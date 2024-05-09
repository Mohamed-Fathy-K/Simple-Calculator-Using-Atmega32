/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  MCAL             *******************/
/*******************    SWC:    DIO              *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/errorStates.h"


#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


ES_t	DIO_enuInit(void)
{
	ES_t	Local_enuErrorState = ES_NOK;

	DDRA 	= CONC(DIO_PIN7_PORTA_DIRCTION,DIO_PIN6_PORTA_DIRCTION,DIO_PIN5_PORTA_DIRCTION,DIO_PIN4_PORTA_DIRCTION,DIO_PIN3_PORTA_DIRCTION,DIO_PIN2_PORTA_DIRCTION,DIO_PIN1_PORTA_DIRCTION,DIO_PIN0_PORTA_DIRCTION);
	DDRB 	= CONC(DIO_PIN7_PORTB_DIRCTION,DIO_PIN6_PORTB_DIRCTION,DIO_PIN5_PORTB_DIRCTION,DIO_PIN4_PORTB_DIRCTION,DIO_PIN3_PORTB_DIRCTION,DIO_PIN2_PORTB_DIRCTION,DIO_PIN1_PORTB_DIRCTION,DIO_PIN0_PORTB_DIRCTION);
	DDRC	= CONC(DIO_PIN7_PORTC_DIRCTION,DIO_PIN6_PORTC_DIRCTION,DIO_PIN5_PORTC_DIRCTION,DIO_PIN4_PORTC_DIRCTION,DIO_PIN3_PORTC_DIRCTION,DIO_PIN2_PORTC_DIRCTION,DIO_PIN1_PORTC_DIRCTION,DIO_PIN0_PORTC_DIRCTION);
	DDRD 	= CONC(DIO_PIN7_PORTD_DIRCTION,DIO_PIN6_PORTD_DIRCTION,DIO_PIN5_PORTD_DIRCTION,DIO_PIN4_PORTD_DIRCTION,DIO_PIN3_PORTD_DIRCTION,DIO_PIN2_PORTD_DIRCTION,DIO_PIN1_PORTD_DIRCTION,DIO_PIN0_PORTD_DIRCTION);

	PORTA 	= CONC(DIO_PIN7_PORTA_VALUE,DIO_PIN6_PORTA_VALUE,DIO_PIN5_PORTA_VALUE,DIO_PIN4_PORTA_VALUE,DIO_PIN3_PORTA_VALUE,DIO_PIN2_PORTA_VALUE,DIO_PIN1_PORTA_VALUE,DIO_PIN0_PORTA_VALUE);
	PORTB 	= CONC(DIO_PIN7_PORTB_VALUE,DIO_PIN6_PORTB_VALUE,DIO_PIN5_PORTB_VALUE,DIO_PIN4_PORTB_VALUE,DIO_PIN3_PORTB_VALUE,DIO_PIN2_PORTB_VALUE,DIO_PIN1_PORTB_VALUE,DIO_PIN0_PORTB_VALUE);
	PORTC 	= CONC(DIO_PIN7_PORTC_VALUE,DIO_PIN6_PORTC_VALUE,DIO_PIN5_PORTC_VALUE,DIO_PIN4_PORTC_VALUE,DIO_PIN3_PORTC_VALUE,DIO_PIN2_PORTC_VALUE,DIO_PIN1_PORTC_VALUE,DIO_PIN0_PORTC_VALUE);
	PORTD 	= CONC(DIO_PIN7_PORTD_VALUE,DIO_PIN6_PORTD_VALUE,DIO_PIN5_PORTD_VALUE,DIO_PIN4_PORTD_VALUE,DIO_PIN3_PORTD_VALUE,DIO_PIN2_PORTD_VALUE,DIO_PIN1_PORTD_VALUE,DIO_PIN0_PORTD_VALUE);

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}


ES_t	DIO_enuSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8Value)
{
	ES_t	Local_enuErrorState = ES_NOK;

	if(Copy_u8PortID <= DIO_PIN7)
	{
		switch(Copy_u8PortID)
		{
		case DIO_PORTA: DDRA = Copy_u8Value; break;
		case DIO_PORTB: DDRB = Copy_u8Value; break;
		case DIO_PORTC: DDRC = Copy_u8Value; break;
		case DIO_PORTD: DDRD = Copy_u8Value; break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t	DIO_enuSetPortValue(u8 Copy_u8PortID, u8 Copy_u8Value)
{
	ES_t	Local_enuErrorState = ES_NOK;

	if(Copy_u8PortID <= DIO_PIN7)
	{
		switch(Copy_u8PortID)
		{
		case DIO_PORTA: PORTA = Copy_u8Value; break;
		case DIO_PORTB: PORTB = Copy_u8Value; break;
		case DIO_PORTC: PORTC = Copy_u8Value; break;
		case DIO_PORTD: PORTD = Copy_u8Value; break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t	DIO_enuGetPortValue(u8 Copy_u8PortID, u8* Copy_pu8Value)
{
	ES_t	Local_enuErrorState = ES_NOK;

	if(Copy_u8PortID <= DIO_PIN7)
	{
		if(Copy_pu8Value != NULL)
		{
			switch(Copy_u8PortID)
			{
				case DIO_PORTA: *Copy_pu8Value = PINA; break;
				case DIO_PORTB: *Copy_pu8Value = PINB; break;
				case DIO_PORTC: *Copy_pu8Value = PINC; break;
				case DIO_PORTD: *Copy_pu8Value = PIND; break;
			}
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_NULL_POINTER;
		}

	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t	DIO_enuTogPortValue(u8 Copy_u8PortID)
{
	ES_t	Local_enuErrorState = ES_NOK;

	if(Copy_u8PortID <= DIO_PIN7)
	{
		switch(Copy_u8PortID)
		{
		case DIO_PORTA: PORTA = ~PORTA; break;
		case DIO_PORTB: PORTB = ~PORTB; break;
		case DIO_PORTC: PORTC = ~PORTC; break;
		case DIO_PORTD: PORTD = ~PORTD; break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}


ES_t	DIO_enuSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID, u8 Copy_u8Value)
{
	ES_t	Local_enuErrorState	= ES_NOK;

	if(Copy_u8PortID<= DIO_PORTD && Copy_u8PinID <= DIO_PIN7 && Copy_u8Value <= OUTPUT)
	{
		switch(Copy_u8PortID)
		{
		case DIO_PORTA : DDRA &= ~(1<<Copy_u8PinID); DDRA |= (Copy_u8Value<<Copy_u8PinID); break;
		case DIO_PORTB : DDRB &= ~(1<<Copy_u8PinID); DDRB |= (Copy_u8Value<<Copy_u8PinID); break;
		case DIO_PORTC : DDRC &= ~(1<<Copy_u8PinID); DDRC |= (Copy_u8Value<<Copy_u8PinID); break;
		case DIO_PORTD : DDRD &= ~(1<<Copy_u8PinID); DDRD |= (Copy_u8Value<<Copy_u8PinID); break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return	Local_enuErrorState;
}

ES_t	DIO_enuSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,  u8 Copy_u8Value)
{
	ES_t	Local_enuErrorState	= ES_NOK;

		if(Copy_u8PortID<= DIO_PORTD && Copy_u8PinID <= DIO_PIN7 && Copy_u8Value <= HIGH)
		{
			switch(Copy_u8PortID)
			{
			case DIO_PORTA : PORTA &= ~(1<<Copy_u8PinID); PORTA |= (Copy_u8Value<<Copy_u8PinID); break;
			case DIO_PORTB : PORTB &= ~(1<<Copy_u8PinID); PORTB |= (Copy_u8Value<<Copy_u8PinID); break;
			case DIO_PORTC : PORTC &= ~(1<<Copy_u8PinID); PORTC |= (Copy_u8Value<<Copy_u8PinID); break;
			case DIO_PORTD : PORTD &= ~(1<<Copy_u8PinID); PORTD |= (Copy_u8Value<<Copy_u8PinID); break;
			}
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

		return	Local_enuErrorState;
}

ES_t	DIO_enuGetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8* Copy_pu8Value)
{
	ES_t	Local_enuErrorState	= ES_NOK;
		if(Copy_pu8Value != NULL)
		{
			if(Copy_u8PortID<= DIO_PORTD && Copy_u8PinID <= DIO_PIN7)
			{
				switch(Copy_u8PortID)
				{
				case DIO_PORTA : *Copy_pu8Value = (PINA>>Copy_u8PinID) & 1;  break;
				case DIO_PORTB : *Copy_pu8Value = (PINB>>Copy_u8PinID) & 1;  break;
				case DIO_PORTC : *Copy_pu8Value = (PINC>>Copy_u8PinID) & 1;  break;
				case DIO_PORTD : *Copy_pu8Value = (PIND>>Copy_u8PinID) & 1;  break;
				}
				Local_enuErrorState = ES_OK;
			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

		return	Local_enuErrorState;
}

ES_t	DIO_enuTogPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
	ES_t Local_enuErrorStates = ES_NOK;

	if(Copy_u8PortID <= DIO_PORTD)
	{
		switch(Copy_u8PortID)
		{
			case	DIO_PORTA 	: PORTA ^=(1<<Copy_u8PinID); break;
			case	DIO_PORTB 	: PORTB ^=(1<<Copy_u8PinID); break;
			case	DIO_PORTC 	: PORTC ^=(1<<Copy_u8PinID); break;
			case	DIO_PORTD 	: PORTD ^=(1<<Copy_u8PinID); break;
		}


		Local_enuErrorStates = ES_OK;
	}
	else
	{
		Local_enuErrorStates = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorStates;
}


