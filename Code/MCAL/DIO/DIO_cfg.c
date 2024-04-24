/*
 * DIO_cfg.c
 *
 * Created: 12/8/2023 1:49:32 PM
 *  Author: Mahmoud Khaled
 */ 

#include "DIO_Interface.h"

DIO_PinStatues_type const Pin_Statues[TOTAL_PIN]=
{
	INPUT_FREE,		// PA0  (ADC0)
	INPUT_FREE,		// PA1  (ADC1)
	OUTPUT,			// PA2  (ADC2)
	OUTPUT,			// PA3  (ADC3)
	OUTPUT,			// PA4  (ADC4)
	OUTPUT,			// PA5  (ADC5)
	OUTPUT,			// PA6  (ADC6)
	OUTPUT,			// PA7  (ADC7)

	OUTPUT,			// PB0  (T0)    (XCK)
	INPUT_PULLUP,	// PB1  (T1)  
	INPUT_PULLUP,	// PB2  (INT2)  (AIN0)
	INPUT_PULLUP,	// PB3  (OC0)   (AIN1)
	OUTPUT,			// PB4  (-SS)   // (-) mean active low
	OUTPUT,			// PB5  (MOSI)
	OUTPUT,			// PB6  (MISO)
	OUTPUT,			// PB7  (SCK)

	OUTPUT,			// PC0  (SCL)
	OUTPUT,			// PC1  (SDA)
	OUTPUT,			// PC2  (TCK)
	OUTPUT,			// PC3  (TMS)
	OUTPUT,			// PC4  (TDO)
	OUTPUT,			// PC5  (TDI)
	OUTPUT,			// PC6  (TOSC1)
	OUTPUT,			// PC7  (TOSC2)

	OUTPUT,			// PD0  (RXD)
	OUTPUT,			// PD1  (TXD)
	OUTPUT,			// PD2  (INT0)
	INPUT_PULLUP,	// PD3  (INT1)
	OUTPUT,	        // PD4  (OSC1B)
	OUTPUT,			// PD5  (OSC1A)
	OUTPUT,			// PD6  (ICP1)
	OUTPUT,			// PD7  (OC2)
};	