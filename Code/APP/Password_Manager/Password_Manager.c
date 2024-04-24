/*
 * Password_Manager.c
 *
 * Created: 4/13/2024 10:24:10 PM
 *  Author: Mahmoud Khaled
 */ 
#define F_CPU 8E6
#include "Password_Manager.h"
#include <util/delay.h>

void APP_PassChange(u8 pass[])
{
	u16 counter;
	for (counter=0; counter < PASS_LEN; counter++)
		NVM_WRITE(counter, pass[counter]);
}

u8 APP_PassMatch(u8 pass[])
{
	u16 counter; 
	u8 digit, res=CORRECT_PASS;
	for (counter=0; counter < PASS_LEN; counter++)
	{
		digit = NVM_READ(counter);
		if (digit!=pass[counter])
		{
			res=WRONG_PASS;
			break;
		}
	}
	return res;
}


void APP_PassScan(u8 pass[])
{
	u8 counter, key=NO_KEY; 
	for (counter=0; counter < PASS_LEN; counter++)
	{
		while(NO_KEY==key)
		{
			key = KEYPAD_GET_KEY();
		}
		pass[counter]=key-'0';
		key = NO_KEY;
		LCD_WRITE_NUM(pass[counter]);
		_delay_ms(250);
		LCD_REMOVE_CHAR();
		LCD_WRITE_CHAR('*');
	}
}
