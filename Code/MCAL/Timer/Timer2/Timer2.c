/*
 * Timer2.c
 *
 * Created: 4/17/2024 9:50:08 PM
 *  Author: Mahmoud Khaled
 */ 
#include "Timer2.h"


static CallBackPtr_type Timer2_OVF_FPtr = NULLPTR;
static CallBackPtr_type Timer2_COMP_FPtr = NULLPTR;


void Timer2_Init(TIMER2_OperationMode_type mode, TIMER2_Prescaler_type prescaler)
{
	switch(mode)
	{
		case TIMER2_NORMAL_MODE:
		CLR_BIT(TCCR2, WGM20);
		CLR_BIT(TCCR2, WGM21);
		break;
		
		case TIMER2_CTC_MODE:
		CLR_BIT(TCCR2, WGM20);
		SET_BIT(TCCR2, WGM21);
		break;
		
		case TIMER2_FAST_PWM_MODE:
		SET_BIT(TCCR2, WGM20);
		SET_BIT(TCCR2, WGM21);
		break;
		
		case TIMER2_PHASE_CORRECT_MODE:
		SET_BIT(TCCR2, WGM20);
		CLR_BIT(TCCR2, WGM21);
		break;
		
		default:
		break;
	}
	prescaler &= 0x07;
	TCCR2 &= 0xF8;
	TCCR2 |= (u8)prescaler;
}

void Timer2_OVF_InterruptEnable()
{
	SET_BIT(TIMSK, TOIE2);
}

void Timer2_OVF_InterruptDisable()
{
	CLR_BIT(TIMSK, TOIE2);
}

void Timer2_COMP_InterruptEnable()
{
	SET_BIT(TIMSK, OCIE2);
}

void Timer2_COMP_InterruptDisable()
{
	CLR_BIT(TIMSK, OCIE2);
}

void Timer2_OC2_PinMode(TIMER2_OC2_PinMode_type PinMode)
{
	switch(PinMode)
	{
		case TIMER2_OC2_DISCONNECTED:
		CLR_BIT(TCCR2, COM20);
		CLR_BIT(TCCR2, COM21);
		break;
		
		case TIMER2_OC2_TOGGLE:
		SET_BIT(TCCR2,COM20);
		CLR_BIT(TCCR2,COM21);
		break;
		
		case TIMER2_OC2_CLEAR:
		case TIMER2_OC2_NON_INVERTING:
		CLR_BIT(TCCR2,COM20);
		SET_BIT(TCCR2,COM21);
		break;
		
		case TIMER2_OC2_SET:
		case TIMER2_OC2_INVERTING:
		SET_BIT(TCCR2, COM20);
		SET_BIT(TCCR2, COM21);
		break;
		
		default:
		break;
	}
}

void Timer2_OVF_SetCallback(CallBackPtr_type LocalPtr)
{
	Timer2_OVF_FPtr = LocalPtr;
}

void Timer2_COMP_SetCallback(CallBackPtr_type LocalPtr)
{
	Timer2_COMP_FPtr = LocalPtr;
}

ISR(TIMER2_COMP_vect)
{
	if(Timer2_COMP_FPtr)
		Timer2_COMP_FPtr();
}

ISR(TIMER2_OVF_vect)
{
	if(Timer2_OVF_FPtr)
		Timer2_OVF_FPtr();
}