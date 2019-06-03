/* 
 * File:   motordriver.h
 * Author: A19356
 *
 * Created on August 30, 2017, 10:41 AM
 */

#ifndef MOTORDRIVER_H
#define	MOTORDRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif
 
#include "mcc_generated_files/mcc.h"
#include "qsm/qsm_config.h"
#include "qsm/qsm.h"
    
#define SCALER 0.1
#define PRINT_COUNT_UP 1
    
void motor_forward (void);
void motor_reverse (void);
void motor_off (void);
void motor_on (void); 
void motor_run(void);
void motor_forward_duration (uint8_t duration_s);
void motor_reverse_duration (uint8_t duration_s);
void motor_off_duration (uint8_t duration_s);
void run_time (uint8_t duration_m);


//void motor_ADC_DC (adc_channel_t channel_source);

//typedef enum {
//            LIGHT,
//            NORMAL,
//            HEAVY
//}weight_t;
//
//typedef enum {
//            WASH,
//            DRAIN
//}mode_t;


#ifdef	__cplusplus
}
#endif

#endif	/* MOTORDRIVER_H */

