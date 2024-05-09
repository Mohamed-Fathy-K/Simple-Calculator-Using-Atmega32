/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  HAL	             *******************/
/*******************    SWC:    CLCD             *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_


//you can choose EIGHT_BIT or FOUR_BIT
#define 	CLCD_MODE			EIGHT_BIT

////////////*CONTROL CONFIG*//////////////////

#define 	CLCD_u8RS_PORT		DIO_u8PORTA
#define 	CLCD_u8RS_PIN		DIO_u8PIN2

#define 	CLCD_u8RW_PORT		DIO_u8PORTA
#define 	CLCD_u8RW_PIN		DIO_u8PIN1

#define 	CLCD_u8EN_PORT		DIO_u8PORTA
#define 	CLCD_u8EN_PIN		DIO_u8PIN0

//////////////////////////////////////////////

///////////////DATA CONFIG/////////////////////

#define 	CLCD_u8DB7_PORT		DIO_u8PORTC
#define 	CLCD_u8DB7_PIN		DIO_u8PIN7

#define 	CLCD_u8DB6_PORT		DIO_u8PORTC
#define 	CLCD_u8DB6_PIN		DIO_u8PIN6

#define 	CLCD_u8DB5_PORT		DIO_u8PORTC
#define 	CLCD_u8DB5_PIN		DIO_u8PIN5

#define 	CLCD_u8DB4_PORT		DIO_u8PORTC
#define 	CLCD_u8DB4_PIN		DIO_u8PIN4

#define 	CLCD_u8DB3_PORT		DIO_u8PORTC
#define 	CLCD_u8DB3_PIN		DIO_u8PIN3

#define 	CLCD_u8DB2_PORT		DIO_u8PORTC
#define 	CLCD_u8DB2_PIN		DIO_u8PIN2

#define 	CLCD_u8DB1_PORT		DIO_u8PORTC
#define 	CLCD_u8DB1_PIN		DIO_u8PIN1

#define 	CLCD_u8DB0_PORT		DIO_u8PORTC
#define 	CLCD_u8DB0_PIN		DIO_u8PIN0

//////////////////////////////////////////////
#endif /* CLCD_CONFIG_H_ */
