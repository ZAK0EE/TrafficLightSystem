/*
 * app.c
 *
 * Created: 22/08/14 01:40:39 AM
 *  Author: Ziad
 */ 

#include "app.h"

// States declarations
void TF_PX_CG_NY();
void TF_PG_CY_NR();
void TF_PX_CR_NY();
void TF_PR_CY_NG();

// An array of states pointers
void (*TF_states[4])(void)= {TF_PX_CG_NY, TF_PG_CY_NR, TF_PX_CR_NY, TF_PR_CY_NG};

// The current state index
uint8_t TF_State_Idx = 0;

void Ped_Button_Interrupt()
{
	// Disabling the button until next state
	Ped_Button_Disable();
	uint8_t state = 0;
	
	// Lookup table for the ped button special cases
	switch(TF_State_Idx)
	{
		case PX_CG_NY:
			state = PG_CY_NR;
			break;
		case PX_CR_NY:
			state = PX_CR_NY;
			break;
		case PG_CY_NR:
		case PR_CY_NG:
			state = PG_CY_NR;
			break;
	}
	
	TF_Goto_State(state);
}

// Yellow Led blink callback function for the blink timer
void TF_Y_Blink(void)
{
	DIO_toggle(TF_CARLED_PORT, TF_CARLED_Y);
	DIO_toggle(TF_PEDLED_PORT, TF_PEDLED_Y);
}

ERROR_H TF_Init()
{
	Ped_Button_Init(Ped_Button_Interrupt);
	
	// Init the traffic and PED leds
	DIO_init(TF_CARLED_PORT, TF_CARLED_G, OUT);
	DIO_init(TF_CARLED_PORT, TF_CARLED_Y, OUT);
	DIO_init(TF_CARLED_PORT, TF_CARLED_R, OUT);
	
	DIO_init(TF_PEDLED_PORT, TF_PEDLED_G, OUT);
	DIO_init(TF_PEDLED_PORT, TF_PEDLED_Y, OUT);
	DIO_init(TF_PEDLED_PORT, TF_PEDLED_R, OUT);
		
	TF_Goto_State(0);
	return OK;
	
}

ERROR_H TF_Goto_State(uint8_t state)
{
	// Reset Timers
	timer0_stop();
	timer1_stop();
	
	// Set the current state
	TF_State_Idx = state;
	// Call current state
	TF_states[TF_State_Idx]();
	
	// five seconds timer for each state before moving to the next
	timer1(TIMER1_PRESCALER_1024, _5SEC_TICKS, TF_Next_State);
	
	return OK;
}


void TF_Next_State(void)
{
	// Reset the blinking timer
	timer0_stop();
	
	// Get number of states
	int statesSize = (sizeof(TF_states) /  sizeof(TF_states[0]));
	
	// Add one to the current state index with limitation to the array size
	TF_State_Idx = (TF_State_Idx + 1) % statesSize;
	
	TF_states[TF_State_Idx]();
	
	Ped_Button_Enable(Ped_Button_Interrupt);
	
}

/***********************************States definitions***********************************/
void TF_PX_CG_NY()
{
	DIO_write(TF_CARLED_PORT, TF_CARLED_G, HIGH);
	DIO_write(TF_CARLED_PORT, TF_CARLED_Y, LOW);
	DIO_write(TF_CARLED_PORT, TF_CARLED_R, LOW);

	DIO_write(TF_PEDLED_PORT, TF_PEDLED_G, LOW);
	DIO_write(TF_PEDLED_PORT, TF_PEDLED_Y, LOW);
	DIO_write(TF_PEDLED_PORT, TF_PEDLED_R, HIGH);	
	
	
}

void TF_PG_CY_NR()
{
	DIO_write(TF_CARLED_PORT, TF_CARLED_G, LOW);
	DIO_write(TF_CARLED_PORT, TF_CARLED_Y, HIGH);
	DIO_write(TF_CARLED_PORT, TF_CARLED_R, LOW);

	DIO_write(TF_PEDLED_PORT, TF_PEDLED_G, LOW);
	DIO_write(TF_PEDLED_PORT, TF_PEDLED_Y, HIGH);
	DIO_write(TF_PEDLED_PORT, TF_PEDLED_R, LOW);
	
	// Blink timer
	timer0(TIMER0_PRESCALER_1024, BLINK_TICKS, TF_Y_Blink);

}
void TF_PX_CR_NY()
{
	DIO_write(TF_CARLED_PORT, TF_CARLED_G, LOW);
	DIO_write(TF_CARLED_PORT, TF_CARLED_Y, LOW);
	DIO_write(TF_CARLED_PORT, TF_CARLED_R, HIGH);

	DIO_write(TF_PEDLED_PORT, TF_PEDLED_G, HIGH);
	DIO_write(TF_PEDLED_PORT, TF_PEDLED_Y, LOW);
	DIO_write(TF_PEDLED_PORT, TF_PEDLED_R, LOW);
}
void TF_PR_CY_NG()
{
	DIO_write(TF_CARLED_PORT, TF_CARLED_G, LOW);
	DIO_write(TF_CARLED_PORT, TF_CARLED_Y, HIGH);
	DIO_write(TF_CARLED_PORT, TF_CARLED_R, LOW);

	DIO_write(TF_PEDLED_PORT, TF_PEDLED_G, LOW);
	DIO_write(TF_PEDLED_PORT, TF_PEDLED_Y, HIGH);
	DIO_write(TF_PEDLED_PORT, TF_PEDLED_R, LOW);
	
	// Blink timer
	timer0(TIMER0_PRESCALER_1024, BLINK_TICKS, TF_Y_Blink);
}