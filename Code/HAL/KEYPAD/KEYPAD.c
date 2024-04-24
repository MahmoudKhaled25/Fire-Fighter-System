/*
 * KEYPAD.c
 *
 * Created: 12/16/2023 9:28:30 PM
 *  Author: Mahmoud Khaled
 */ 


/****************************************** Include Section ********************************************/
#define F_CPU 8E6
#include "util/delay.h"
#include "Utilities.h"
#include "DIO_Interface.h"
#include "KEYPAD_Interface.h"
#include "LCD_Interface.h"
#include "MemoryMap.h"

/****************************************** Variable Section ********************************************/
extern const u8 KEYPAD_KEYS[ROW][COL];
extern const DIO_Pin_type KEYPAD_OUTPUT [ROW];
extern const DIO_Pin_type KEYPAD_INPUT [COL];

/*************************************** Function Declartaion ******************************************/
void KEYPAD_INIT(void)
{
	for(u8 i = 0 ; i < ROW ; ++i)
	{
		DIO_WritePin(KEYPAD_OUTPUT[i] , OUTPUT_VALUE);
	}
}

u8 KEYPAD_GET_KEY(void)
{
	u8 key = NO_KEY;
	for(u8 i = 0 ; i < ROW ; ++i)
	{
		DIO_WritePin(KEYPAD_OUTPUT[i] , INPUT_VALUE);
		for(u8 j = 0 ; j < COL ; ++j)
		{
			if(DIO_ReadPin(KEYPAD_INPUT[j]) == INPUT_VALUE)
			{
				key = KEYPAD_KEYS[i][j];
				while(DIO_ReadPin(KEYPAD_INPUT[j]) == INPUT_VALUE);
			}

		}
		DIO_WritePin(KEYPAD_OUTPUT[i] , OUTPUT_VALUE);
	}
	return key;
}



