/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  HAL              *******************/
/*******************    SWC:    KEYPAD           *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#include "../Keypad/KPD_config.h"
#include "../Keypad/KPD_interface.h"
#include "../Keypad/KPD_private.h"
#include "DIO_interface.h"


u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey = KPD_NO_KEY_PRESSED, Local_u8ColumnCounter, Local_u8RowCounter, Local_u8PressedKeyState;
	static u8 Local_u8KPDArr[KPD_ROW_LENGTH][KPD_COLUMN_LENGTH] = KPD_ARR_VALUE;
	static u8 Local_u8KPDColumnArr[KPD_COLUMN_LENGTH] = {KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	static u8 Local_u8KPDRowArr[KPD_ROW_LENGTH] = {KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	for (Local_u8ColumnCounter = 0 ; Local_u8ColumnCounter < KPD_COLUMN_LENGTH ; Local_u8ColumnCounter++)
		{
			/*Activate the current column*/
			DIO_SetPinValue(KPD_PORT, Local_u8KPDColumnArr[Local_u8ColumnCounter], DIO_SetPinLow);

			for (Local_u8RowCounter = 0 ; Local_u8RowCounter <  KPD_ROW_LENGTH ; Local_u8RowCounter++)
				{
					/*read the current row */
					Local_u8PressedKeyState = DIO_GetPinValue(KPD_PORT, Local_u8KPDRowArr[Local_u8RowCounter]);

					/*check if the key is pressed*/
					if(Local_u8PressedKeyState == DIO_SetPinLow)
					{
						Local_u8PressedKey = Local_u8KPDArr[Local_u8RowCounter][Local_u8ColumnCounter];

						/*Polling (busy waiting) until the key is released*/
						while(Local_u8PressedKeyState == DIO_SetPinLow)
						{
							Local_u8PressedKeyState = DIO_GetPinValue(KPD_PORT, Local_u8KPDRowArr[Local_u8RowCounter]);
						}

						return Local_u8PressedKey;
					}
				}

			DIO_SetPinValue(KPD_PORT, Local_u8KPDColumnArr[Local_u8ColumnCounter], DIO_SetPinHigh);
		}

	return Local_u8PressedKey;

}
