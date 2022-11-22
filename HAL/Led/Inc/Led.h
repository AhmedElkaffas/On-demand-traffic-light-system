/*
 * Led.h
 *
 * Created: 11/11/2022 10:07:16 PM
 *  Author: Ahmed.Elsayed
 */ 


#ifndef LED_H_
#define LED_H_

#include "avr/interrupt.h"
#include "../../../Common/STD_Types.h"
#include "../../../MCAL/DIO/Inc/Dio.h"
#include "../../../MCAL/TIMER0/Inc/Timer0.h"
/*Led PORT*/
#define CARS_RED_LED_PORT Dio_PORTA
#define CARS_YELLOW_LED_PORT Dio_PORTA
#define CARS_GREEN_LED_PORT Dio_PORTA
#define PEDESTRIANS_RED_LED_PORT Dio_PORTA
#define PEDESTRIANS_YELLOW_LED_PORT Dio_PORTA
#define PEDESTRIANS_GREEN_LED_PORT Dio_PORTA
/*Led PIN*/
#define CARS_RED_LED_PIN PIN1
#define CARS_YELLOW_LED_PIN PIN2
#define CARS_GREEN_LED_PIN PIN3
#define PEDESTRIANS_RED_LED_PIN PIN5
#define PEDESTRIANS_YELLOW_LED_PIN PIN6
#define PEDESTRIANS_GREEN_LED_PIN PIN7

static 	uint32 overflowCounter = 0;

/*
Led Colors:
-CARS_GREEN -> 0,
-CARS_YELLOW -> 1,
-CARS_RED -> 2,
-PEDSTRIANS_GREEN -> 3,
-PEDSTRIANS_YELLOW -> 4,
-PEDSTRIANS_RED -> 5
*/
typedef enum
{
	CARS_GREEN,
	CARS_YELLOW,
	CARS_RED,
	PEDESTRIANS_GREEN,
	PEDESTRIANS_YELLOW,
	PEDESTRIANS_RED
}EN_LED_COLORS_t;

void Led_Init_vi(void);
void Led_ON_vi(EN_LED_COLORS_t* LedColor);
void Led_OFF_vi(EN_LED_COLORS_t* LedColor);
void vidLed_ON_5Sec(EN_LED_COLORS_t* CarsLedColor, EN_LED_COLORS_t* PedestrainsLedColor);
void Led_Yellow_Blink_vi(EN_LED_COLORS_t* CarsLedColor, EN_LED_COLORS_t* PedestrainsLedColor);

#endif /* LED_H_ */