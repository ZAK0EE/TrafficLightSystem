/*
 * TrafficLightSystem.c
 *
 * Created: 22/08/11 03:00:41 PM
 * Author : VGA
 */ 
#define F_CPU 1000000UL

#include "APP/app.h"



int main(void)
{
		sei();
	Ped_Button_Init();
	TF_Init(0);
    while (1) 
    {

    }
}

