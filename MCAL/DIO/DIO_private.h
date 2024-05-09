/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  MCAL             *******************/
/*******************    SWC:    DIO              *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#ifndef		DIO_PRIVATE_H_
#define		DIO_PRIVATE_H_


#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)			0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)					CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)

#define INPUT		0
#define OUTPUT		1

#define HIGH		1
#define LOW			0
#define FLOAT		0
#define PULLUP		1


#define DIO_PORTA		0
#define DIO_PORTB		1
#define DIO_PORTC		2
#define DIO_PORTD		3

#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7


/////////////////////Group A//////////////////////////

#define 	DDRA		*((u8*) 0x3A)
#define 	PORTA		*((u8*) 0x3B)
#define 	PINA		*((volatile u8*) 0x39)

//////////////////////////////////////////////////////

/////////////////////Group B//////////////////////////

#define 	DDRB		*((u8*) 0x37)
#define 	PORTB		*((u8*) 0x38)
#define 	PINB		*((volatile u8*) 0x36)

//////////////////////////////////////////////////////

/////////////////////Group C//////////////////////////

#define 	DDRC		*((u8*) 0x34)
#define 	PORTC		*((u8*) 0x35)
#define 	PINC		*((volatile u8*) 0x33)

//////////////////////////////////////////////////////

/////////////////////Group D//////////////////////////
#define 	DDRD		*((u8*) 0x31)
#define 	PORTD		*((u8*) 0x32)
#define 	PIND		*((volatile u8*) 0x30)

//////////////////////////////////////////////////////


//#define 	DDRA		*((volatile u8*) 0x3A)
//#define 	DDRB		*((volatile u8*) 0x37)
//#define 	DDRC		*((volatile u8*) 0x34)
//#define 	DDRD		*((volatile u8*) 0x31)
//
//#define 	PORTA		*((volatile u8*) 0x3B)
//#define 	PORTB		*((volatile u8*) 0x38)
//#define 	PORTC		*((volatile u8*) 0x35)
//#define 	PORTD		*((volatile u8*) 0x32)


#endif
