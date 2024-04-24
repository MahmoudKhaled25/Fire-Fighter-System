/*
 * ADC_Interface.h
 *
 * Created: 12/18/2023 10:13:40 PM
 *  Author: Mahmoud Khaled
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*************************************** Include Section *******************************/
#include "ADC_Cfg.h"
#include "MemoryMap.h"
#include "Utilities.h"
#include "StdTypes.h"
/*************************************** Macros Section *******************************/

/**
 * @brief: Macro to select ADC prescaler
 *		- Clear ADC prescaler bits
 *		- Set ADC prescaler bits according to PS
 */	
#define SELECT_PS(PS)  ADCSRA &= 0xF8;\
					   ADCSRA |= ((PS) & 0x07)

/**
 * @brief: Macro to select ADC reference voltage
 *		- Clear ADC reference voltage bits
 *		- Set ADC reference voltage bits according to VREF
 */	
#define SELECT_VREF(VREF)   ADMUX &= 0x3F;\
							ADMUX |= (((VREF) << 6) & 0xC0)

/**
 * @brief: Macro to select ADC channel
 *		- Clear ADC channel selection bits
 *		- Set ADC channel selection bits according to CH
 */				
#define SELECT_CH(CH)   ADMUX &= 0xE0;\
						ADMUX |= ((CH) & 0x1F)

/*************************************** Types Section ********************************/

// Enumeration for ADC channels
typedef enum {
	CH_0 = 0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
	}ADC_Channel_type;

// Enumeration for ADC reference voltage
typedef enum {
	VREF_AREF = 0,
	VREF_AVCC,
	VREF_256 = 3
	}ADC_Vref_type;

// Enumeration for ADC prescaler
typedef enum {
	ADC_SCALER_2 = 1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128
	}ADC_Prescaler_type;

/************************************** Function declaration **************************/

/**
 * @brief Initialize ADC module with given reference voltage and prescaler.
 * 
 * @param vref: Reference voltage selection (VREF_AREF, VREF_AVCC, VREF_256).
 * @param prescaler: ADC prescaler selection (ADC_SCALER_2, ADC_SCALER_4, ...).
 */
void ADC_Init(ADC_Vref_type vref, ADC_Prescaler_type prescaler);

/**
 * @brief Read ADC value from specified channel.
 * 
 * @param ch: ADC channel selection (CH_0, CH_1, ...).
 * @return ADC value read from the specified channel.
 */
u16  ADC_Read(ADC_Channel_type ch);

/**
 * @brief Read voltage value from specified channel (in mV).
 * 
 * @param ch: ADC channel selection (CH_0, CH_1, ...).
 * @return Voltage value read from the specified channel.
 */
u16 ADC_ReadVolt(ADC_Channel_type ch);
#endif /* ADC_INTERFACE_H_ */