/*
 * Filter.c
 *
 * Created: 4/9/2024 4:08:09 AM
 *  Author: Mahmoud Khlaed
 */ 

#include "Filter.h"

volatile static u16 Unfiltered_Reads[10], filteredRead;
volatile static u32 tempSum;

void TEMP_FilterInit(void)
{
	u8 i;
	for (i = 0; i < 10; i++)
	{
		Unfiltered_Reads[i] = sensor_ReadTemp_LM35();
		tempSum+=Unfiltered_Reads[i];
	}
}

void TEMP_FilterRunnable(void)  // Short Execution Time
{
	static u8 counter=0;
	
	if (10==counter)
		counter=0;
	tempSum -= Unfiltered_Reads[counter];				// 1) Subtract Oldest Read
	Unfiltered_Reads[counter] = sensor_ReadTemp_LM35(); // 2) Take a New read
	tempSum += Unfiltered_Reads[counter];				// 3) Add the New Read
	filteredRead = (u16)(tempSum/10);
	counter++;
}

u16  TEMP_FilterGetter(void)  // No Time
{
	return filteredRead;
}