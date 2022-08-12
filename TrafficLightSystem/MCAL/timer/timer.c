//      Copyright 2011 Javier Valencia <javiervalencia80@gmail.com>
//
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
//
//		Modified by Ziad Gamalelden to fit ATmega32
//
#include "timer.h"



void (*_t0_func)();
void (*_t1_func)();
void (*_t2_func)();

ERROR_H timer0(uint8_t prescaler, uint8_t ticks, void (*f)()) {
	TIMSK &= ~(1 << OCIE0);				// disable interrupt
	_t0_func = f;						// assign user function
	TCCR0 = (1 << WGM01);				// set CTC mode
	OCR0 = ticks;						// set top value
	TCCR0 = prescaler;					// set prescaler
	TCNT0 = 0;							// reset TCNT counter register
	TIMSK |= (1 << OCIE0);				// enable interrupt
	return OK;
}

ERROR_H timer0_stop() {
	TCCR0 = 0;
	return OK;							// set prescaler to none, disabling timer
}

#ifdef ENABLE_TIMER0
ISR(TIMER0_COMP_vect) {
	_t0_func();
}
#endif

ERROR_H timer1(uint8_t prescaler, uint16_t ticks, void (*f)()) {
	TIMSK &= ~(1 << OCIE1A);
	_t1_func = f;
	OCR1A = ticks;
	TCCR1A = 0;
	TCCR1B = prescaler | (1 << WGM12);
	TCNT1 = 0;
	TIMSK |= (1 << OCIE1A);
	return OK;
}

ERROR_H timer1_stop() {
	TCCR1B = 0;
	return OK;
}

#ifdef ENABLE_TIMER1
ISR(TIMER1_COMPA_vect) {
	_t1_func();
}
#endif

ERROR_H timer2(uint8_t prescaler, uint8_t ticks, void (*f)()) {
	TIMSK &= ~(1 << OCIE2);
	_t2_func = f;
	OCR2 = ticks;
	ASSR = 0;
	TCCR2 = prescaler || (1 << WGM21);
	TCNT2 = 0;
	TIMSK |= (1 << OCIE2);
	return OK;
}

ERROR_H timer2_stop() {
	TCCR2 = 0;
	return OK;
}

#ifdef ENABLE_TIMER2

ISR(TIMER2_COMP_vect) {
	_t2_func();
}
#endif

ERROR_H wait0(uint8_t prescaler, uint8_t ticks) {
	if (ticks == 0)
	return ERROR;						// return if no ticks to count
	TIMSK &= ~(1 << OCIE0);				// disable compare interrupt
	OCR0 = ticks;					// set top value
	TCCR0 = (1 << WGM01);				// set CTC mode
	TCCR0 = prescaler;				// set prescaler
	TCNT0 = 0;						// reset TCNT counter register
	TIFR |= (1 << OCF0);			// reset compare flag
	while(!(TIFR & (1 << OCF0)));	// wait till compare flag goes up
	TCCR0 = 0;						// stop timer to save energy
	return OK;
}

ERROR_H wait1(uint8_t prescaler, uint16_t ticks) {
	if (ticks == 0)
	return ERROR;
	TIMSK &= ~(1 << OCIE1A);
	OCR1A = ticks;
	TCCR1A = 0;
	TCCR1B = prescaler | (1 << WGM12);
	TCNT1 = 0;
	TIFR |= (1 << OCF1A);
	while(!(TIFR & (1 << OCF1A)));
	TCCR1B = 0;
	return OK;
}

ERROR_H wait2(uint8_t prescaler, uint8_t ticks) {
	if (ticks == 0)
	return ERROR;
	TIMSK &= ~(1 << OCIE2);
	ASSR = 0;
	OCR2 = ticks;
	TCCR2 = (1 << WGM21);
	TCCR2 = prescaler;
	TCNT2 = 0;
	TIFR |= (1 << OCF2);
	while(!(TIFR & (1 << OCF2)));
	TCCR2 = 0;
	return OK;
}