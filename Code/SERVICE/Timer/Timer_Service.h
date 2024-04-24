/*
 * Timer_Service.h
 *
 * Created: 4/16/2024 5:27:39 PM
 *  Author: Mahmoud Khaled
 */ 


#ifndef TIMER_SERVICE_H_
#define TIMER_SERVICE_H_

/************************************************** Include section **********************************************************/
#include "StdTypes.h"
#include "MemoryMap.h"
#include "Utilities.h"
#include "Timer0.h"
#include "Timer1.h"

/************************************************ Function declaration *******************************************************/
void Timer0_SetInterruptTime_us(u16 Time_us, CallBackPtr_type LocalPtr);
void Timer1_TimeoutAndExecute_s(u8 Time_s, CallBackPtr_type LocalPtr);

#endif /* TIMER_SERVICE_H_ */