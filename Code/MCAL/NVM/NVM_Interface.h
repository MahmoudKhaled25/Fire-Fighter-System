/*
 * NVM_Interface.h
 *
 * Created: 1/4/2024 9:51:32 PM
 *  Author: Mahmoud Khaled
 */ 


#ifndef NVM_INTERFACE_H_
#define NVM_INTERFACE_H_

/******************************** Include Section *********************************/
#include "StdTypes.h"
#include "MemoryMap.h"

/********************************* Macros Section ********************************/
#define EERIE 3
#define EEMWE 2
#define EEWE  1
#define EERE  0

/***************************** Function Declaration ******************************/

void NVM_INIT (void);
void NVM_WRITE(u16 address , u8 data);
u8   NVM_READ (u16 address);




#endif /* NVM_INTERFACE_H_ */