/*
 * Led.c
 *
 * Created: 11/11/2022 10:07:27 PM
 *  Author: Ahmed.Elsayed
 */ 
#include "../Inc/Led.h"

/********************************************
 * Description: Initializes Pins of Leds as Output 
 * Input      : None
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ********************************************/
void Led_Init_vi(void)
{
	Dio_vidSetPinDirection(CARS_RED_LED_PORT, CARS_RED_LED_PIN, Dio_Output);
	Dio_vidSetPinDirection(CARS_YELLOW_LED_PORT, CARS_YELLOW_LED_PIN, Dio_Output);
	Dio_vidSetPinDirection(CARS_GREEN_LED_PORT, CARS_GREEN_LED_PIN, Dio_Output);
	Dio_vidSetPinDirection(PEDESTRIANS_RED_LED_PORT, PEDESTRIANS_RED_LED_PIN, Dio_Output);
	Dio_vidSetPinDirection(PEDESTRIANS_YELLOW_LED_PORT, PEDESTRIANS_YELLOW_LED_PIN, Dio_Output);
	Dio_vidSetPinDirection(PEDESTRIANS_GREEN_LED_PORT, PEDESTRIANS_GREEN_LED_PIN, Dio_Output);
}

/********************************************
 * Description: Turn On The Led 
 * Input      : Led's Color
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ********************************************/
void Led_ON_vi(EN_LED_COLORS_t* LedColor)
{
	if(LedColor == CARS_RED)
	{
		Dio_vidWritePin(CARS_RED_LED_PORT, CARS_RED_LED_PIN, Dio_High);	
	}
	else if(LedColor == CARS_YELLOW)
	{
		Dio_vidWritePin(CARS_YELLOW_LED_PORT, CARS_YELLOW_LED_PIN, Dio_High);
	}
	else if(LedColor == CARS_GREEN)
	{
		Dio_vidWritePin(CARS_GREEN_LED_PORT, CARS_GREEN_LED_PIN, Dio_High);
	}		
	else if(LedColor == PEDESTRIANS_RED)
	{
		Dio_vidWritePin(PEDESTRIANS_RED_LED_PORT, PEDESTRIANS_RED_LED_PIN, Dio_High);
	}
	else if(LedColor == PEDESTRIANS_YELLOW)
	{
		Dio_vidWritePin(PEDESTRIANS_YELLOW_LED_PORT, PEDESTRIANS_YELLOW_LED_PIN, Dio_High);
	}
	else if(LedColor == PEDESTRIANS_GREEN)
	{
		Dio_vidWritePin(PEDESTRIANS_GREEN_LED_PORT, PEDESTRIANS_GREEN_LED_PIN, Dio_High);
	}	
}

/********************************************
 * Description: Turn Off The Led 
 * Input      : Led's Color
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ********************************************/
void Led_OFF_vi(EN_LED_COLORS_t* LedColor)
{
	if(LedColor == CARS_RED)
	{
		Dio_vidWritePin(CARS_RED_LED_PORT, CARS_RED_LED_PIN, Dio_Low);
	}
	else if(LedColor == CARS_YELLOW)
	{
		Dio_vidWritePin(CARS_YELLOW_LED_PORT, CARS_YELLOW_LED_PIN, Dio_Low);
	}
	else if(LedColor == CARS_GREEN)
	{
		Dio_vidWritePin(CARS_GREEN_LED_PORT, CARS_GREEN_LED_PIN, Dio_Low);
	}
	else if(LedColor == PEDESTRIANS_RED)
	{
		Dio_vidWritePin(PEDESTRIANS_RED_LED_PORT, PEDESTRIANS_RED_LED_PIN, Dio_Low);
	}
	else if(LedColor == PEDESTRIANS_YELLOW)
	{
		Dio_vidWritePin(PEDESTRIANS_YELLOW_LED_PORT, PEDESTRIANS_YELLOW_LED_PIN, Dio_Low);
	}
	else if(LedColor == PEDESTRIANS_GREEN)
	{
		Dio_vidWritePin(PEDESTRIANS_GREEN_LED_PORT, PEDESTRIANS_GREEN_LED_PIN, Dio_Low);
	}
}

/********************************************
 * Description: Blink The Led For 5 Sec
 * Input      : CarsLedColor , PedestrainsLedColor
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ********************************************/
void Led_Yellow_Blink_vi(EN_LED_COLORS_t* CarsLedColor, EN_LED_COLORS_t* PedestrainsLedColor)
{
	uint8 i;
	uint8 ToggleFlag = 0;
	TMR0_vidInit();
	for(i=0 ; i<5 ; i++)
	{
		TMR0_vidSetTimer(0x00);
		if(ToggleFlag == 0)
		{
			Led_ON_vi(CarsLedColor);
			Led_ON_vi(PedestrainsLedColor);
			ToggleFlag = 1;
		}
		else if(ToggleFlag == 1)
		{
			Led_OFF_vi(CarsLedColor);
			Led_OFF_vi(PedestrainsLedColor);
			ToggleFlag = 0;
		}
		/*Delay 1sec*/	
		/*Start Timer0 With Prescalar 1024*/
		TMR0_vidStartTimer(1024);	
		while (overflowCounter < NUMBER_OF_OVERFLOWS_TIM0_1SEC)
		{
			TMR0_vidWaitOverflowFlagTimer();
			overflowCounter++;
		}
		overflowCounter = 0;
		/*Timer0 stop*/
		TMR0_vidStopTimer();				
	}
	Led_OFF_vi(CarsLedColor);
	Led_OFF_vi(PedestrainsLedColor);
}

/********************************************
 * Description: Turn On The Led For 5 Sec
 * Input      : CarsLedColor , PedestrainsLedColor
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ********************************************/
void vidLed_ON_5Sec(EN_LED_COLORS_t* CarsLedColor, EN_LED_COLORS_t* PedestrainsLedColor)
{
		/*Set time for 5 second */
		TMR0_vidInit();
		TMR0_vidSetTimer(0x00);
		Led_ON_vi(CarsLedColor);
		Led_ON_vi(PedestrainsLedColor);
		TMR0_vidStartTimer(1024);
		while (overflowCounter < NUMBER_OF_OVERFLOWS_TIM0_5SEC)
		{
			TMR0_vidWaitOverflowFlagTimer();
			overflowCounter++;
		}
		overflowCounter = 0;
		/*Timer0 stop*/
		TMR0_vidStopTimer();
		Led_OFF_vi(CarsLedColor);
		Led_OFF_vi(PedestrainsLedColor);
}