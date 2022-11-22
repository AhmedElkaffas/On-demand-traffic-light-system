/*
 * On-demand Traffic light.c
 *
 * Created: 11/11/2022 9:45:23 PM
 * Author : Ahmed.Elsayed
 */ 

#include <avr/io.h>
#include "Application/Inc/App.h"



int main(void)
{
    /* Initialize Leds */
	Led_Init_vi();
	/* Initialize PushButton as INT0 */
	vidInit_pushButton(PUSHBUTTON_PORT, PUSHBUTTON_PIN);
    while (1) 
    {
		vidTrafficLights();
    }
}

