/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  MCAL             *******************/
/*******************    SWC:    DIO              *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7

#define DIO_PORTA		'A'
#define DIO_PORTB		'B'
#define DIO_PORTC		'C'
#define DIO_PORTD		'D'

#define DIO_SetPinLow		0
#define DIO_SetPinHigh		1

#define DIO_SetPortLow 		0
#define DIO_SetPortHigh		1

#include "STD_TYPES.h"
#include "BIT_MATH.h"

void	DIO_SetPinValue		(u8 CopyPort, u8 CopyPin, u8 CopyPinValue);
void	DIO_SetPortValue	(u8 CopyPort, u8 CopyPortValue);

u8		DIO_GetPinValue		(u8 CopyPort, u8 CopyPin);

#endif
