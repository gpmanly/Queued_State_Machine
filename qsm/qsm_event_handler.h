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

#ifndef QSM_EVENT_HANDLER_H
#define	QSM_EVENT_HANDLER_H

void WM_HANDLER_INIT(void);
void WM_HANDLER_NONE(void);
void WM_HANDLER_TOGGLE_MODE(void);
void WM_HANDLER_START_WEIGHING(void);
void WM_HANDLER_LOAD_SENSE(void);
void WM_HANDLER_WATER_LEVEL_SENSE(void);
void WM_HANDLER_FAULT_SENSE(void);
void WM_HANDLER_TIMER_DONE(void);


void WM_HANDLER_START_RUNNING(void);

#endif	/* QSM_EVENT_HANDLER_H */
/* end of file */

