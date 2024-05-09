/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  MCAL             *******************/
/*******************    SWC:    DIO              *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/


#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_register.h"




void	DIO_SetPinValue		(u8 CopyPort, u8 CopyPin, u8 CopyPinValue)
{
	if(CopyPin <= 7)
	{
		switch(CopyPinValue)
		{
		case	DIO_SetPinLow  :
			switch(CopyPort)
			{
			case 'A'	:	CLR_BIT(PORTA,CopyPin);		break;
			case 'B'	:	CLR_BIT(PORTB,CopyPin);		break;
			case 'C'	:	CLR_BIT(PORTC,CopyPin);		break;
			case 'D'	:	CLR_BIT(PORTD,CopyPin);		break;
			}
			break;
		case	DIO_SetPinHigh :
			switch(CopyPort)
			{
			case 'A'	:	SET_BIT(PORTA,CopyPin);		break;
			case 'B'	:	SET_BIT(PORTB,CopyPin);		break;
			case 'C'	:	SET_BIT(PORTC,CopyPin);		break;
			case 'D'	:	SET_BIT(PORTD,CopyPin);		break;
			}
			break;
		}
	}
}

void	DIO_SetPortValue	(u8 CopyPort, u8 CopyPortValue)
{
	switch(CopyPort)
	{
	case 'A'	:	PORTA = CopyPortValue;	break;
	case 'B'	:	PORTB = CopyPortValue;	break;
	case 'C'	:	PORTC = CopyPortValue;	break;
	case 'D'	:	PORTD = CopyPortValue;	break;
	}
}

u8		DIO_GetPinValue		(u8 CopyPort, u8 CopyPin)
{
	switch (CopyPort)
	{
		if(CopyPin <= 7)
		{
		case 'A':	return GET_BIT(PINA,CopyPin);	break;
		case 'B':	return GET_BIT(PINB,CopyPin);	break;
		case 'C':	return GET_BIT(PINC,CopyPin);	break;
		case 'D':	return GET_BIT(PIND,CopyPin);	break;
		}
	}
	return 0xff;
}
