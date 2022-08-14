/*
 * app.h
 *
 * Created: 22/08/14 01:40:24 AM
 *  Author: Ziad
 */ 


#ifndef APP_H_
#define APP_H_

#include "dio/dio.h"
#include "Ped_Button/Ped_Button.h"
#include "timer/timer.h"

#define TF_CARLED_PORT		 PORT_A
#define TF_CARLED_G			 PIN0
#define TF_CARLED_Y			 PIN1
#define TF_CARLED_R			 PIN2

#define TF_PEDLED_PORT		PORT_B
#define TF_PEDLED_G			PIN0
#define TF_PEDLED_Y			PIN1
#define TF_PEDLED_R			PIN2

// States indices
#define PX_CG_NY 0
#define PG_CY_NR 1
#define PX_CR_NY 2
#define PR_CY_NG 3

#define PED EXT_INT_0


void TF_Init(uint8_t state);

void TF_Next_State(void);


void (*TF_states[4])(void);



#endif /* APP_H_ */