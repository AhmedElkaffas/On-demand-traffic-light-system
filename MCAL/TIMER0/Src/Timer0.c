/*
 * Timer0.c
 *
 * Created: 11/11/2022 10:01:20 PM
 *  Author: Ahmed.Elsayed
 */ 


#include "../Inc/Timer0.h"

#if TMR0_MODULE_MODE == 0
#include "../../DIO/Inc/Dio.h"
#endif


/********************************************
 * Description: Initializes Timer 0 Module
 * Input      : None
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ********************************************/
void TMR0_vidInit(void)
{
#if TMR0_MODULE_MODE == 0
	/*Configure Timer Mode (Normal Mode)*/
	Clear_Bit(TCCR0, 3);
	Clear_Bit(TCCR0, 6);

	/*Configure Compare Match Mode(OC0 is PORTB)*/
	Clear_Bit(TCCR0, 4);
	Clear_Bit(TCCR0, 5);
#elif TMR0_MODULE_MODE == 1
	/*Configure Timer Mode (CTC Mode)*/
	Set_Bit(TCCR0, 3);
	Clear_Bit(TCCR0, 6);

	/*Configure Compare Match Mode(OC0 is PORTB)*/
	Clear_Bit(TCCR0, 4);
	Clear_Bit(TCCR0, 5);
#elif TMR0_MODULE_MODE == 2
	/*Configure Timer Mode (FastPWM)*/
	Set_Bit(TCCR0, 3);
	Set_Bit(TCCR0, 6);

	/*Configure PB3 as Output*/
	Dio_vidSetPinDirection(Dio_PORTB, 3, Dio_Output);
	#if TMR0_PWM_INVRTED == 0
		/*Configure Compare Match Mode(Non-Inverted)*/
		Clear_Bit(TCCR0, 4);
		Set_Bit(TCCR0, 5);
	#elif TMR0_PWM_INVRTED == 1
		/*Configure Compare Match Mode(Inverted)*/
		Set_Bit(TCCR0, 4);
		Set_Bit(TCCR0, 5);
	#endif
#endif

	
#if TMR0_OVF_ENABLED == 0
	/*Clear TMR0 Over-Flow Interrupt Flag*/
	Clear_Bit(TIFR, 0);
	/*Enable TMR0 Over-Flow Interrupt*/
	Set_Bit(TIMSK, 0);
#endif

#if TMR0_OVF_ENABLED == 1
	/*Clear TMR0 Over-Flow Interrupt Flag*/
	Clear_Bit(TIFR, 1);
	/*Enable TMR0 Over-Flow Interrupt*/
	Set_Bit(TIMSK, 1);
#endif

}

/********************************************
 * Description: Updates Timer0 Register
 * Input      : Register Value
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ********************************************/
void TMR0_vidSetTimer(uint8 Value)
{
	TCNT0 = Value;
}


/********************************************
 * Description: Gets Timer0 Register
 * Input      : None
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ********************************************/
uint8 TMR0_u8GetTimer(void)
{
	return TCNT0;
}

/********************************************
 * Description: Start Timer0 with pre_scalar value
 * Input      : pre_scalar
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ********************************************/
void TMR0_vidStartTimer(uint16 preScalar)
{
	if(preScalar == 0)
	{
		Set_Bit(TCCR0, CS00);
	}
	else if(preScalar == 8)
	{
		Set_Bit(TCCR0, CS01);
	}
	else if(preScalar == 64)
	{
		Set_Bit(TCCR0, CS00);
		Set_Bit(TCCR0, CS01);
	}
	else if(preScalar == 256)
	{
		Set_Bit(TCCR0, CS02);
	}
	else if(preScalar == 1024)
	{
		Set_Bit(TCCR0, CS00);
		Set_Bit(TCCR0, CS02);
	}				
}

/********************************************
 * Description: Stop Timer0
 * Input      : None
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ********************************************/
void TMR0_vidStopTimer(void)
{
	TCCR0 = 0x00;
}

/********************************************
 * Description: Wait Overflow Flag For Timer0 and Clear it
 * Input      : None
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ********************************************/
void TMR0_vidWaitOverflowFlagTimer(void)
{
	while (Get_Bit(TIFR, 0) == 0);
	Clear_Bit(TIFR, 0);	
}
#if TMR0_MODULE_MODE != 0
/***************************************************
 * Description: Updates the Timer0 Compare Register
 * Input      : None
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ***************************************************/
void TMR0_vidSetCompareValue(uint8 Value)
{
	OCR0 = Value;
}
#endif
