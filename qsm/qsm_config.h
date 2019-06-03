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

#ifndef QSM_CONFIG_H
#define	QSM_CONFIG_H

#ifdef	__cplusplus
extern "C" {
   
#endif

/*GP defined flag*/
typedef enum {
    FLAG_WASH,
    FLAG_DRAIN        
}mode_operation_t;

typedef enum {
    FLAG_LIGHT,
    FLAG_NORMAL,
    FLAG_HEAVY
}weight_flag_t;
    
    
    
//DEFINE ALL THE STATES HERE
typedef enum huvent_state_e
{
    WM_STATE_IDLE = 0,
            
            WM_STATE_MODE_WASH,
            
            WM_STATE_MODE_DRAIN,
            
            WM_STATE_WEIGHING,
            
            WM_STATE_MODE_LIGHT,
            
            WM_STATE_MODE_NORMAL,
            
            WM_STATE_MODE_HEAVY,

    WM_STATE_WASHING,

    WM_STATE_DRAINING,
            
    WM_STATE_FAULT,
            
    WM_STATE_DONE,

    /* DO NOT RENAME THIS STATE!! */
    QSM_STATE_MAX

} qsm_state_t;

//DEFINE ALL THE EVENTS HERE
typedef enum huvent_e
{
    WM_EVENT_INIT = 0,

    WM_EVENT_BUTTON_OK,

    WM_EVENT_BUTTON_UP,
            
            WM_EVENT_LOAD_SENSE,
            
            WM_EVENT_WATER_LEVEL_SENSE,

    WM_EVENT_FAULT_SENSE,
            
    WM_EVENT_TIMER_DONE,

    /* DO NOT RENAME THIS EVENT!! */
    QSM_EVENT_MAX
} qsm_event_t;    

#define     QSM_INITIAL_STATE           WM_STATE_IDLE    
#define     QSM_PRINT_STATE_EVENT       0
#define     QSM_CATCH_HARD_ERROR        1  

#ifdef	__cplusplus
}
#endif

#endif	/* QSM_CONFIG_H */

