/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  HAL	             *******************/
/*******************    SWC:    CLCD             *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/
#include <util/delay.h>

#include "STD_TYPES.h"
#include "errorStates.h"

#include "DIO_interface.h"

#include "CLCD_private.h"
#include "CLCD_config.h"

#include "CLCD_interface.h"




ES_t	CLCD_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Counter = 0;

	if(DIO_enuSetPinDirection(CLCD_u8RS_PORT, CLCD_u8RS_PIN, DIO_u8OUTPUT) == ES_OK) Local_u8Counter++;
	if(DIO_enuSetPinDirection(CLCD_u8RW_PORT, CLCD_u8RW_PIN, DIO_u8OUTPUT) == ES_OK) Local_u8Counter++;
	if(DIO_enuSetPinDirection(CLCD_u8EN_PORT, CLCD_u8EN_PIN, DIO_u8OUTPUT) == ES_OK) Local_u8Counter++;


	if(DIO_enuSetPinDirection(CLCD_u8DB7_PORT, CLCD_u8DB7_PIN, DIO_u8OUTPUT) == ES_OK) Local_u8Counter++;
	if(DIO_enuSetPinDirection(CLCD_u8DB6_PORT, CLCD_u8DB6_PIN, DIO_u8OUTPUT) == ES_OK) Local_u8Counter++;
	if(DIO_enuSetPinDirection(CLCD_u8DB5_PORT, CLCD_u8DB5_PIN, DIO_u8OUTPUT) == ES_OK) Local_u8Counter++;
	if(DIO_enuSetPinDirection(CLCD_u8DB4_PORT, CLCD_u8DB4_PIN, DIO_u8OUTPUT) == ES_OK) Local_u8Counter++;
	if(DIO_enuSetPinDirection(CLCD_u8DB3_PORT, CLCD_u8DB3_PIN, DIO_u8OUTPUT) == ES_OK) Local_u8Counter++;
	if(DIO_enuSetPinDirection(CLCD_u8DB2_PORT, CLCD_u8DB2_PIN, DIO_u8OUTPUT) == ES_OK) Local_u8Counter++;
	if(DIO_enuSetPinDirection(CLCD_u8DB1_PORT, CLCD_u8DB1_PIN, DIO_u8OUTPUT) == ES_OK) Local_u8Counter++;
	if(DIO_enuSetPinDirection(CLCD_u8DB0_PORT, CLCD_u8DB0_PIN, DIO_u8OUTPUT) == ES_OK) Local_u8Counter++;



	_delay_ms(35);	// Wait for more than 30ms
	if(CLCD_enuSendCommand(0b00111000) == ES_OK) Local_u8Counter++;	 	//Function Set
	_delay_ms(1);	// Wait for more than 39 microS
	if(CLCD_enuSendCommand(0b00001111) == ES_OK) Local_u8Counter++;		//Display ON/OFF
	_delay_ms(1);	// Wait for more than 39 microS
	if(CLCD_enuSendCommand(0b00000001) == ES_OK) Local_u8Counter++;		//Display Clear
	_delay_ms(2);	// Wait for more than 1.53ms
	if(CLCD_enuSendCommand(0b00000000) == ES_OK) Local_u8Counter++;

	if(Local_u8Counter == 15)
	{
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NOK;
	}
	return	 Local_enuErrorState;

}


ES_t	CLCD_enuSendCommand(u8 Copy_u8Command)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Counter = 0;


	if(DIO_enuSetPinValue(CLCD_u8RS_PORT, CLCD_u8RS_PIN, DIO_u8LOW) == ES_OK) Local_u8Counter++;
	if(DIO_enuSetPinValue(CLCD_u8RW_PORT, CLCD_u8RW_PIN, DIO_u8LOW) == ES_OK) Local_u8Counter++;
	if(CLCD_enuSendDataPinsData(Copy_u8Command) 					== ES_OK) Local_u8Counter++;

	/*Send enable pulse*/
	if(DIO_enuSetPinValue(CLCD_u8EN_PORT,CLCD_u8EN_PIN,DIO_u8HIGH) 	== ES_OK) Local_u8Counter++;
	if(DIO_enuSetPinValue(CLCD_u8EN_PORT,CLCD_u8EN_PIN,DIO_u8LOW)	== ES_OK) Local_u8Counter++;



	if(Local_u8Counter == 4)
	{
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NOK;
	}

	return	 Local_enuErrorState;

}


