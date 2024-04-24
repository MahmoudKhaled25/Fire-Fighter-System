/*
 * NVM.c
 *
 * Created: 1/4/2024 9:50:26 PM
 *  Author: Mahmoud Khaled
 */ 

/******************************** Include Section ********************************/
#include "MemoryMap.h"
#include "Utilities.h"
#include "NVM_Interface.h"

/**************************** Function Implementation ****************************/ 
void NVM_INIT(void)
{
	return;
}

void NVM_WRITE(u16 address , u8 data)
{
	/* Wait the previous until writing the data */
	while (READ_PIN(EECR,EEWE));
	
	/* Write the desired address and data */
	EEAR = address;
	EEDR = data;
	
	/* Make the EEPROM ready to write the data */
	SET_BIT(EECR,EEMWE);
	
	/* Make the EEPROM starting the operation */
	SET_BIT(EECR,EEWE);
}

u8 NVM_READ (u16 address)
{

	while (READ_PIN(EECR,EEWE));
	
	EEAR = address;
	
	SET_BIT(EECR,EERE);
	
	return EEDR;		
}
