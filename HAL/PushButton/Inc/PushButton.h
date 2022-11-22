/*
 * PushButton.h
 *
 * Created: 11/11/2022 10:05:29 PM
 *  Author: Ahmed.Elsayed
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_

#include "../../../MCAL/DIO/Inc/Dio.h"
#include "avr/interrupt.h"

#define PUSHBUTTON_PORT Dio_PORTD
#define PUSHBUTTON_PIN PIN2

void vidInit_pushButton(uint8 buttonPort, uint8 buttonPin);


#endif /* PUSHBUTTON_H_ */