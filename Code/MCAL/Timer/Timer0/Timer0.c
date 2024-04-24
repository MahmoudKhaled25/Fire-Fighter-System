/*
 * Timer.c
 *
 * Created: 4/14/2024 3:27:47 PM
 *  Author: Mahmoud Khaled
 */ 

#include "Timer0.h"

static CallBackPtr_type Timer0_OVF_FPtr = NULLPTR;
static CallBackPtr_type Timer0_COMP_FPtr = NULLPTR;


void Timer0_Init(TIMER0_OperationMode_type mode, TIMER0_Prescaler_type prescaler)
{
	switch(mode)
	{
		case TIMER0_NORMAL_MODE:
			CLR_BIT(TCCR0, WGM00);
			CLR_BIT(TCCR0, WGM01);
			break;
		case TIMER0_CTC_MODE:
			CLR_BIT(TCCR0, WGM00);
			SET_BIT(TCCR0, WGM01);
			break;
		case TIMER0_FAST_PWM_MODE:
			SET_BIT(TCCR0, WGM00);
			SET_BIT(TCCR0, WGM01);
			break;
		case TIMER0_PHASE_CORRECT_MODE:
			SET_BIT(TCCR0, WGM00);
			CLR_BIT(TCCR0, WGM01);
			break;
		default:
			break;
	}
	prescaler &= 0x07;
	TCCR0 &= 0xF8;
	TCCR0 |= (u8)prescaler; 
}

void Timer0_OVF_InterruptEnable()
{
	SET_BIT(TIMSK, TOIE0);
}

void Timer0_OVF_InterruptDisable()
{
	CLR_BIT(TIMSK, TOIE0);
}

void Timer0_COMP_InterruptEnable()
{
	SET_BIT(TIMSK, OCIE0);
}

void Timer0_COMP_InterruptDisable()
{
	CLR_BIT(TIMSK, OCIE0);
}

void Timer0_OC0_PinMode(TIMER0_OC0_PinMode_type PinMode)
{
	switch(PinMode)
	{
		case TIMER0_OC0_DISCONNECTED:
		CLR_BIT(TCCR0, COM00);
		CLR_BIT(TCCR0, COM01);
		break;
		
		case TIMER0_OC0_TOGGLE:
		SET_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
		break;
		
		case TIMER0_OC0_CLEAR:
		case TIMER0_OC0_NON_INVERTING:
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
		
		case TIMER0_OC0_SET:
		case TIMER0_OC0_INVERTING:
		SET_BIT(TCCR0, COM00);
		SET_BIT(TCCR0, COM01);
		break;
		
		default:
		break;
	}
}

void Timer0_OVF_SetCallback(CallBackPtr_type LocalPtr)
{
	Timer0_OVF_FPtr = LocalPtr;
}

void Timer0_COMP_SetCallback(CallBackPtr_type LocalPtr)
{
	Timer0_COMP_FPtr = LocalPtr;
}

ISR(TIMER0_COMP_vect)
{
	if(Timer0_COMP_FPtr)
		Timer0_COMP_FPtr();
}

ISR(TIMER0_OVF_vect)
{
	if(Timer0_OVF_FPtr)
		Timer0_OVF_FPtr();
}