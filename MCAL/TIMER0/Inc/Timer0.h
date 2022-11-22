/*
 * Timer0.h
 *
 * Created: 11/11/2022 10:01:03 PM
 *  Author: Ahmed.Elsayed
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "avr/io.h"
#include "../../../Common/STD_Types.h"
#include "../../../Common/Bit_Op.h"

#define NUMBER_OF_OVERFLOWS_TIM0_1SEC 1000
#define NUMBER_OF_OVERFLOWS_TIM0_5SEC 5000

#define TCCR0  *((volatile uint8*)0x53)
#define TCNT0  *((volatile uint8*)0x52)
#define TIFR  *((volatile uint8*)0x52)
#define TIMSK  *((volatile uint8*)0x59)
#define OCR0   *((volatile uint8*)0x5C)
#define SREG   *((volatile uint8*)0x5F)

/* SREG Register */
#define I  7
/* TCCR0 Register */
#define WGM00 6
#define WGM01 3

#define CS02  2
#define CS01  1
#define CS00  0

#define COM00 4
#define COM01 5

/* TIMSK Register */
#define TOIE0 0
#define OCIE0 1
/*TMR0 Modes:
 * 0: Normal OverFlow Mode
 * 1: CTC Mode
 * 2: Fast PWM
 * 3: PhaseCorrect Mode*/

#define TMR0_MODULE_MODE  0

/* 0: Non-Inverted
 * 1: Inverted*/
#define TMR0_PWM_INVRTED  0

/*
 * 0: Interrupt on Over Flow is disabled
 * 1: Interrupt on over flow is enabled*/
#define TMR0_OVF_ENABLED  0

/*
 * 0: Interrupt on Compare is disabled
 * 1: Interrupt on Compare is enabled*/
#define TMR0_OCR_ENABLED  0

void TMR0_vidInit(void);
void TMR0_vidStartTimer(uint16 preScalar);
void TMR0_vidStopTimer(void);
void TMR0_vidWaitOverflowFlagTimer(void);
uint8 TMR0_u8GetTimer(void);
void TMR0_vidSetTimer(uint8 Value);
void TMR0_vidSetCompareValue(uint8 Value);


#endif /* TIMER0_H_ */