/*
 * Password_Manager.h
 *
 * Created: 4/13/2024 10:23:52 PM
 *  Author: Mahmoud Khaled
 */ 


#ifndef PASSWORD_MANAGER_H_
#define PASSWORD_MANAGER_H_

/*********************************************** Include Section *****************************************/
#include "NVM_Interface.h"
#include "LCD_Interface.h"
#include "KEYPAD_Interface.h"

/********************************************* Macros Section ********************************************/
#define PASS_LEN     8
#define WRONG_PASS   0
#define CORRECT_PASS 1

/******************************************** Declaration Section *****************************************/
/**
 * @brief Change the password stored in EEPROM memory.
 *
 * @param pass An array containing the new password to be stored in EEPROM.
 */
void APP_PassChange(u8 pass[]);

/**
 * @brief Compare the given password with the password stored in EEPROM memory.
 *
 * @param  pass An array containing the password to be checked.
 * @return Returns 1 if the given password matches the password stored in EEPROM memory, 
 *         otherwise returns 0.
 */
u8 APP_PassMatch(u8 pass[]);

/**
 * @brief Take a password and store it to array
 *
 */
void APP_PassScan(u8 pass[]);

#endif /* PASSWORD_MANAGER_H_ */