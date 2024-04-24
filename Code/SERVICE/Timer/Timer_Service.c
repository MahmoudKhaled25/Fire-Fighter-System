/*
 * Timer_Service.c
 *
 * Created: 4/16/2024 5:28:01 PM
 *  Author: Mahmoud Khaled
 */ 

#include "Timer_Service.h"
#define F_CPU_MHZ 8

static void icu_callback(void);

void Timer0_SetInterruptTime_us(u16 time_us, CallBackPtr_type LocalPtr)
{
	TIMER0_Prescaler_type prescaler;
	u16 N;
	
	// Select Appropriate Timer Prescaler
	if ((1*256)/F_CPU_MHZ > time_us)
	{
		prescaler = TIMER0_NO_SCALER;
		N=1;
	}
	else if ((8*256)/F_CPU_MHZ > time_us)
	{
		prescaler = TIMER0_SCALER_8;
		N=8;
	}
	else if ((64*256)/F_CPU_MHZ > time_us)
	{
		prescaler = TIMER0_SCALER_64;
		N=64;
	}
	else if (((u32)256*256)/F_CPU_MHZ > time_us)
	{
		prescaler = TIMER0_SCALER_256;
		N=256;
	}
	else if (((u32)1024*256)/F_CPU_MHZ > time_us)
	{
		prescaler = TIMER0_SCALER_1024;
		N=1024;
	}
	else
	{
		prescaler = TIMER0_NO_CLOCK;
		N=0;
	}
	
	// Initialize Timer0 with Prescaler and set to CTC mode
	Timer0_Init(TIMER0_CTC_MODE, prescaler);
	
	// Set Timer0 COMP Callback
	Timer0_COMP_SetCallback(LocalPtr);
		
	// Calculate OCR0 Value
	if (N)
	{
		OCR0= ((u32)time_us*F_CPU_MHZ)/N - 1;
	}
	
	// Enable COMP Interrupt
	Timer0_COMP_InterruptEnable();
	
}

void Timer1_TimeoutAndExecute_s(u8 Time_s, CallBackPtr_type LocalPtr)
{
	Timer1_ICU_TriggerEdge(ICU_FALLING_EDGE);
	Timer1_OutCompAWrite(((u32)8000000*Time_s)/1024);
	Timer1_COMPA_SetCallback(LocalPtr);
	Timer1_CAPT_SetCallback(icu_callback);
	Timer1_Init(TIMER1_CTC_OCR1ATOP_MODE, TIMER1_SCALER_1024);
	Timer1_CAPT_InterruptEnable();
}

static void icu_callback(void)
{
	static u8 flag=1;
	if (flag)
	{
		SET_BIT(TIFR, OCF1A);
		Timer1_Write(0);
		Timer1_COMPA_InterruptEnable();
		Timer1_ICU_TriggerEdge(ICU_RISING_EDGE);
		flag = 0;
	}
	else
	{
		Timer1_COMPA_InterruptDisable();
		Timer1_ICU_TriggerEdge(ICU_FALLING_EDGE);
		flag = 1;
	}
}