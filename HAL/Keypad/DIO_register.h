/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  MCAL             *******************/
/*******************    SWC:    DIO              *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

/////////////////////Group A//////////////////////////

#define 	PORTA		*((volatile u8*) 0x3B)
#define 	PINA		*((volatile u8*) 0x39)


//////////////////////////////////////////////////////

/////////////////////Group B//////////////////////////

#define 	PORTB		*((volatile u8*) 0x38)
#define 	PINB		*((volatile u8*) 0x36)

//////////////////////////////////////////////////////

/////////////////////Group C//////////////////////////

#define 	PORTC		*((volatile u8*) 0x35)
#define 	PINC		*((volatile u8*) 0x33)

//////////////////////////////////////////////////////

/////////////////////Group D//////////////////////////

#define 	PORTD		*((volatile u8*) 0x32)
#define 	PIND		*((volatile u8*) 0x30)

//////////////////////////////////////////////////////

#endif
