/*
 * GccApplication1.c
 *
 * Created: 12/2/2023 1:00:25 AM
 * Author : Mahmoud Khaled
 */ 

/*********************************************** Include Section *****************************************/
#include "Serive_App.h"

int main(void)
{
	APP_Init();
	App_StartWindow();

    while (1) 
    {			
		APP_StateAct();
		APP_StateUpadate();
	}
}	