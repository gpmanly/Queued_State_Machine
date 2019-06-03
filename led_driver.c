#include "led_driver.h"

void led_blink (void){
    
}

void led_all_on (void){
    LATE = 0x07;
}

void led_running (void){
    //LATE = 0x01;
    LATE = LATE>>1;
}