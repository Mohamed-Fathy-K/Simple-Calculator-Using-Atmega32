/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  HAL	             *******************/
/*******************    SWC:    CLCD             *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

ES_t	CLCD_enuInit(void);

ES_t	CLCD_enuSendCommand(u8 Copy_u8Command);

ES_t	CLCD_enuWriteChar(u8 Copy_u8Data);

ES_t	CLCD_enuWriteString(u8* Copy_pu8String);

ES_t	CLCD_enuClear(void);

void CLCD_voidWriteNumber(u32 Copy_u32Number);

void CLCD_voidSetCursor(u8 Copy_u8XPostion, u8 Copy_u8YPostion);
#endif /* CLCD_INTERFACE_H_ */
