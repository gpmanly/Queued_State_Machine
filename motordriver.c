#include "motordriver.h"


void motor_forward (void){
    P1M1 = 1;
}

void motor_reverse (void) {
    P1M1 = 0;
}

void motor_off (void){
    CCP1CONbits.CCP1M = 0B0000;
}

void motor_on (void) {
    CCP1CONbits.CCP1M = 0B1100;
}

//void motor_ADC_DC (adc_channel_t channel_source) {
//    EPWM1_LoadDutyValue(ADC_GetConversion(channel_source)*SCALER);
//}

void motor_forward_duration (uint8_t duration_s) {
    TMR3_StartTimer();
    motor_forward();
    motor_on();
    while(get_count_s() < duration_s){
        #if PRINT_COUNT_UP
            printf("Count up: %d \n",get_count_s());
        #endif
        if(get_out())break;
    }
    TMR3_StopTimer();
    TMR3_Reload();
    set_count_s(0);
    motor_off();
}

void motor_reverse_duration (uint8_t duration_s) {
    TMR3_StartTimer();
    motor_reverse();
    motor_on();
    while(get_count_s() < duration_s){
        #if PRINT_COUNT_UP
            printf("Count up: %d \n",get_count_s());
        #endif
        if(get_out())break;
    }
    TMR3_StopTimer();
    set_count_s(0);
    motor_off();
}

void motor_off_duration (uint8_t duration_s) {
    TMR3_StartTimer();
    motor_off();
    while(get_count_s() < duration_s){
        #if PRINT_COUNT_UP
            printf("Count up: %d \n",get_count_s());
        #endif
        if(get_out())break;
    }
    TMR3_StopTimer();
    TMR3_Reload();
    set_count_s(0);
}

void run_time (uint8_t duration_m){
    set_duration_m(duration_m);
    TMR0_StartTimer();    
}

void motor_run (){
    switch (get_weight_flag()){
        case FLAG_LIGHT:
            switch (get_mode()){
                case FLAG_WASH:     //1min (9s FW, 2s OFF, 9s REV)
                                    qsm_set_state(WM_STATE_WASHING);
                                    printf("LIGHT WASHING \n");
                                    run_time(1);
                                    while(!get_out()){
                                        motor_forward_duration(9);
                                        motor_off_duration(2);
                                        motor_reverse_duration(9);
                                    }
                    break;
                case FLAG_DRAIN:    //1min ON FW
                                    qsm_set_state(WM_STATE_DRAINING);
                                    printf("LIGHT DRAINING \n");
                                    run_time(1);
                                    while(!get_out()){
                                        motor_forward_duration(60);
                                    }
                    break;
            }
        case FLAG_NORMAL:
            switch (get_mode()){    
                case FLAG_WASH:     //2min (9s FW, 2s OFF, 9s REV)
                                    qsm_set_state(WM_STATE_WASHING);
                                    printf("NORMAL WASHING \n");
                                    run_time(2);
                                    while(!get_out()){
                                        motor_forward_duration(9);
                                        motor_off_duration(2);
                                        motor_reverse_duration(9);
                                    }
                    break;
                case FLAG_DRAIN:    //2min ON FW
                                    qsm_set_state(WM_STATE_DRAINING);
                                    printf("NORMAL DRAINING \n");
                                    run_time(2);
                                    while(!get_out()){
                                        motor_forward_duration(60);
                                    }
                    break;
            }
        case FLAG_HEAVY:
            switch (get_mode()){
                case FLAG_WASH:     //3min (9s FW, 2s OFF, 9s REV)
                                    qsm_set_state(WM_STATE_WASHING);
                                    printf("HEAVY WASHING \n");
                                    run_time(3);
                                    while(!get_out()){
                                        motor_forward_duration(9);
                                        motor_off_duration(2);
                                        motor_reverse_duration(9);
                                    }
                    break;
                case FLAG_DRAIN:    //3min ON FW
                                    qsm_set_state(WM_STATE_DRAINING);
                                    printf("HEAVY DRAINING \n");
                                    run_time(3);
                                    while(!get_out()){
                                        motor_forward_duration(60);
                                    }
                    break;
            }
            
    }
}