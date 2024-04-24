/*
 * Timer1.c
 *
 * Created: 4/17/2024 3:38:50 AM
 *  Author: Mahmoud Khaled
 */ 

#include "Timer1.h"

static CallBackPtr_type Timer1_OVF_FPtr = NULLPTR;
static CallBackPtr_type Timer1_COMPA_FPtr = NULLPTR;
static CallBackPtr_type Timer1_COMPB_FPtr = NULLPTR;
static CallBackPtr_type Timer1_CAPT_FPtr = NULLPTR;

void Timer1_Init(TIMER1_OperationMode_type mode, TIMER1_Prescaler_type prescaler)
{
	// Mode Selection
	TCCR1A &= 0xFC;
	TCCR1A |= ((u8)mode & 0x03);
	TCCR1B &= 0xE7;
	TCCR1B |= (((u8)mode << 1) & 0x18);
	
	//	Prescaler Selection
	TCCR1B &= 0xF8;
	prescaler &= 0x07;
	TCCR1B |= (u8)prescaler;
}

void Timer1_OVF_InterruptEnable()
{
	SET_BIT(TIMSK, TOIE1);
}

void Timer1_OVF_InterruptDisable()
{
	CLR_BIT(TIMSK, TOIE1);
}

void Timer1_COMPA_InterruptEnable()
{
	SET_BIT(TIMSK, OCIE1A);
}

void Timer1_COMPA_InterruptDisable()
{
	CLR_BIT(TIMSK, OCIE1A);
}

void Timer1_COMPB_InterruptEnable()
{
	SET_BIT(TIMSK, OCIE1B);
}

void Timer1_COMPB_InterruptDisable()
{
	CLR_BIT(TIMSK, OCIE1B);
}


void Timer1_CAPT_InterruptEnable()
{
	SET_BIT(TIMSK, TICIE1);
}

void Timer1_CAPT_InterruptDisable()
{
	CLR_BIT(TIMSK, TICIE1);
}

void Timer1_CAPTNoiseCancler_Enable()
{
	SET_BIT(TCCR1B, ICNC1);
}

void Timer1_CAPTNoiseCancler_Disable()
{
	CLR_BIT(TCCR1B, ICNC1);
}

void Timer1_OC1_PinMode(TIMER1_OC1_PinMode_type PinMode)
{
	switch (PinMode)
	{
		case TIMER1_OC1A_OC1B_DISCONNECTED:
		CLR_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1B0);
		CLR_BIT(TCCR1A,COM1A1);
		CLR_BIT(TCCR1A,COM1B1);
		break;
		
		case TIMER1_OC1A_OC1B_TOGGLE:
		case TIMER1_OC1A_TOGGLE_OC1B_DISCONNECTED:
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1B0);
		CLR_BIT(TCCR1A,COM1A1);
		CLR_BIT(TCCR1A,COM1B1);
		break;
		
		case TIMER1_OC1A_OC1B_CLEAR:
		case TIMER1_OC1A_OC1B_NON_INVERTING:
		CLR_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1A1);
		SET_BIT(TCCR1A,COM1B1);
		break;
		
		case TIMER1_OC1A_OC1B_SET:
		case TIMER1_OC1A_OC1B_INVERTING:
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1A1);
		SET_BIT(TCCR1A,COM1B1);
		break;
		
		default:
		break;
	}
}

void  Timer1_ICU_TriggerEdge(TIMER1_ICU_TriggerEdge_type Edge)
{
	switch(Edge)
	{
		case ICU_FALLING_EDGE:
		CLR_BIT(TCCR1B, ICES1);
		break;
		
		case ICU_RISING_EDGE:
		SET_BIT(TCCR1B, ICES1);
		break;
		
		default:
		break;
	}
}

void Timer1_OVF_SetCallback(CallBackPtr_type LocalPtr)
{
	Timer1_OVF_FPtr = LocalPtr;
}

void Timer1_COMPA_SetCallback(CallBackPtr_type LocalPtr)
{
	Timer1_COMPA_FPtr = LocalPtr;
}

void Timer1_COMPB_SetCallback(CallBackPtr_type LocalPtr)
{
	Timer1_COMPB_FPtr = LocalPtr;
}

void Timer1_CAPT_SetCallback(CallBackPtr_type LocalPtr)
{
	Timer1_CAPT_FPtr = LocalPtr;
}

ISR(TIMER1_COMPA_vect)
{
	if(Timer1_COMPA_FPtr)
		Timer1_COMPA_FPtr();
}

ISR(TIMER1_COMPB_vect)
{
	if(Timer1_COMPB_FPtr)
		Timer1_COMPB_FPtr();
}


ISR(TIMER1_OVF_vect)
{
	if(Timer1_OVF_FPtr)
		Timer1_OVF_FPtr();
}

ISR(TIMER1_CAPT_vect)
{
	if(Timer1_CAPT_FPtr)
		Timer1_CAPT_FPtr();
}