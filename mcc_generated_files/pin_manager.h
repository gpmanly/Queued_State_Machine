/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26
        Device            :  PIC18F46K80
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_FAULT aliases
#define channel_FAULT_TRIS               TRISAbits.TRISA0
#define channel_FAULT_LAT                LATAbits.LATA0
#define channel_FAULT_PORT               PORTAbits.RA0
#define channel_FAULT_ANS                ANCON0bits.ANSEL0
#define channel_FAULT_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_FAULT_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_FAULT_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_FAULT_GetValue()           PORTAbits.RA0
#define channel_FAULT_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_FAULT_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_FAULT_SetAnalogMode()  do { ANCON0bits.ANSEL0 = 1; } while(0)
#define channel_FAULT_SetDigitalMode() do { ANCON0bits.ANSEL0 = 0; } while(0)

// get/set channel_LOAD aliases
#define channel_LOAD_TRIS               TRISAbits.TRISA1
#define channel_LOAD_LAT                LATAbits.LATA1
#define channel_LOAD_PORT               PORTAbits.RA1
#define channel_LOAD_ANS                ANCON0bits.ANSEL1
#define channel_LOAD_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define channel_LOAD_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define channel_LOAD_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define channel_LOAD_GetValue()           PORTAbits.RA1
#define channel_LOAD_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define channel_LOAD_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define channel_LOAD_SetAnalogMode()  do { ANCON0bits.ANSEL1 = 1; } while(0)
#define channel_LOAD_SetDigitalMode() do { ANCON0bits.ANSEL1 = 0; } while(0)

// get/set channel_WATER aliases
#define channel_WATER_TRIS               TRISAbits.TRISA2
#define channel_WATER_LAT                LATAbits.LATA2
#define channel_WATER_PORT               PORTAbits.RA2
#define channel_WATER_ANS                ANCON0bits.ANSEL2
#define channel_WATER_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define channel_WATER_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define channel_WATER_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define channel_WATER_GetValue()           PORTAbits.RA2
#define channel_WATER_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define channel_WATER_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define channel_WATER_SetAnalogMode()  do { ANCON0bits.ANSEL2 = 1; } while(0)
#define channel_WATER_SetDigitalMode() do { ANCON0bits.ANSEL2 = 0; } while(0)

// get/set RA6 procedures
#define RA6_SetHigh()    do { LATAbits.LATA6 = 1; } while(0)
#define RA6_SetLow()   do { LATAbits.LATA6 = 0; } while(0)
#define RA6_Toggle()   do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define RA6_GetValue()         PORTAbits.RA6
#define RA6_SetDigitalInput()   do { TRISAbits.TRISA6 = 1; } while(0)
#define RA6_SetDigitalOutput()  do { TRISAbits.TRISA6 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()    do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()   do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()   do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()         PORTBbits.RB0
#define RB0_SetDigitalInput()   do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()  do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()     do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()   do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode() do { ANCON1bits.ANSEL10 = 1; } while(0)
#define RB0_SetDigitalMode()do { ANCON1bits.ANSEL10 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()    do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()   do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()   do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()         PORTBbits.RB1
#define RB1_SetDigitalInput()   do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()  do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()     do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()   do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode() do { ANCON1bits.ANSEL8 = 1; } while(0)
#define RB1_SetDigitalMode()do { ANCON1bits.ANSEL8 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()    do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()   do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()   do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()         PORTBbits.RB5
#define RB5_SetDigitalInput()   do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()  do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()     do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()   do { WPUBbits.WPUB5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()    do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()   do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()   do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()         PORTCbits.RC6
#define RC6_SetDigitalInput()   do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()  do { TRISCbits.TRISC6 = 0; } while(0)

// get/set RD4 procedures
#define RD4_SetHigh()    do { LATDbits.LATD4 = 1; } while(0)
#define RD4_SetLow()   do { LATDbits.LATD4 = 0; } while(0)
#define RD4_Toggle()   do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define RD4_GetValue()         PORTDbits.RD4
#define RD4_SetDigitalInput()   do { TRISDbits.TRISD4 = 1; } while(0)
#define RD4_SetDigitalOutput()  do { TRISDbits.TRISD4 = 0; } while(0)

// get/set RD5 procedures
#define RD5_SetHigh()    do { LATDbits.LATD5 = 1; } while(0)
#define RD5_SetLow()   do { LATDbits.LATD5 = 0; } while(0)
#define RD5_Toggle()   do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define RD5_GetValue()         PORTDbits.RD5
#define RD5_SetDigitalInput()   do { TRISDbits.TRISD5 = 1; } while(0)
#define RD5_SetDigitalOutput()  do { TRISDbits.TRISD5 = 0; } while(0)

// get/set RD6 procedures
#define RD6_SetHigh()    do { LATDbits.LATD6 = 1; } while(0)
#define RD6_SetLow()   do { LATDbits.LATD6 = 0; } while(0)
#define RD6_Toggle()   do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define RD6_GetValue()         PORTDbits.RD6
#define RD6_SetDigitalInput()   do { TRISDbits.TRISD6 = 1; } while(0)
#define RD6_SetDigitalOutput()  do { TRISDbits.TRISD6 = 0; } while(0)

// get/set RD7 procedures
#define RD7_SetHigh()    do { LATDbits.LATD7 = 1; } while(0)
#define RD7_SetLow()   do { LATDbits.LATD7 = 0; } while(0)
#define RD7_Toggle()   do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define RD7_GetValue()         PORTDbits.RD7
#define RD7_SetDigitalInput()   do { TRISDbits.TRISD7 = 1; } while(0)
#define RD7_SetDigitalOutput()  do { TRISDbits.TRISD7 = 0; } while(0)

// get/set LED_D0 aliases
#define LED_D0_TRIS               TRISEbits.TRISE0
#define LED_D0_LAT                LATEbits.LATE0
#define LED_D0_PORT               PORTEbits.RE0
#define LED_D0_ANS                ANCON0bits.ANSEL5
#define LED_D0_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define LED_D0_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define LED_D0_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define LED_D0_GetValue()           PORTEbits.RE0
#define LED_D0_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define LED_D0_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define LED_D0_SetAnalogMode()  do { ANCON0bits.ANSEL5 = 1; } while(0)
#define LED_D0_SetDigitalMode() do { ANCON0bits.ANSEL5 = 0; } while(0)

// get/set LED_D1 aliases
#define LED_D1_TRIS               TRISEbits.TRISE1
#define LED_D1_LAT                LATEbits.LATE1
#define LED_D1_PORT               PORTEbits.RE1
#define LED_D1_ANS                ANCON0bits.ANSEL6
#define LED_D1_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define LED_D1_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define LED_D1_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define LED_D1_GetValue()           PORTEbits.RE1
#define LED_D1_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define LED_D1_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define LED_D1_SetAnalogMode()  do { ANCON0bits.ANSEL6 = 1; } while(0)
#define LED_D1_SetDigitalMode() do { ANCON0bits.ANSEL6 = 0; } while(0)

// get/set LED_D2 aliases
#define LED_D2_TRIS               TRISEbits.TRISE2
#define LED_D2_LAT                LATEbits.LATE2
#define LED_D2_PORT               PORTEbits.RE2
#define LED_D2_ANS                ANCON0bits.ANSEL7
#define LED_D2_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define LED_D2_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define LED_D2_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define LED_D2_GetValue()           PORTEbits.RE2
#define LED_D2_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define LED_D2_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define LED_D2_SetAnalogMode()  do { ANCON0bits.ANSEL7 = 1; } while(0)
#define LED_D2_SetDigitalMode() do { ANCON0bits.ANSEL7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/