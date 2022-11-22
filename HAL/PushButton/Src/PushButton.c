/*
 * PushButton.c
 *
 * Created: 11/11/2022 10:05:43 PM
 *  Author: Ahmed.Elsayed
 */ 

#include "../Inc/PushButton.h"



/********************************************
 * Description: Initialize The Button as an external interrupt (INT0) With the Rising Edge  
 * Input      : CarsLedColor , PedestrainsLedColor
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ********************************************/
void vidInit_pushButton(uint8 buttonPort, uint8 buttonPin)
{
	/*Set button pin to input*/
	Dio_vidSetPinDirection(buttonPort, buttonPin, Dio_Input);
	/*Enable Global Interrupt*/
	sei();
	/*Use rising edge for external interrupt*/
	Set_Bit(MCUCR, ISC00);
	Set_Bit(MCUCR, ISC01);
	/*Enable external INT0*/
	Set_Bit(GICR, INT0);
}

