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
#include <stdio.h>
#include "qsm_config.h"
#include "qsm_event_handler.h"
#include "qsm.h"
#include "../mcc_generated_files/mcc.h"
#include "../motordriver.h"
#include "../led_driver.h"


void WM_HANDLER_INIT(void){
    printf("WM_HANDLER_INIT \n\r");
    ADCON0bits.CHS = channel_FAULT;
    led_all_on();
    TMR3_StopTimer();
    TMR0_StopTimer();
    set_count_s(0);
    set_count_m(0);
    qsm_set_state ( WM_STATE_IDLE );           
}


void WM_HANDLER_NONE(void){
    printf("WM_HANDLER_NONE \n\r");
}



void WM_HANDLER_FAULT_SENSE(void){
    printf("WM_HANDLER_FAULT_SENSE \n\r");
    TMR0_StopTimer();
    motor_off();
    LATE = 0X00;
    qsm_set_state(WM_STATE_FAULT);
}
void WM_HANDLER_TIMER_DONE(void){
    printf("WM_HANDLER_TIMER_DONE \n\r");
    motor_off();
    LATE = 0X00;
    set_out(0);
    qsm_set_state(WM_STATE_DONE);
}





void WM_HANDLER_TOGGLE_MODE(void){
    printf("WM_HANDLER_TOGGLE_MODE \n\r");
    switch(qsm_get_state()){
        case WM_STATE_MODE_WASH:    printf("MODE_DRAIN \n\r");
                                    set_mode(FLAG_DRAIN);
                                    qsm_set_state(WM_STATE_MODE_DRAIN);
                                    break;
        case WM_STATE_MODE_DRAIN:   printf("MODE_WASH \n\r");
                                    set_mode(FLAG_WASH);
                                    qsm_set_state(WM_STATE_MODE_WASH);
                                    break;
        case WM_STATE_IDLE:         printf("MODE_WASH \n\r");
                                    set_mode(FLAG_WASH);
                                    qsm_set_state(WM_STATE_MODE_WASH);
                                    break;
    }
}

void WM_HANDLER_START_WEIGHING(void){
    printf("WM_HANDLER_START_WEIGHING \n\r");
    ADCON0bits.CHS = channel_LOAD;
    
    uint16_t weight = ADC_GetConversionResult();
    if(weight < 1365){
        printf("LIGHT WEIGHT \n\r");
        set_weight_flag(FLAG_LIGHT);
        qsm_set_state(WM_STATE_MODE_LIGHT);
    }
    else if(weight >= 1365 && weight < 2730){
        printf("NORMAL WEIGHT \n\r");
        set_weight_flag(FLAG_NORMAL);
        qsm_set_state(WM_STATE_MODE_NORMAL);
    }
    else if (weight >= 2730){
        printf("HEAVY WEIGHT \n\r");
        set_weight_flag(FLAG_HEAVY);
        qsm_set_state(WM_STATE_MODE_HEAVY);
    }
    
}



void WM_HANDLER_LOAD_SENSE(void){
    printf("WM_HANDLER_LOAD_SENSE \n\r");
    ADCON0bits.CHS = channel_LOAD;
    
    uint16_t weight = ADC_GetConversionResult();
    if(weight < 1365){
        printf("LIGHT \n\r");
        set_weight_flag(FLAG_LIGHT);
        qsm_set_state(WM_STATE_MODE_LIGHT);
    }
    else if(weight >= 1365 && weight < 2730){
        printf("NORMAL \n\r");
        set_weight_flag(FLAG_NORMAL);
        qsm_set_state(WM_STATE_MODE_NORMAL);
    }
    else if (weight >= 2730){
        printf("HEAVY \n\r");
        set_weight_flag(FLAG_HEAVY);
        qsm_set_state(WM_STATE_MODE_HEAVY);
    }
}

void WM_HANDLER_START_RUNNING(void){
    printf("WM_HANDLER_START_RUNNING \n\r");
    ADCON0bits.CHS = channel_FAULT;
    motor_run();
}

void WM_HANDLER_WATER_LEVEL_SENSE(void){
    printf("WM_HANDLER_WATER_LEVEL_SENSE \n\r");
    qsm_set_state(WM_STATE_DONE);
}



/* end of file */
