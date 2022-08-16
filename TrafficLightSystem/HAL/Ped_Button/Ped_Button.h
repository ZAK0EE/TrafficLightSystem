/*
 * Ped_Button.h
 *
 * Created: 22/08/14 01:08:41 AM
 *  Author: Ziad
 */ 


#ifndef PED_BUTTON_H_
#define PED_BUTTON_H_

#include "dio/dio.h"
#include "interrupt/interrupt.h"

#define PED_BUTTON_DDR				DDRD
#define PED_BUTTON_PORT				PORTD
#define PED_BUTTON_PIN				PIN2
#define PED_BUTTON_TRIGGER			INT_FALLING
#define PED_BUTTON_EXTI				EXT_INT_0

/*
Use this function to initialize the pedestrian button
callback: the call back function that's called when interrupt occurs 
return: an error or OK
*/
ERROR_H Ped_Button_Init(void (*callback)());

/*
Use this function to Enable the pedestrian button
callback: the call back function that's called when interrupt occurs
return: an error or OK
*/
ERROR_H Ped_Button_Enable(void (*callback)());

/*
Use this function to Disable the pedestrian button
return: an error or OK
*/
ERROR_H Ped_Button_Disable();

#endif /* PED_BUTTON_H_ */