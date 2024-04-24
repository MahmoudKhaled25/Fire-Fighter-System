/*
 * KEYPAD_cfg.h
 *
 * Created: 12/16/2023 9:29:14 PM
 *  Author: Mahmoud Khaled
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

/******************************************* Macros Section ******************************************/
#define  NO_KEY   'T'   // In case the user does not enter on any key


/******************************************** Mode Config *********************************************/
 
 // In case of pull up resistor	    >  (PULL_UP)    ,  OUTPUT_VALUE ---> 1   , INPUT_VALUE ---> 0 
 // In case of pull DOWN resistor   >  (PULL_DOWN)  ,  OUTPUT_VALUE ---> 0   , INPUT_VALUE ---> 1
 
 #define OUTPUT_VALUE  HIGH
 #define INPUT_VALUE   LOW
 
 /******************************************* Row & Col *********************************************/
 #define  ROW          4  // Number of rows
 #define  COL          3  // Number of cols





#endif /* KEYPAD_CFG_H_ */