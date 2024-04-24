/*
 * sensors.c
 *
 * Created: 3/17/2024 3:08:32 AM
 *  Author: Mahmoud Khaled
 */ 

#include "Sensors.h"

u16 sensor_ReadTemp_LM35(void)
{
	/* Temperature from LM35 Sensor (in C*10) */
	u16 temperature = ADC_ReadVolt(SENSOR_LM35_CH);
	return temperature;
}

u16 sensor_ReadPressure_MPX4115(void)
{
	/* Temperature from MPX4115 Sensor (in kP*10) */
	u16 pressure = ((ADC_ReadVolt(SENSOR_MPX4115_CH) + 405)*10)/45;
	return pressure;
}

u16 sensor_ReadPressure_MPX4250(void)
{
	/* Temperature from MPX4250 Sensor (in kP*10) */
	u16 pressure = ADC_ReadVolt(SENSOR_MPX4250_CH)/2+100;
	return pressure;
}
