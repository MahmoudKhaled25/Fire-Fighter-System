/*
 * Serive_App.h
 *
 * Created: 4/14/2024 10:30:15 PM
 *  Author: Mahmoud Khaled
 */ 


#ifndef SERIVE_APP_H_
#define SERIVE_APP_H_

/*********************************************** Include Section *****************************************/
#define F_CPU 8E6
#include <util/delay.h>
#include "MemoryMap.h"
#include "Utilities.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "KEYPAD_Interface.h"
#include "ADC_Interface.h"
#include "NVM_Interface.h"
#include "EX_Interrupt.h"
#include "Filter.h"
#include "Timer0.h"
#include "Timer1.h"
#include "Timer_Service.h"
#include "Password_Manager.h"

/*********************************************** Macro Section *****************************************/
#define GREEN_LED   PIND4
#define YELLOW_LED  PIND5
#define RED_LED		PIND6
#define ALARM		PIND7

// Unit: C*10
#define HEAT_TEMP		500
#define FINE_TEMP		480

// Unit: KPa*10
#define CRITICAL_SMOKE	650

#define	SYS_STATE_ADD 0x00FF

/****************************************** typedef section **********************************************/
typedef enum {
	FINE_STATE,
	HEAT_STATE,
	FIRE_STATE
}APP_SystemState_type;

/******************************************** Global declaration *****************************************/
void APP_Init(void);
void App_StartWindow(void);
void APP_StateAct(void);
void APP_StateUpadate(void);

#endif /* SERIVE_APP_H_ */