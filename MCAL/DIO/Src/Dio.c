/*
 * Dio.c
 *
 * Created: 11/11/2022 9:53:55 PM
 *  Author: Ahmed.Elsayed
 */ 

#include "../Inc/Dio.h"

/********************************************
 * Description: Initializes Pin Direction as Input/Output
 * Input      : Port , Pin Number , Direction
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ********************************************/
void Dio_vidSetPinDirection(enuPortType Port, uint8 Pin, enuPortDirection Direction)
{
	switch(Port)
	{
		case Dio_PORTA:
		if (Direction == Dio_Input)
		{
			Clear_Bit(DDRA, Pin);
		}
		else if(Direction == Dio_Output)
		{
			Set_Bit(DDRA, Pin);
		}
		break;
		case Dio_PORTB:
		if (Direction == Dio_Input)
		{
			Clear_Bit(DDRB, Pin);
		}
		else if(Direction == Dio_Output)
		{
			Set_Bit(DDRB, Pin);
		}
		break;
		case Dio_PORTC:
		if (Direction == Dio_Input)
		{
			Clear_Bit(DDRC, Pin);
		}
		else if(Direction == Dio_Output)
		{
			Set_Bit(DDRC, Pin);
		}
		break;
		case Dio_PORTD:
		if (Direction == Dio_Input)
		{
			Clear_Bit(DDRD, Pin);
		}
		else if(Direction == Dio_Output)
		{
			Set_Bit(DDRD, Pin);
		}
		break;
	}
}

/********************************************
 * Description: Initializes The Direction for All Pins of The Port as Input/Output
 * Input      : Port , Direction
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ********************************************/
void Dio_vidSetPortDirection(enuPortType Port, enuPortDirection Direction)
{
	switch(Port)
	{
		case Dio_PORTA:
		if (Direction == Dio_Input)
		{
			DDRA = 0x00;
		}
		else if(Direction == Dio_Output)
		{
			DDRA = 0xFF;
		}
		break;
		case Dio_PORTB:
		if (Direction == Dio_Input)
		{
			DDRB = 0x00;
		}
		else if(Direction == Dio_Output)
		{
			DDRB = 0xFF;
		}

		break;
		case Dio_PORTC:
		if (Direction == Dio_Input)
		{
			DDRC = 0x00;
		}
		else if(Direction == Dio_Output)
		{
			DDRC = 0xFF;
		}

		break;
		case Dio_PORTD:
		if (Direction == Dio_Input)
		{
			DDRD = 0x00;
		}
		else if(Direction == Dio_Output)
		{
			DDRD = 0xFF;
		}
		break;

	}
}

/********************************************
 * Description: Write High/Low on The Pin
 * Input      : Port , Pin Number , State
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ********************************************/
void Dio_vidWritePin(enuPortType Port, uint8 Pin, enuPinState State)
{
	switch(Port)
	{
		case Dio_PORTA:
		if(State == Dio_High)
		{
			Set_Bit(PORTA, Pin);
		}
		else if(State == Dio_Low)
		{
			Clear_Bit(PORTA, Pin);
		}
		break;
		case Dio_PORTB:
		if(State == Dio_High)
		{
			Set_Bit(PORTB, Pin);
		}
		else if(State == Dio_Low)
		{
			Clear_Bit(PORTB, Pin);
		}
		break;
		case Dio_PORTC:
		if(State == Dio_High)
		{
			Set_Bit(PORTC, Pin);
		}
		else if(State == Dio_Low)
		{
			Clear_Bit(PORTC, Pin);
		}
		break;

		case Dio_PORTD:
		if(State == Dio_High)
		{
			Set_Bit(PORTD, Pin);
		}
		else if(State == Dio_Low)
		{
			Clear_Bit(PORTD, Pin);
		}
		break;
	}
}

/********************************************
 * Description: Write High/Low on All Pins of The Port
 * Input      : Port , Value
 * Output     : None
 * Author	  : Ahmed.Elsayed
 ********************************************/
void Dio_vidWritePort(enuPortType Port, uint8 Value)
{
	switch(Port)
	{
		case Dio_PORTA:
		PORTA = Value;
		break;
		case Dio_PORTB:
		PORTB = Value;
		break;
		case Dio_PORTC:
		PORTC = Value;
		break;
		case Dio_PORTD:
		PORTD = Value;
		break;
	}
}

/********************************************
 * Description: Read The Value of The Pin
 * Input      : Port , Pin Number
 * Output     : Value
 * Author	  : Ahmed.Elsayed
 ********************************************/
uint8 Dio_u8ReadPin(enuPortType Port, uint8 Pin)
{
	uint8 Result = 0;

	switch(Port)
	{
		case Dio_PORTA:
		if(Get_Bit(DDRA, Pin) == 1)
		{
			/*The required PIN is output*/
			Result = Get_Bit(PORTA, Pin);
		}
		else if(Get_Bit(DDRA, Pin) == 0)
		{
			/*The required PIN is input*/
			Result = Get_Bit(PINA, Pin);
		}
		break;
		case Dio_PORTB:
		if(Get_Bit(DDRB, Pin) == 1)
		{
			/*The required PIN is output*/
			Result = Get_Bit(PORTB, Pin);
		}
		else if(Get_Bit(DDRB, Pin) == 0)
		{
			/*The required PIN is input*/
			Result = Get_Bit(PINB, Pin);
		}
		break;
		case Dio_PORTC:
		if(Get_Bit(DDRC, Pin) == 1)
		{
			/*The required PIN is output*/
			Result = Get_Bit(PORTC, Pin);
		}
		else if(Get_Bit(DDRC, Pin) == 0)
		{
			/*The required PIN is input*/
			Result = Get_Bit(PINC, Pin);
		}
		break;
		case Dio_PORTD:
		if(Get_Bit(DDRD, Pin) == 1)
		{
			/*The required PIN is output*/
			Result = Get_Bit(PORTD, Pin);
		}
		else if(Get_Bit(DDRD, Pin) == 0)
		{
			/*The required PIN is input*/
			Result = Get_Bit(PIND, Pin);
		}
		break;
	}

	return Result;
}

/********************************************
 * Description: Read The Value of The Port
 * Input      : Port , Control
 * Output     : Value
 * Author	  : Ahmed.Elsayed
 ********************************************/
uint8 Dio_u8ReadPort(enuPortType Port, uint8 Control)
{
	uint8 Result = 0;

	switch(Port)
	{
		case Dio_PORTA:
		if(Control == 0)
		{
			Result = PINA;
		}
		else if(Control == 1)
		{
			Result = PORTA;
		}
		break;
		case Dio_PORTB:
		if(Control == 0)
		{
			Result = PINB;
		}
		else if(Control == 1)
		{
			Result = PORTB;
		}
		break;

		case Dio_PORTC:
		if(Control == 0)
		{
			Result = PINC;
		}
		else if(Control == 1)
		{
			Result = PORTC;
		}
		break;

		case Dio_PORTD:
		if(Control == 0)
		{
			Result = PIND;
		}
		else if(Control == 1)
		{
			Result = PORTD;
		}
		break;

	}
	return Result;
}