ES_t	CLCD_enuWriteChar(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Counter = 0;


	if(DIO_enuSetPinValue(CLCD_u8RS_PORT, CLCD_u8RS_PIN, DIO_u8HIGH) == ES_OK) Local_u8Counter++;
	if(DIO_enuSetPinValue(CLCD_u8RW_PORT, CLCD_u8RW_PIN, DIO_u8LOW)  == ES_OK) Local_u8Counter++;
	if(CLCD_enuSendDataPinsData(Copy_u8Data) 						 == ES_OK) Local_u8Counter++;

	/*Send enable pulse*/
	if(DIO_enuSetPinValue(CLCD_u8EN_PORT,CLCD_u8EN_PIN,DIO_u8HIGH) 	== ES_OK) Local_u8Counter++;
	if(DIO_enuSetPinValue(CLCD_u8EN_PORT,CLCD_u8EN_PIN,DIO_u8LOW)	== ES_OK) Local_u8Counter++;



	if(Local_u8Counter == 5)
	{
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NOK;
	}

//	DIO_enuSetPinValue(CLCD_u8RS_PORT, CLCD_u8RS_PIN, DIO_u8HIGH);
//	DIO_enuSetPinValue(CLCD_u8RW_PORT, CLCD_u8RW_PIN, DIO_u8LOW);
//
//	DIO_enuSetPortValue(DIO_u8PORTA, Copy_u8Data);

//	/*Set RS pin to high for data*/
//	DIO_enuSetPinValue(CLCD_u8RS_PORT, CLCD_u8RS_PIN, DIO_u8HIGH);
//
//	/*Set RW pin to low for write*/
//	DIO_enuSetPinValue(CLCD_u8RW_PORT, CLCD_u8RW_PIN, DIO_u8LOW);
//
//	/*Set command to data pins*/
//	CLCD_enuSendDataPinsData(Copy_u8Data) ;
//
//	/*Send enable pulse*/
//	DIO_enuSetPinValue(CLCD_u8EN_PORT,CLCD_u8EN_PIN,DIO_u8HIGH);
//	_delay_ms(2);
//	DIO_enuSetPinValue(CLCD_u8EN_PORT,CLCD_u8EN_PIN,DIO_u8LOW);

	return	 Local_enuErrorState;

}


