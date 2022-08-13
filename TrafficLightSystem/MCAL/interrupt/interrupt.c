/*
 * interrupt.c
 *
 * Created: 22/08/13 10:39:56 PM
 *  Author: Ziad
 */ 

#include "interrupt.h"

/* Using this function to enable Interrupt 1
 * INPUT : uint8_t --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H Enable_INT0 (uint8_t INT_STATE)
{
	sei();
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

/* Using this function to enable Interrupt 1
 * INPUT : uint8_t --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H Enable_INT1 (uint8_t INT_STATE)
{
	sei();
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

/* Using this function to enable Interrupt 1
 * INPUT : uint8_t --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
ERROR_H Enable_INT2 (uint8_t INT_STATE)
{
	sei();
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