/* 
 * File:   motordriver_tb.h
 * Author: A19356
 *
 * Created on August 30, 2017, 10:49 AM
 */

#ifndef MOTORDRIVER_TB_H
#define	MOTORDRIVER_TB_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    
#include "mcc_generated_files/mcc.h"
#include "motordriver.h"
    
    
void motordriver_test();
    bool state = 0;
    bool state2 = 1;
    uint16_t payload;


#ifdef	__cplusplus
}
#endif

#endif	/* MOTORDRIVER_TB_H */