ES_t 	CLCD_enuSendDataPinsData(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

	typedef	struct
	{
		u8 Local_u8DB7ErrorState :3;
		u8 Local_u8DB6ErrorState :3;
		u8 Local_u8DB5ErrorState :3;
		u8 Local_u8DB4ErrorState :3;
#if	CLCD_MODE == EIGHT_BIT
		u8 Local_u8DB3ErrorState :3;
		u8 Local_u8DB2ErrorState :3;
		u8 Local_u8DB1ErrorState :3;
		u8 Local_u8DB0ErrorState :3;
#elif CLCD_MODE == FOUR_BIT

#else

#error	CLCD_MODE OUT OF RANGE!!

#endif

		}ErrorStates;


	ErrorStates Local_strErrorStates;

	Local_strErrorStates.Local_u8DB7ErrorState =	DIO_enuSetPinValue(CLCD_u8DB7_PORT, CLCD_u8DB7_PIN, ((Copy_u8Data >> 7) & 1));
	Local_strErrorStates.Local_u8DB6ErrorState =	DIO_enuSetPinValue(CLCD_u8DB6_PORT, CLCD_u8DB6_PIN, ((Copy_u8Data >> 6) & 1));
	Local_strErrorStates.Local_u8DB5ErrorState =	DIO_enuSetPinValue(CLCD_u8DB5_PORT, CLCD_u8DB5_PIN, ((Copy_u8Data >> 5) & 1));
	Local_strErrorStates.Local_u8DB4ErrorState =	DIO_enuSetPinValue(CLCD_u8DB4_PORT, CLCD_u8DB4_PIN, ((Copy_u8Data >> 4) & 1));
	Local_strErrorStates.Local_u8DB3ErrorState =	DIO_enuSetPinValue(CLCD_u8DB3_PORT, CLCD_u8DB3_PIN, ((Copy_u8Data >> 3) & 1));
	Local_strErrorStates.Local_u8DB2ErrorState =	DIO_enuSetPinValue(CLCD_u8DB2_PORT, CLCD_u8DB2_PIN, ((Copy_u8Data >> 2) & 1));
	Local_strErrorStates.Local_u8DB1ErrorState =	DIO_enuSetPinValue(CLCD_u8DB1_PORT, CLCD_u8DB1_PIN, ((Copy_u8Data >> 1) & 1));
	Local_strErrorStates.Local_u8DB0ErrorState =	DIO_enuSetPinValue(CLCD_u8DB0_PORT, CLCD_u8DB0_PIN, ((Copy_u8Data >> 0) & 1));




	if(
		Local_strErrorStates.Local_u8DB7ErrorState == ES_OK &&
		Local_strErrorStates.Local_u8DB6ErrorState == ES_OK &&
		Local_strErrorStates.Local_u8DB5ErrorState == ES_OK &&
		Local_strErrorStates.Local_u8DB4ErrorState == ES_OK &&
		Local_strErrorStates.Local_u8DB3ErrorState == ES_OK &&
		Local_strErrorStates.Local_u8DB2ErrorState == ES_OK &&
		Local_strErrorStates.Local_u8DB1ErrorState == ES_OK &&
		Local_strErrorStates.Local_u8DB0ErrorState == ES_OK
		)
	{
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NOK;
	}

	return	 Local_enuErrorState;
}


ES_t	CLCD_enuWriteString(u8 Copy_pu8String[])
{
	ES_t Local_enuErrorState = ES_NOK;

	for(u8 Local_u8Iterator = 0 ; Copy_pu8String[Local_u8Iterator] != '\0'; Local_u8Iterator++)
	{
		CLCD_enuWriteChar(Copy_pu8String[Local_u8Iterator]);
	}

	return	 Local_enuErrorState;

}


ES_t	CLCD_enuClear(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState  = CLCD_enuSendCommand(0b00000001);

	return	 Local_enuErrorState;

}

void CLCD_voidWriteNumber(u32 Copy_u32Number)
{
	u8 Local_u8temp = 0, Local_u8Counter = 0;
	char Local_arrStr[20];

	if(Copy_u32Number == 0)
	{
		CLCD_enuWriteChar('0');
		return;
	}
	while(Copy_u32Number!=0)
	{
		Local_u8temp = Copy_u32Number%10;
		Copy_u32Number/=10;
		Local_arrStr[Local_u8Counter++] = Local_u8temp+'0';
	}
	while(Local_u8Counter--)
	{
		CLCD_enuWriteChar(Local_arrStr[Local_u8Counter]);
	}
}



void CLCD_voidSetCursor(u8 Copy_u8XPostion, u8 Copy_u8YPostion)
{
	u8 Local_u8Address=0;
	if(Copy_u8YPostion == 0)
	{
		/*location is at first line*/
		Local_u8Address = Copy_u8XPostion;
	}
	else if (Copy_u8YPostion == 1)
	{
		/*location is at second line*/
		Local_u8Address = Copy_u8XPostion + 0x40;
	}
	/*Set bit number 7 for set DDRAM address command then send the command*/
	CLCD_enuSendCommand(Local_u8Address + 128);  // For Set The Cursor At The Second Row
}

