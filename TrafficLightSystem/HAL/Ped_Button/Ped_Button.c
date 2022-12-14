/*
 * Ped_Button.c
 *
 * Created: 22/08/14 01:07:56 AM
 *  Author: Ziad
 */ 

#include "Ped_Button/Ped_Button.h"

ERROR_H Ped_Button_Init(void (*callback)())
{
	Ped_Button_Enable(callback);
	
	return OK;
}
ERROR_H Ped_Button_Enable(void (*callback)())
{
	DIO_init(PED_BUTTON_PORT, PED_BUTTON_PIN, IN);
	Enable_INT0(PED_BUTTON_TRIGGER, callback);
	return OK;

}
ERROR_H Ped_Button_Disable()
{
	Disable_INT0(PED_BUTTON_TRIGGER);
	return OK;


}