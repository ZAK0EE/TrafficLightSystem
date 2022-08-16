/*
 * interrupt.c
 *
 * Created: 22/08/13 05:39:56 PM
 *  Author: Ziad
 */ 

#ifndef TIMER_H_
#define TIMER_H_

#include "utilities/datatypes.h"
#include <avr/interrupt.h>

// Comment/delete those lines to disable interrupt definition for that timer
// so you can define your own ISR functions without conflicts.
#define ENABLE_TIMER0
#define ENABLE_TIMER1
#define ENABLE_TIMER2

#define TIMER0_PRESCALER_NONE 0
#define TIMER0_PRESCALER_1 1
#define TIMER0_PRESCALER_8 2
#define TIMER0_PRESCALER_64 3
#define TIMER0_PRESCALER_256 4
#define TIMER0_PRESCALER_1024 5

#define TIMER1_PRESCALER_NONE 0
#define TIMER1_PRESCALER_1 1
#define TIMER1_PRESCALER_8 2
#define TIMER1_PRESCALER_64 3
#define TIMER1_PRESCALER_256 4
#define TIMER1_PRESCALER_1024 5

#define TIMER2_PRESCALER_NONE 0
#define TIMER2_PRESCALER_1 1
#define TIMER2_PRESCALER_8 2
#define TIMER2_PRESCALER_32 3
#define TIMER2_PRESCALER_64 4
#define TIMER2_PRESCALER_128 5
#define TIMER2_PRESCALER_256 6
#define TIMER2_PRESCALER_1024 7


/* Use this function to enable timer 0 in interrupt mode
 * prescaler: the prescaler for the CPU frequency
 * ticks : number of ticks
 * callback: call back function that will be called after timer delay is finished
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H timer0(uint8_t prescaler, uint8_t ticks, void (*callback)());

/* Use this function to enable timer 1 in interrupt mode
 * prescaler: the prescaler for the CPU frequency
 * ticks : number of ticks
 * callback: call back function that will be called after timer delay is finished
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H timer1(uint8_t prescaler, uint16_t ticks, void (*callback)());

/* Use this function to enable timer 2 in interrupt mode
 * prescaler: the prescaler for the CPU frequency
 * ticks : number of ticks
 * callback: call back function that will be called after timer delay is finished
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H timer2(uint8_t prescaler, uint8_t ticks, void (*callback)());

/* Use this function to stop timer 0
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H timer0_stop();

/* Use this function to stop timer 0
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H timer1_stop();

/* Use this function to stop timer 0
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H timer2_stop();

/* Use this function to enable timer 0 in CTC mode
 * prescaler: the prescaler for the CPU frequency
 * ticks : number of ticks
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H wait0(uint8_t prescaler, uint8_t ticks);

/* Use this function to enable timer 1 in CTC mode
 * prescaler: the prescaler for the CPU frequency
 * ticks : number of ticks
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H wait1(uint8_t prescaler, uint16_t ticks);

/* Use this function to enable timer 2 in CTC mode
 * prescaler: the prescaler for the CPU frequency
 * ticks : number of ticks
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H wait2(uint8_t prescaler, uint8_t ticks);


#endif /* TIMER_H_ */