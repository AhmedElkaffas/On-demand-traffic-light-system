/*
 * App.c
 *
 * Created: 11/12/2022 8:40:58 PM
 *  Author: Ahmed.Elsayed
 */ 

#include "../Inc/App.h"


/********************************************
 * Description: Initialize The Traffic lights system 
 * Input      : None
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ********************************************/
void vidTrafficLights(void)
{
	checkFlag = 1;
	vidLed_ON_5Sec(CARS_GREEN, PEDESTRIANS_RED);
	checkFlag = 0;
	Led_Yellow_Blink_vi(CARS_YELLOW, PEDESTRIANS_YELLOW);	
	vidLed_ON_5Sec(CARS_RED, PEDESTRIANS_GREEN);
}


/********************************************
 * Description: Allow for the pedestrian to pass 
 * Author	  : Ahmed.Elsayed
 ********************************************/
ISR(INT0_vect)
{
	if (checkFlag == 1)
	{
		Led_OFF_vi(CARS_GREEN);
		Led_OFF_vi(PEDESTRIANS_RED);
		overflowCounter = 0;
		/*Timer0 stop*/
		TMR0_vidStopTimer();
		Clear_Bit(TIFR, 0);
		Led_Yellow_Blink_vi(CARS_YELLOW, PEDESTRIANS_YELLOW);
		vidLed_ON_5Sec(CARS_RED, PEDESTRIANS_GREEN);
		TMR0_vidInit();
		TMR0_vidSetTimer(0x00);
		Led_ON_vi(CARS_GREEN);
		Led_ON_vi(PEDESTRIANS_RED);
		TMR0_vidStartTimer(1024);
	}
}