/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  HAL              *******************/
/*******************    SWC:    KEYPAD           *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#ifndef		KPD_CONFIG_H_
#define 	KPD_CONFIG_H_

#include "DIO_interface.h"

#define 	KPD_PORT				DIO_PORTD

#define 	KPD_COLUMN0_PIN 		DIO_PIN4
#define 	KPD_COLUMN1_PIN 		DIO_PIN5
#define 	KPD_COLUMN2_PIN 		DIO_PIN6
#define 	KPD_COLUMN3_PIN 		DIO_PIN7

#define 	KPD_ROW0_PIN			DIO_PIN0
#define 	KPD_ROW1_PIN 			DIO_PIN1
#define 	KPD_ROW2_PIN 			DIO_PIN2
#define 	KPD_ROW3_PIN 			DIO_PIN3






#define 	KPD_NO_KEY_PRESSED		0xff

//#define 	KPD_ARR_VALUE {{1,2,3,4},{5,6,7,8},{9,1,2,3},{4,5,6,7}}

#define 	KPD_ARR_VALUE 	{											\
							{	'7'	,	'8'	,	'9'	,	'/'		},		\
							{	'4'	,	'5'	,	'6'	,	'X'		},		\
							{	'1'	,	'2'	,	'3'	,	'-'		},		\
							{	'O'	,	'0'	,	'='	,	'+'		},		\
							}


#endif
