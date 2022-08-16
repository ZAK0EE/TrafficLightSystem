/*
 * dio.h
 *
 * Created: 22/08/11 04:58:02 PM
 *  Author: Ziad
 */ 

#include "dio.h"


ERROR_H DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction) // initialize dio direction
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
			default:
			return ERROR;
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
			default:
			return ERROR;
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
			default:
			return ERROR;
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
			default:
			return ERROR;
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
		default:
		return ERROR;
		break;
	}
	return OK;
}

ERROR_H DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value) //read dio
{
	switch(portNumber)
	{
		case PORT_A:
		*value = GET_BIT(PINA, pinNumber);
		break;
		case PORT_B:
		*value = GET_BIT(PINB, pinNumber);
		break;
		case PORT_C:
		*value = GET_BIT(PINC, pinNumber);
		break;
		case PORT_D:
		*value = GET_BIT(PIND, pinNumber);
		break;
		default:
		return ERROR;
		break;
	}
	return OK;
}


ERROR_H DIO_Port_Write(uint8_t portNumber, uint8_t value)
{
	switch(portNumber)
	{
		case PORT_A:
		PORTA = value;
		break;
		case PORT_B:
		PORTB = value;
		break;
		case PORT_C:
		PORTC = value;
		break;
		case PORT_D:
		PORTD = value;
		break;
		default:
		return ERROR;
		break;
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
		default:
		return ERROR;
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
			default:
			return ERROR;
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
			default:
			return ERROR;
			break;
		}
	}
	else
	{
		return ERROR;
	}
	return OK;
}