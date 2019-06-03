/********************************************************************
 * Dependencies:    See INCLUDES section below
 * Processor:       PICxxx
 * Compiler:        XCx
 * Author:          Sherwin Tiongson
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement:
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the "Company") for its PICmicro� Microcontroller is intended and
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
#ifndef QSM_QUEUE_H
#define	QSM_QUEUE_H

typedef enum qsm_queue_resp_e
{
    QSM_QUEUE_OK = 0,
    QSM_QUEUE_EMPTY,
    QSM_QUEUE_FULL,
} qsm_queue_resp_t;
    
#define QSM_QUEUE_SIZE   20
typedef struct qsm_queue_s
{
    uint8_t head;     		
    uint8_t tail;     		
    uint8_t buffer[QSM_QUEUE_SIZE]; 	
    uint8_t buffer_len;     		
    qsm_queue_resp_t status;
} qsm_queue_t;

void qsm_queue_init( qsm_queue_t* b);
void qsm_queue_reset( qsm_queue_t * b);
qsm_queue_resp_t qsm_queue_get( qsm_queue_t * b, uint8_t* byte_out);
qsm_queue_resp_t qsm_queue_put( qsm_queue_t * b, uint8_t data_byte);

#endif	/* QSM_QUEUE_H */
/* end of file */

