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
#include <string.h>
#include "qsm_queue.h"

/*!
 * @name  qsm_queue_count().
 * @brief Returns the number of elements in the buffer.
 */
static uint8_t qsm_queue_count ( qsm_queue_t const *b)
{
    return (b ? (b->head - b->tail) : 0);
}

/*!
 * @name  qsm_queue_isfull().
 * @brief Returns true if the buffer is full, false if it is not.
 */
static bool qsm_queue_isfull ( qsm_queue_t const *b)
{
    return (b ? (qsm_queue_count(b) == b->buffer_len) : true);
}

/*!
 * @name  qsm_queue_isempty().
 * @brief Returns true if the buffer is empty, false if it is not.
 */
static bool qsm_queue_isempty( qsm_queue_t const *b)
{
    return (b ? (qsm_queue_count(b) == 0) : true);
}

/*!
 * @name  qsm_queue_get().
 * @brief Returns the data at the front of the list, and removes it
 */
qsm_queue_resp_t qsm_queue_get( qsm_queue_t* b, uint8_t* byte_out)
{
    if (!qsm_queue_isempty(b)) 
    {
        *byte_out = b->buffer[b->tail % b->buffer_len];
        b->tail++;
        b->status = QSM_QUEUE_OK;
    } 
    else 
    {
    	b->status = QSM_QUEUE_EMPTY;
    }
    return  b->status;
}

/*!
 * @name  qsm_queue_put().
 * @brief ...... 
 */
qsm_queue_resp_t qsm_queue_put( qsm_queue_t* b, uint8_t data_byte)
{
    if (b)
    {
        if (!qsm_queue_isfull(b))
        {
                b->buffer[b->head % b->buffer_len] = data_byte;
                b->head++;
                b->status = QSM_QUEUE_OK;
        } else
        {
                b->status = QSM_QUEUE_FULL;
        }
    }
    return b->status;
}

/*!
 * @name  qsm_queue_reset().
 * 
 */
void qsm_queue_reset( qsm_queue_t * b)
{
    if (b) 
    {
        b->head = 0;
        b->tail = 0;
        b->status = QSM_QUEUE_OK;
    }
    return;
}

/*!
 * @name  qsm_queue_init().
 * @brief Configures the queue buffer.
 */
void qsm_queue_init( qsm_queue_t* b )
{
    if (b) 
    {
        b->head = 0;
        b->tail = 0;
        b->buffer_len = QSM_QUEUE_SIZE;
        b->status = QSM_QUEUE_OK;
        memset((void*) b->buffer, 0x00, QSM_QUEUE_SIZE);
    }
    return;
}

/*!
 * @name  qsm_queue_get_status().
 */
static qsm_queue_resp_t qsm_queue_get_status( qsm_queue_t const *b )
{
    return b->status;
}
/* end of file */