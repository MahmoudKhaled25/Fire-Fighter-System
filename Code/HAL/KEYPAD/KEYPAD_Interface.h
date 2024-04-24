/*
 * KEYPAD_Interface.h
 *
 * Created: 12/16/2023 9:28:47 PM
 *  Author: Mahmoud Khaled
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_


/****************************************** Include Section ********************************************/
#include "StdTypes.h"
#include "KEYPAD_cfg.h"

/*************************************** Function Declartaion ******************************************/
void KEYPAD_INIT(void);
u8 KEYPAD_GET_KEY(void);






#endif /* KEYPAD_INTERFACE_H_ */