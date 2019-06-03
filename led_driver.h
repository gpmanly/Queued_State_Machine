/* 
 * File:   led_driver.h
 * Author: A19356
 *
 * Created on September 5, 2017, 4:34 PM
 */

#ifndef LED_DRIVER_H
#define	LED_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
#include "qsm/qsm_config.h"
#include "qsm/qsm.h"

void led_blink (void);

void led_all_on (void);

void led_running (void);

#ifdef	__cplusplus
}
#endif

#endif	/* LED_DRIVER_H */

