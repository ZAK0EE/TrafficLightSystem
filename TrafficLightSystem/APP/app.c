/*
 * app.c
 *
 * Created: 22/08/14 01:40:39 AM
 *  Author: Ziad
 */ 

#include "app.h"

// States
void TF_PX_CG_NY();
void TF_PG_CY_NR();
void TF_PX_CR_NY();
void TF_PR_CY_NG();

void (*TF_states[4])(void)= {TF_PX_CG_NY, TF_PG_CY_NR, TF_PX_CR_NY, TF_PR_CY_NG};

uint8_t TF_State_Idx = 0;

ISR(PED_BUTTON_EXTI)
{
	Ped_Button_Disable();
	uint8_t state = 0;
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
	
	TF_Init(state);
}
void TF_Init(uint8_t state)
{
	timer0_stop();
	timer1_stop();
	
	DIO_init(TF_CARLED_PORT, TF_CARLED_G, OUT);
	DIO_init(TF_CARLED_PORT, TF_CARLED_Y, OUT);
	DIO_init(TF_CARLED_PORT, TF_CARLED_R, OUT);
	
	DIO_init(TF_PEDLED_PORT, TF_PEDLED_G, OUT);
	DIO_init(TF_PEDLED_PORT, TF_PEDLED_Y, OUT);
	DIO_init(TF_PEDLED_PORT, TF_PEDLED_R, OUT);
	
	TF_State_Idx = state;
	TF_states[TF_State_Idx]();
	timer1(TIMER1_PRESCALER_1024, 4883U, TF_Next_State);
	
}

void TF_Y_Blink(void)
{
	DIO_toggle(TF_CARLED_PORT, TF_CARLED_Y);
	DIO_toggle(TF_PEDLED_PORT, TF_PEDLED_Y);
}
void TF_Next_State(void)
{
	
	timer0_stop();
	TF_State_Idx = (TF_State_Idx + 1) % (sizeof(TF_states) /  sizeof(TF_states[0]));
	TF_states[TF_State_Idx]();

	
	Ped_Button_Enable();

}

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
	timer0(TIMER0_PRESCALER_1024, 255U, TF_Y_Blink);

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
	timer0(TIMER0_PRESCALER_1024, 255U, TF_Y_Blink);
}