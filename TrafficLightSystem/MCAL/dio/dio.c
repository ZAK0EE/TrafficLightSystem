/*
 * dio.h
 *
 * Created: 22/08/11 04:58:02 PM
 *  Author: Ziad
 */ 

#include "dio.h"

ERROR_H DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction) // Initail dio direction
{
	if (direction == OUT)
	{
		switch(portNumber)
		{
			case PORT_A:
			DDRA |= (1 << pinNumber);
			break;
			case PORT_B:
			DDRB |= (1 << pinNumber);
			break;
			case PORT_C:
			DDRC |= (1 << pinNumber);
			break;
			case PORT_D:
			DDRD |= (1 << pinNumber);
			break;
		}
	}
	else if(direction == IN)
	{
		switch(portNumber)
		{
			case PORT_A:
			DDRA &= ~(1 << pinNumber);
			break;
			case PORT_B:
			DDRB &= ~(1 << pinNumber);
			break;
			case PORT_C:
			DDRC &= ~(1 << pinNumber);
			break;
			case PORT_D:
			DDRD &= ~(1 << pinNumber);
			break;
		}
	}
	else
	{
		return ERROR;
	}
	return OK;
}

ERROR_H DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value) // Write data to dio
{
	if (value == HIGH)
	{
		switch(portNumber)
		{
			case PORT_A:
			PORTA |= (1 << pinNumber);
			break;
			case PORT_B:
			PORTB |= (1 << pinNumber);
			break;
			case PORT_C:
			PORTC |= (1 << pinNumber);
			break;
			case PORT_D:
			PORTD |= (1 << pinNumber);
			break;
		}
	}
	else if(value == LOW)
	{
		switch(portNumber)
		{
			case PORT_A:
			PORTA &= ~(1 << pinNumber);
			break;
			case PORT_B:
			PORTB &= ~(1 << pinNumber);
			break;
			case PORT_C:
			PORTC &= ~(1 << pinNumber);
			break;
			case PORT_D:
			PORTD &= ~(1 << pinNumber);
			break;
		}
	}
	else
	{
		return ERROR;
	}
	return OK;
}


ERROR_H DIO_toggle(uint8_t portNumber, uint8_t pinNumber) // toggle data
{
	switch(portNumber)
	{
		case PORT_A:
		TOGGLE_BIT(PORTA, pinNumber);
		break;
		case PORT_B:
		TOGGLE_BIT(PORTB, pinNumber);
		break;
		case PORT_C:
		TOGGLE_BIT(PORTC, pinNumber);
		break;
		case PORT_D:
		TOGGLE_BIT(PORTD, pinNumber);
		break;
	}
	return OK;
}

ERROR_H DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value) //read dio
{
	switch(portNumber)
	{
		case PORT_A:
		*value = GET_BIT(PORTA, pinNumber);
		break;
		case PORT_B:
		*value = GET_BIT(PORTB, pinNumber);
		break;
		case PORT_C:
		*value = GET_BIT(PORTC, pinNumber);
		break;
		case PORT_D:
		*value = GET_BIT(PORTD, pinNumber);
		break;
	}
	return OK;
}


ERROR_H DIO_Port_Write(uint8_t portNumber, uint8_t value)
{
	if (value == HIGH)
	{
		switch(portNumber)
		{
			case PORT_A:
			PORTA = 0xff;
			break;
			case PORT_B:
			PORTB = 0xff;
			break;
			case PORT_C:
			PORTC = 0xff;
			break;
			case PORT_D:
			PORTD = 0xff;
			break;
		}
	}
	else if (value ==  LOW)
	{
		switch(portNumber)
		{
			case PORT_A:
			PORTA = 0x00;
			break;
			case PORT_B:
			PORTB = 0x00;
			break;
			case PORT_C:
			PORTC = 0x00;
			break;
			case PORT_D:
			PORTD = 0x00;
			break;
		}
	}
	else
	{
		return ERROR;
	}
	return OK;
}


ERROR_H DIO_Port_Read(uint8_t portNumber, uint8_t *value)
{
	switch(portNumber)
	{
		case PORT_A:
		*value = PINA;
		break;
		case PORT_B:
		*value = PINB;
		break;
		case PORT_C:
		*value = PINC;
		break;
		case PORT_D:
		*value = PIND;
		break;
	}
	return OK;
}


ERROR_H DIO_Port_Direction(uint8_t portNumber, uint8_t direction)
{
	if (direction == OUT)
	{
		switch(portNumber)
		{
			case PORT_A:
			DDRA = 0xff;
			break;
			case PORT_B:
			DDRB = 0xff;
			break;
			case PORT_C:
			DDRC = 0xff;
			break;
			case PORT_D:
			DDRD = 0xff;
			break;
		}
	}
	else if (direction == IN)
	{
		switch(portNumber)
		{
			case PORT_A:
			DDRA = 0x00;
			break;
			case PORT_B:
			DDRB = 0x00;
			break;
			case PORT_C:
			DDRC = 0x00;
			break;
			case PORT_D:
			DDRD = 0x00;
			break;
		}
	}
	else
	{
		return ERROR;
	}
	return OK;
}