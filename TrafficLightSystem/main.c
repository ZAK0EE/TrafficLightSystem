/*
 * TrafficLightSystem.c
 *
 * Created: 22/08/11 03:00:41 PM
 * Author : VGA
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/delay.h>
#include "MCAL/timer/timer.h"

// toggle PORTB status
void toggle() {

	PORTB = ~PORTB;

}

int main(void)
{
		// set all pins of PORTB as output
		DDRB = 0xff;
		PORTB = 0xff;
	// toggle PORTB every 500ms (using 16Mhz clock)
	timer1(TIMER1_PRESCALER_1024, 39063U, toggle);
	
		// enable
		sei();
    /* Replace with your application code */
    while (1) 
    {
		//_delay_ms(10);
		//PORTB = ~PORTB;
    }
}

