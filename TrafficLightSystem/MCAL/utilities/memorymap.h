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




#endif /* MEMORYMAP_H_ */