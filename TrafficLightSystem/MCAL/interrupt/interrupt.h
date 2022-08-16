/*
 * interrupt.h
 *
 * Created: 22/08/13 10:40:10 PM
 *  Author: Ziad
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "utilities/memorymap.h"
#include "utilities/bit_manipulation.h"
#include "utilities/datatypes.h"

// Comment/delete those lines to disable interrupt definition for that interrupt
// so you can define your own ISR functions without conflicts.
#define ENABLE_INT0
#define ENABLE_INT1
#define ENABLE_INT2

#define INT_FALLING 0
#define INT_RISING 1

/* Function Prototypes */
/* Using this function to enable Interrupt 0
 * INPUT : uint8_t --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H Enable_INT0 (uint8_t INT_STATE, void (*callback)());

/* Using this function to disable Interrupt 0
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H Disable_INT0 ();

/* Using this function to enable Interrupt 1
 * INPUT : uint8_t --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H Enable_INT1 (uint8_t INT_STATE, void (*callback)());

/* Using this function to disable Interrupt 1
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H Disable_INT1();

/* Using this function to enable Interrupt 2
 * INPUT : uint8_t --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H Enable_INT2 (uint8_t INT_STATE, void (*callback)());

/* Using this function to enable Interrupt 2
 * INPUT : uint8_t --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H Disable_INT2 ();


#endif /* INTERRUPT_H_ */