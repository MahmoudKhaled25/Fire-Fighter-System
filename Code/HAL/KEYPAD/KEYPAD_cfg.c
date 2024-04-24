/*
 * KEYPAD_cfg.c
 *
 * Created: 12/16/2023 9:30:10 PM
 *  Author: Mahmoud Khaled
 */ 

#include "KEYPAD_cfg.h"
#include "StdTypes.h"
#include "DIO_Interface.h"

#if ROW==4 && COL==4
const u8 KEYPAD_KEYS[ROW][COL]=
{
	{'7','8','9','f'},
	{'4','5','6','e'},
	{'1','2','3','a'},
	{'c','0','=','b'}
	
};
#elif ROW==4 && COL==3
const u8 KEYPAD_KEYS[ROW][COL]=
{
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'},
	{'*','0','#'}
	
};
#endif


 const DIO_Pin_type KEYPAD_OUTPUT [ROW] = 
{
									    PINB4,
									    PINB5,
									    PINB6,
									    PINB7
};

const DIO_Pin_type KEYPAD_INPUT [COL] =
{
										PINB1,
										PINB2,
										PINB3
};