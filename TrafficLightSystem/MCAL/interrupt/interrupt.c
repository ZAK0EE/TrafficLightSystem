/*
 * interrupt.c
 *
 * Created: 22/08/13 10:39:56 PM
 *  Author: Ziad
 */ 

#include "interrupt.h"

void (*_int0_func)();
void (*_int1_func)();
void (*_int2_func)();


ERROR_H Enable_INT0 (uint8_t INT_STATE, void (*f)())
{
	sei(); /* Enable global interrupt */
	_int0_func = f; /* Set the callback function to f*/
	GICR |= (1<< INT0); /* Enable INT0*/
	if(INT_STATE == INT_FALLING)
	{
		MCUCR |= (1<< ISC01); /* Trigger INT0 on FALLING edge */
	}
	else if(INT_STATE == INT_RISING)
	{
		MCUCR |= (1<< ISC01) | (1<< ISC00); /* Trigger INT0 on RISING edge */
	}
	else
	{
		return ERROR;
	}

	return OK;
}

ERROR_H Disable_INT0 ()
{

	GICR &= ~(1<< INT0); /* Disable  INT0*/
	MCUCR &= ~((1<< ISC01) | (1<< ISC00)); // Clear Rising/Falling trigger bits


	return OK;
}

/* Interrupt service routine handler for EXT INT0
	It calls the callback function set by the user
*/
#ifdef ENABLE_INT0
ISR(EXT_INT_0) {
	_int0_func();
}
#endif

ERROR_H Enable_INT1 (uint8_t INT_STATE, void (*f)())
{
	sei();
	_int1_func = f;
	GICR |= (1<< INT1);
	if(INT_STATE == INT_FALLING)
	{
		MCUCR |= (1<< ISC11);
	}
	else if(INT_STATE == INT_RISING)
	{
		MCUCR |= (1<< ISC10) | (1<< ISC11);
	}
	else
	{
		return ERROR;
	}
	return OK;
}

ERROR_H Disable_INT1 ()
{

	GICR &= ~(1<< INT1); /* Disable  INT1*/
	MCUCR &= ~((1<< ISC11) | (1<< ISC10)); // Clear Rising/Falling trigger bits


	return OK;
}

/* Interrupt service routine handler for EXT INT1
	It calls the callback function set by the user
*/
#ifdef ENABLE_INT1
ISR(EXT_INT_1) {
	_int1_func();
}
#endif

ERROR_H Enable_INT2 (uint8_t INT_STATE, void (*f)())
{
	sei();
	_int2_func = f;
	GICR |= (1<< INT2);
	if(INT_STATE == INT_FALLING)
	{
		CLR_BIT(MCUCSR,ISC2);
	}
	else if(INT_STATE == INT_RISING)
	{
		SET_BIT(MCUCSR,ISC2);
	}
	else
	{
		return ERROR;
	}
	return OK;
}


ERROR_H Disable_INT2 ()
{

	GICR &= ~(1<< INT2); /* Disable  INT2*/
	MCUCSR &= ~((1<< ISC2));


	return OK;
}

/* Interrupt service routine handler for EXT INT2
	It calls the callback function set by the user
*/
#ifdef ENABLE_INT2
ISR(EXT_INT_2) {
	_int2_func();
}
#endif