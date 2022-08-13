/*
 * memorymap.h
 *
 * Created: 22/08/11 06:25:30 PM
 * ATmega32 Memory map
 *  Author: Ziad
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_


#include "datatypes.h"

/************************************************************************/
/* DIO Registers                                                        */
/************************************************************************/

// PORTA registers
#define PORTA (*(volatile uint8_t*) 0x3B) //8bit register
#define DDRA (*(volatile uint8_t*) 0x3A)	//8bit register
#define PINA (*(volatile uint8_t*) 0x39)	//8bit register

// PORTB registers
#define PORTB (*(volatile uint8_t*) 0x38)	//8bit register
#define DDRB (*(volatile uint8_t*) 0x37)	//8bit register
#define PINB (*(volatile uint8_t*) 0x36)	//8bit register

// PORTC registers
#define PORTC (*(volatile uint8_t*) 0x35)	//8bit register
#define DDRC (*(volatile uint8_t*) 0x34)	//8bit register
#define PINC (*(volatile uint8_t*) 0x33)	//8bit register

#define PORTD (*(volatile uint8_t*) 0x32)	//8bit register
#define DDRD (*(volatile uint8_t*) 0x31)	//8bit register
#define PIND (*(volatile uint8_t*) 0x30)	//8bit register

/************************************************************************/
/*	TIMERS Registers                                                    */
/************************************************************************/

//Timer 0 - 8 bit timer
#define TCCR0 (*(volatile unsigned char*)0x53)
#define TCNT0 (*(volatile unsigned char*)0x52)
#define OCR0 (*(volatile unsigned char*)0x5C)

//Timer 1 - 16 bit timer
#define TCCR1A (*(volatile unsigned char*)0x4F)
#define TCCR1B (*(volatile unsigned char*)0x4E)
#define TCNT1H (*(volatile unsigned char*)0x4D)
#define TCNT1L (*(volatile unsigned char*)0x4C)
#define OCR1AH (*(volatile unsigned char*)0x4B)
#define OCR1AL (*(volatile unsigned char*)0x4A)
#define OCR1BH (*(volatile unsigned char*)0x49)
#define OCR1BL (*(volatile unsigned char*)0x48)
#define ICR1H (*(volatile unsigned char*)0x47)
#define ICR1L (*(volatile unsigned char*)0x46)

//Timer 2 - 8 bit timer
#define TCCR2 (*(volatile unsigned char*)0x45)
#define TCNT2 (*(volatile unsigned char*)0x44)
#define OCR2 (*(volatile unsigned char*)0x43)

#define TIMSK (*(volatile unsigned char*)0x59)
#define TIFR (*(volatile unsigned char*)0x58)


/************************************************************************/
/* Interrupts  Registers                                                */
/************************************************************************/
#define SREG (*(volatile unsigned char*)0x5F)
#define GICR (*(volatile unsigned char*)0x5B)
#define GIFR (*(volatile unsigned char*)0x5A)
#define MCUCR (*(volatile unsigned char*)0x55)
#define MCUCSR (*(volatile unsigned char*)0x54)

/************************************************************************/
/* Interrupt Vector                                                     */
/************************************************************************/

/* External Interrupt Vector */
/* External Interrupt Request 0 */
#define EXT_INT_0 __vector_1
/* External Interrupt Request 1 */
#define EXT_INT_1 __vector_2
/* External Interrupt Request 2 */
#define EXT_INT_2 __vector_3

/* Timer Interrupt Vector */

/*Timer 2*/
/* Timer/Counter2 Compare Match */
#define TIMER2_COMP __vector_4
/* Timer/Counter2 Overflow */
#define TIMER2_OVF __vector_5

/*Timer 1*/
/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT __vector_6
/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA __vector_7
/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB __vector_8
/* Timer/Counter1 Overflow */
#define TIMER1_OVF __vector_9

/*Timer 0*/
/* Timer/Counter0 Compare Match */
#define TIMER0_COMP __vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF __vector_11

/* Set Global Interrupt, Set the I-bit in status register to 1 */
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

/* Clear Global Interrupt, Set the I-bit in status register to 0 */
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

/* ISR definition */
#define ISR(INT_VECT) void INT_VECT(void) __attribute__((signal,used)); void INT_VECT(void)

/* Interrupt Bits */
/* GICR bits */
#define INT1 7
#define INT0 6
#define INT2 5

/* GIFR bits */
#define INTF1 7
#define INTF0 6
#define INTF2 5

/* MCUCR bits */
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

/* MCUCSR bits */
#define ISC2 7

/* Interrupt PORT - Pins */
/* Interrupt 0 */
#define INT0_PORT PORT_D
#define INT0_PIN 2
/* Interrupt 1 */
#define INT1_PORT PORT_D
#define INT1_PIN 3
/* Interrupt 2 */
#define INT2_PORT PORT_B
#define INT2_PIN 2




#endif /* MEMORYMAP_H_ */