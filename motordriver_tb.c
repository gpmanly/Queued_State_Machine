
#include "motordriver_tb.h"

void motordriver_test(){
    EPWM1_LoadDutyValue(300);
    run_time(1);
    motor_forward_duration(9);
    while(1){
//        while(get_out()==0){
//            motor_forward_duration(9);
//            motor_off_duration(2);
//            motor_reverse_duration(9);
//        }
//        while(1){
//            motor_off();
//        }
    }
    
//    while (1)
//    {
//        
//        switch(state){
//            case 1: motor_forward(); break;
//            case 0: motor_reverse(); break;
//        }
//        switch(state2){
//            case 1: motor_off(); break;
//            case 0: motor_on(); break;
//        }        
//        motor_ADC_DC(channel_FAULT);
//        payload = ADC_GetConversionResult();
//        
//        printf("%u \n", payload);   
//    }
}

