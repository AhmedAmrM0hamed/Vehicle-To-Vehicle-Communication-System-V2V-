/***********************************************************************************/
/**************		Author	:	 FU_ES Team        	********************************/
/**************		SWC  	:	 MOTOR			   	********************************/
/**************		Date  	:	 2/29/2023         	********************************/
/**************		Version :	 V1            		********************************/
/***********************************************************************************/

#include "App.h"

void CAR_voidMotion (uint8_t Copy_ReciviedData)
{
	switch (Copy_ReciviedData)
			{
			case USART_CAR_STOP 			:	HMOTOR_voidStop();
												break ;

			case USART_MOVE_FORWARD 		:	HMOTOR_voidMoveForward (CAR_SPEED);
												break ;

			case USART_MOVE_BACKWARD 		:	HMOTOR_voidMoveBackward (CAR_SPEED);
												break ;

			case USART_MOVE_RIGHT_FORWARD 	:	HMOTOR_voidMoveRight (MOTOR_RIGHT_FORWAED);
												break ;

			case USART_MOVE_RIGHT_BACKWARD 	:	HMOTOR_voidMoveRight (MOTOR_RIGHT_BACKWARD);
												break ;

			case USART_MOVE_LEFT_FORWARD 	:	HMOTOR_voidMoveLeft (MOTOR_LEFT_FORWAED);
												break ;

			case USART_MOVE_LEFT_BACKWARD 	:	HMOTOR_voidMoveLeft (MOTOR_RIGHT_BACKWARD);
												break ;

			case USART_CAR_SPEED_0 			:	CAR_SPEED = MOTOR_SPEED_0 ;
												HMOTOR_voidSetSpeed (CAR_SPEED);
												break ;

			case USART_CAR_SPEED_1 			:	CAR_SPEED = MOTOR_SPEED_1 ;
												HMOTOR_voidSetSpeed (CAR_SPEED);
												break ;

			case USART_CAR_SPEED_2 			:	CAR_SPEED = MOTOR_SPEED_2 ;
												HMOTOR_voidSetSpeed (CAR_SPEED);
												break ;

			case USART_CAR_SPEED_3 			:	CAR_SPEED = MOTOR_SPEED_3 ;
												HMOTOR_voidSetSpeed (CAR_SPEED);
												break ;

			case USART_CAR_SPEED_4 			:	CAR_SPEED = MOTOR_SPEED_4 ;
												HMOTOR_voidSetSpeed (CAR_SPEED);
												break ;

			}
}

