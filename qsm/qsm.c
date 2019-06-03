/********************************************************************
 * Dependencies:    See INCLUDES section below
 * Processor:       PICxxxx
 * Compiler:        XCxx
 * Board:           ---
 * Author:          Sherwin Tiongson
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement:
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the "Company") for its PICmicro? Microcontroller is intended and
 * supplied to you, the Company's customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *********************************************************************
 ********************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "qsm_config.h"
#include "qsm_queue.h"
#include "qsm.h"
#include "qsm_event_handler.h"

static qsm_state_t qsm_state = QSM_INITIAL_STATE;
static qsm_queue_t qsm_queue;

/*USER DEFINED*/
static mode_operation_t mode = FLAG_WASH;
static weight_flag_t weight_flag = FLAG_LIGHT;


typedef struct qsm_lookup_table_e
{    
    qsm_event_t event;
    
    /* An array of function pointers. Each element is a function pointer 
     * to the event handler. The array is index by the State 
     */
    void (*event_handler[QSM_STATE_MAX]) ();
} qsm_lookup_table_t;

/* EVENT HANDLERS */
#define 	WMHA_INIT       WM_HANDLER_INIT
#define 	WMHA_NONE       WM_HANDLER_NONE
#define 	WMHA_STRN       WM_HANDLER_START_RUNNING
#define 	WMHA_FULT       WM_HANDLER_FAULT_SENSE
#define 	WMHA_TMDN       WM_HANDLER_TIMER_DONE

#define     WMHA_TOGL       WM_HANDLER_TOGGLE_MODE
#define     WMHA_STWE       WM_HANDLER_START_WEIGHING
#define     WMHA_LOAD       WM_HANDLER_LOAD_SENSE
#define     WMHA_H2OS       WM_HANDLER_WATER_LEVEL_SENSE

 
/* 
 *  EVENT, STATE and EVENT_HANDLER Look-up Table.
 *  
 *  The EVENTS are the row numbers and the STATES are the
 *  column numbers. Each element on the table is the
 *  function pointer to the EVENT_HANDLER function.
 */
const qsm_lookup_table_t qsm_lookup_table [] =
{
/*====================================================================================================================================================================================================================================*/
/*                                IDLE	          MODE WASH         MODE DRAIN      WEIGHING        MODE_LIGHT          MODE_NORMAL         MODE_HEAVY           WASHING             DRAINING            FAULT               DONE  */
/*====================================================================================================================================================================================================================================*/    
    /*  EVENTS */
    {WM_EVENT_INIT,             {WMHA_INIT,       WMHA_NONE,         WMHA_NONE,    WMHA_NONE,       WMHA_NONE,          WMHA_NONE,          WMHA_NONE,          WMHA_NONE,          WMHA_NONE,          WMHA_NONE,          WMHA_NONE} },
    {WM_EVENT_BUTTON_OK,        {WMHA_NONE,       WMHA_STWE,         WMHA_STWE,    WMHA_NONE,       WMHA_STRN,          WMHA_STRN,          WMHA_STRN,          WMHA_NONE,          WMHA_NONE,          WMHA_STRN,          WMHA_INIT} },
    {WM_EVENT_BUTTON_UP,        {WMHA_TOGL,       WMHA_TOGL,         WMHA_TOGL,    WMHA_NONE,       WMHA_NONE,          WMHA_NONE,          WMHA_NONE,          WMHA_NONE,          WMHA_NONE,          WMHA_NONE,          WMHA_NONE} },
    {WM_EVENT_LOAD_SENSE,	    {WMHA_NONE,       WMHA_NONE,         WMHA_NONE,    WMHA_LOAD,       WMHA_LOAD,          WMHA_LOAD,          WMHA_LOAD,          WMHA_NONE,          WMHA_NONE,          WMHA_NONE,          WMHA_NONE} },
    {WM_EVENT_WATER_LEVEL_SENSE,{WMHA_NONE,       WMHA_NONE,         WMHA_NONE,    WMHA_NONE,       WMHA_NONE,          WMHA_NONE,          WMHA_NONE,          WMHA_NONE,          WMHA_H2OS,          WMHA_NONE,          WMHA_NONE} },
    {WM_EVENT_FAULT_SENSE,	    {WMHA_NONE,       WMHA_NONE,         WMHA_NONE,    WMHA_NONE,       WMHA_NONE,          WMHA_NONE,          WMHA_NONE,          WMHA_FULT,          WMHA_FULT,          WMHA_FULT,          WMHA_NONE} },
    {WM_EVENT_TIMER_DONE,	    {WMHA_NONE,       WMHA_NONE,         WMHA_NONE,    WMHA_NONE,       WMHA_NONE,          WMHA_NONE,          WMHA_NONE,          WMHA_TMDN,          WMHA_TMDN,          WMHA_NONE,          WMHA_NONE} }
};

void qsm_init(void)
{
    qsm_queue_init( &qsm_queue );
    qsm_queue_reset( &qsm_queue );
    qsm_state = QSM_INITIAL_STATE;
}

qsm_resp_t qsm_post_event( qsm_event_t event)
{
    if( QSM_QUEUE_OK != qsm_queue_put( &qsm_queue, event ) )
    {
        return QSM_FULL;
    }
    return QSM_OK;
}

qsm_state_t qsm_get_state( void )
{
       return qsm_state;
}

void qsm_set_state( qsm_state_t new_state )
{
    qsm_state = new_state;
    return;   
}

/*!
 * @name  qsm_engine().
 * @brief Call this function in your main loop.
 */
void qsm_engine(void)
{
    qsm_event_t event = QSM_INITIAL_STATE;
    qsm_queue_resp_t resp = QSM_QUEUE_OK;
    
    resp = qsm_queue_get( &qsm_queue, (uint8_t*) &event);
    
#if QSM_PRINT_STATE_EVENT
    printf(" event = %d \n\r", event );
    printf(" state = %d \n\r" , qsm_state );
#endif

    switch(resp)
    {
        case QSM_QUEUE_OK:
        {
            qsm_lookup_table[event].event_handler[qsm_state]();  
            break;
        }
        case QSM_QUEUE_EMPTY:
        {
            /* nothing to do when event queue is empty */
            break;
        }
        case QSM_QUEUE_FULL:
        default:
        {
            while(QSM_CATCH_HARD_ERROR);
            break;
        }
    }
}

/*GP DEFINED FUNCTION*/
mode_operation_t get_mode (void){
    return mode;
}

void set_mode (mode_operation_t new_mode){
    mode = new_mode;
    return;
}

weight_flag_t get_weight_flag (void){
    return weight_flag;
}

void set_weight_flag (weight_flag_t new_weight_flag){
    weight_flag = new_weight_flag;
    return;
}
/* end of file */