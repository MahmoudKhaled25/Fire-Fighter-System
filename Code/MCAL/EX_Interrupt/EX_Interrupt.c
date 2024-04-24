/*
 * EX_Interrupt.c
 *
 * Created: 4/7/2024 4:48:57 PM
 *  Author: Mahmoud Khaled
 */ 

#include "EX_Interrupt.h"

static CallBackPtr_type INT0_Fptr = NULLPTR;
static CallBackPtr_type INT1_Fptr = NULLPTR;
static CallBackPtr_type INT2_Fptr = NULLPTR;

void EXI_Init(void)
{
	MCUCR &= 0xF0;
	MCUCR |= 0X0A; 
	CLR_BIT(MCUCSR, ISC2);
}

void EXI_Enable(EXI_Source_type Interrupt)
{
	switch(Interrupt)
	{
		case EX_INT0:
			SET_BIT(GICR, INT0);
			break;
		case EX_INT1:
			SET_BIT(GICR, INT1);
			break;
		case EX_INT2:
			SET_BIT(GICR, INT2);
			break;
	}
}

void EXI_Disable(EXI_Source_type Interrupt)
{
	switch(Interrupt)
	{
		case EX_INT0:
			CLR_BIT(GICR, INT0);
			break;
		case EX_INT1:
			CLR_BIT(GICR, INT1);
			break;
		case EX_INT2:
			CLR_BIT(GICR, INT2);
			break;
	}
}

void EXI_TriggerEdge(EXI_Source_type Interrupt, EXI_TriggerEdge_type Edge)
{
	if (FALLING_EDGE == Edge)
	{
		switch(Interrupt)
		{
			case EX_INT0:
				CLR_BIT(MCUCR, ISC00);
				SET_BIT(MCUCR, ISC01);
			break;
			case EX_INT1:
				CLR_BIT(MCUCR, ISC10);
				SET_BIT(MCUCR, ISC11);
				break;
			case EX_INT2:
				CLR_BIT(MCUCSR, ISC2);
				break;
		}
	}
	else if (RISING_EDGE == Edge)
	{
		switch(Interrupt)
		{
			case EX_INT0:
				SET_BIT(MCUCR, ISC00);
				SET_BIT(MCUCR, ISC01);
				break;
			case EX_INT1:
				SET_BIT(MCUCR, ISC10);
				SET_BIT(MCUCR, ISC11);
				break;
			case EX_INT2:
				SET_BIT(MCUCSR, ISC2);
				break;
		}
	}
	else {/* Noting */}
}

void EXI_SetCallBack(EXI_Source_type Interrupt, CallBackPtr_type LocalPtr)
{
	switch(Interrupt)
	{
		case EX_INT0:
			INT0_Fptr = LocalPtr;
			break;	
		case EX_INT1:
			INT1_Fptr = LocalPtr;
			break;
		case EX_INT2:
			INT2_Fptr = LocalPtr;
			break;	
	}
}

ISR(INT0_vect)
{
	if (INT0_Fptr)
		INT0_Fptr();
}

ISR(INT1_vect)
{
	if (INT1_Fptr)
		INT1_Fptr();
}

ISR(INT2_vect)
{
	if (INT2_Fptr)
		INT2_Fptr();
}