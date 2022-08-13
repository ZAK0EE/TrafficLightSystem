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


#define INT_FALLING 0
#define INT_RISING 1

/* Function Prototypes */
/* Using this function to enable Interrupt 1
 * INPUT : uint8_t --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H Enable_INT0(uint8_t INT_STATE);
ERROR_H Disable_INT0 ();
/* Using this function to enable Interrupt 1
 * INPUT : uint8_t --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H Enable_INT1(uint8_t INT_STATE);
ERROR_H Disable_INT2 ();
/* Using this function to enable Interrupt 1
 * INPUT : uint8_t --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H Enable_INT2(uint8_t INT_STATE);
ERROR_H Disable_INT2 ();


#endif /* INTERRUPT_H_ */