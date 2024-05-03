/***********************************************************************************/
/**************		Author	:	 FU_ES Team        	********************************/
/**************		SWC  	:	 APP			   	********************************/
/**************		Date  	:	 2/29/2023         	********************************/
/**************		Version :	 V1            		********************************/
/***********************************************************************************/

#ifndef APPLICATION_H_
#define APPLICATION_H_

/*	Enum for the received data from USART	*/
typedef enum {
	USART_CAR_STOP = '0'		,
	USART_MOVE_FORWARD 			,
	USART_MOVE_BACKWARD 		,
	USART_MOVE_LEFT_FORWARD 	,
	// USART_MOVE_RIGHT_BACKWARD 	,
	USART_MOVE_RIGHT_FORWARD 	,
	// USART_MOVE_LEFT_BACKWARD 	,
	// USART_CAR_SPEED_0 			,
	USART_CAR_SPEED_1 			,
	USART_CAR_SPEED_2 			,
	USART_CAR_SPEED_3 			,
	USART_CAR_SPEED_4

}USART_DATA_RECEIVED;

/*	Enum for the received data from SPI

typedef enum {
	USART_CAR_STOP = 0x00		,
	USART_MOVE_FORWARD 			,
	USART_MOVE_BACKWARD 		,
	USART_MOVE_RIGHT_FORWARD 	,
	USART_MOVE_RIGHT_BACKWARD 	,
	USART_MOVE_LEFT_FORWARD 	,
	USART_MOVE_LEFT_BACKWARD 	,
	USART_CAR_SPEED_0 			,
	USART_CAR_SPEED_1 			,
	USART_CAR_SPEED_2 			,
	USART_CAR_SPEED_3 			,
	USART_CAR_SPEED_4

}SPI_DATA_RECEIVED;

*/

/*	Functions Prototypes	*/
void CAR_voidMotion (uint8_t Copy_ReciviedData);

#endif
