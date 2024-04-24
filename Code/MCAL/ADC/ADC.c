/*
 * ADC.c
 *
 * Created: 12/18/2023 10:13:50 PM
 *  Author: Mahmoud Khaled
 */ 

/************************************ Include Section ***********************************/
#include "ADC_Interface.h"

/********************************** Global Declaration *********************************/
u16 voltRef;

/******************************** Function Implementaion *******************************/
void ADC_Init(ADC_Vref_type vref, ADC_Prescaler_type prescaler)
{
	/* ADC Clock Adjustment */
	SELECT_PS(prescaler);
	
	/* ADC Voltage Reference Selection */
	SELECT_VREF(vref);
	switch(vref)
	{
		case VREF_AVCC:
			voltRef = 5000;
			break;
			
		case VREF_256:
			voltRef = 2560;
			break;
			
		case VREF_AREF:
			voltRef = AREF_VALUE;
			break;
			
		default:
			break;
	}
	
	/* Disable Adjusted Left Option */
	CLR_BIT(ADMUX, ADLAR);
	
	/* Disable Auto Triggering Option */
	CLR_BIT(ADCSRA, ADATE);
	
	/* ADC Enable */
	SET_BIT(ADCSRA, ADEN);
}

u16 ADC_Read(ADC_Channel_type ch)
{
	u16 adc;
	u8 adcl, adch;
	
	/* Select ADC Channel */
	SELECT_CH(ch);
	
	/* Start Conversion Operation */
	SET_BIT(ADCSRA, ADSC);
	
	/* Wait Until Conversion is Done */
	while(READ_PIN(ADCSRA, ADSC));
	
	/**
	 * Read and Return ADC
	 * We must read Low Byte first --> From Datasheet
	 */
	adcl = ADCL;
	adch = ADCH;
	adc = ((u16)adch << 8) | ((u16)adcl);
	
	return adc;
}

u16 ADC_ReadVolt(ADC_Channel_type ch)
{
	/* Voltage with respect to ADC voltage Reference (in mV) */
	u16 volt = (ADC_Read(ch)*(u32)voltRef)/1024;
	return volt;
}