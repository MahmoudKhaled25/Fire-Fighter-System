/*
 * Serive_App.c
 *
 * Created: 4/14/2024 10:30:33 PM
 *  Author: Mahmoud Khaled
 */ 

#include "Serive_App.h"

static u8 PassUpdateFlag, flag=1;
static u16 pressure, temperature;
static APP_SystemState_type system_state;

static void APP_SystemLock(void);
static void APP_PassChangeRequest(void);
static void exi_CallBack(void);

void APP_Init(void)
{
	DIO_INIT();
	ADC_Init(VREF_AVCC, ADC_SCALER_128);
	NVM_INIT();
	EXI_Init();
	LCD_INIT();
	KEYPAD_INIT();
	TEMP_FilterInit();
	EXI_SetCallBack(EX_INT1, exi_CallBack);
	EXI_Enable(EX_INT1);
	Timer0_SetInterruptTime_us(10000, TEMP_FilterRunnable);
	SEI();
	
	// Start with Latest System State
	system_state = NVM_READ(SYS_STATE_ADD);
}

void App_StartWindow(void)
{
	if (system_state!=FIRE_STATE)
	{
		LCD_SET_CURSOR(1, 3);
		LCD_WRITE_STRING("Fire Fighter");
		LCD_SET_CURSOR(2, 6);
		LCD_WRITE_STRING("System");
		_delay_ms(1500);
		LCD_CLR();
	}
	LCD_WRITE_STRING("Status: ");
}

void APP_StateAct(void)
{
	if (!PassUpdateFlag)
		LCD_SET_CURSOR(1, 9);
	switch(system_state)
	{
		case FINE_STATE:
		if (!PassUpdateFlag)
			LCD_WRITE_STRING("Fine");
		DIO_WritePin(YELLOW_LED, LOW);
		DIO_WritePin(RED_LED, LOW);
		DIO_WritePin(ALARM, LOW);
		DIO_WritePin(GREEN_LED, HIGH);
		break;
		
		case HEAT_STATE:
		if (!PassUpdateFlag)
			LCD_WRITE_STRING("Heat");
		DIO_WritePin(GREEN_LED, LOW);
		DIO_WritePin(RED_LED, LOW);
		DIO_WritePin(ALARM, LOW);
		DIO_WritePin(YELLOW_LED, HIGH);
		break;
		
		case FIRE_STATE:
		APP_SystemLock();
		break;
		
		default:
		break;
	}
}

void APP_StateUpadate(void)
{
	
	// ----- Critical section -----------------------
	CLI();
	temperature = TEMP_FilterGetter();
	pressure = sensor_ReadPressure_MPX4115();
	SEI();
	// ----------------------------------------------
	
	// Password Change 
	if (PassUpdateFlag)
		APP_PassChangeRequest();
	
	// Update System State
	if (temperature >= HEAT_TEMP)
	{
		if (pressure >= CRITICAL_SMOKE)
			system_state = FIRE_STATE;
		else
			system_state = HEAT_STATE;
	}
	else if (temperature <= FINE_TEMP)
		system_state = FINE_STATE;
	else {}
	
	// Store Latest System State
	NVM_WRITE(SYS_STATE_ADD, system_state);
}

static void APP_SystemLock(void)
{
	u8 wrong_pass_flag=WRONG_PASS, pass[PASS_LEN];
	DIO_WritePin(YELLOW_LED, LOW);
	DIO_WritePin(GREEN_LED, LOW);
	DIO_WritePin(RED_LED, HIGH);
	DIO_WritePin(ALARM, HIGH);
	LCD_CLR();
	LCD_WRITE_STRING("Status: ");
	LCD_SET_CURSOR(1, 9);
	LCD_WRITE_STRING("Fire");
	while (WRONG_PASS == wrong_pass_flag)
	{
		LCD_SET_CURSOR(2, 1);
		LCD_WRITE_STRING("                ");
		LCD_SET_CURSOR(2, 1);
		LCD_WRITE_STRING("Pass: ");
		LCD_SET_CURSOR(2, 7);
		APP_PassScan(pass);
		wrong_pass_flag = APP_PassMatch(pass);
		if (CORRECT_PASS == wrong_pass_flag)
		{
			LCD_SET_CURSOR(2, 1);
			LCD_WRITE_STRING("                ");
		}
		else
		{
			LCD_SET_CURSOR(2, 1);
			LCD_WRITE_STRING("                ");
			LCD_SET_CURSOR(2, 1);
			LCD_WRITE_STRING("Wrong Password");
			_delay_ms(1000);
		}
	}
	flag=1;
	PassUpdateFlag=0;
}

static void APP_PassChangeRequest(void)
{
	static u8 counter=0, pass[PASS_LEN]={}, local_flag=1;
	u8 key;
	
	// Verify old password
	if (1==local_flag)
	{
		if (flag)
		{
			LCD_CLR();
			LCD_WRITE_STRING("Enter Password:");
			LCD_SET_CURSOR(2, 1);
			flag=0;
			counter=0;
		}
		if (counter == PASS_LEN)
		{
			u8 check;
			check = APP_PassMatch(pass);
			if (check)
			{
				local_flag = 2;
			}
			else
			{
				LCD_CLR();
				LCD_WRITE_STRING("Wrong Password!");
				_delay_ms(1500);
			}
			flag=1;
		}
	}
	
	// Change password
	if (2==local_flag)
	{
		if (flag)
		{
			LCD_CLR();
			LCD_WRITE_STRING("New Password:");
			LCD_SET_CURSOR(2, 1);
			LCD_WRITE_STRING("        ");
			LCD_SET_CURSOR(2, 1);
			flag=0;
			counter=0;
		}
		if (counter == PASS_LEN)
			local_flag = 3;
	}
	
	// Scan password
	if (counter < PASS_LEN)
	{
		key = KEYPAD_GET_KEY();
		if (key!=NO_KEY)
		{
			LCD_WRITE_CHAR(key);
			_delay_ms(250);
			LCD_REMOVE_CHAR();
			LCD_WRITE_CHAR('*');
			pass[counter] = key - '0';
			counter++;
		}
	}
	
	// Change Password
	if (3==local_flag)
	{
		APP_PassChange(pass);
		PassUpdateFlag=0;
		local_flag=1;
		flag=1;
		counter=0;
		LCD_CLR();
		LCD_WRITE_STRING("Password Changed!");
		_delay_ms(1500);
		LCD_CLR();
		LCD_WRITE_STRING("Status: ");
		LCD_SET_CURSOR(1, 9);
	}
	
}

static void exi_CallBack(void)
{
	PassUpdateFlag = 1;
}