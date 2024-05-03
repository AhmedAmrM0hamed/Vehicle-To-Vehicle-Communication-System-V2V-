/***********************************************************************************/
/**************		Author	:	 FU_ES Team        	********************************/
/**************		SWC  	:	 MOTOR			   	********************************/
/**************		Date  	:	 12/8/2023         	********************************/
/**************		Version :	 V1            		********************************/
/***********************************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_

/* 	Private defines 	-----------------------------------------------------------*/

#define Motor1_GPIO_Port 	GPIOA
#define Motor1_V1_Pin 		GPIO_PIN_10
#define Motor1_V2_Pin 		GPIO_PIN_11

#define Motor2_GPIO_Port 	GPIOB
#define Motor2_V1_Pin 		GPIO_PIN_13
#define Motor2_V2_Pin 		GPIO_PIN_14

/*********************************************************************************/


/*Macros for Car Type ---------------------------------------------------------*/
#define	CAR_PRIMARY   0 /***************/
#define	CAR_SECONDARY 1 /***************/
/***************************************/
/*Macros for configuration-------------*/
#define CAR_TYPE CAR_PRIMARY /**********/
/**********************************************************************************/


/*Enum for Motor Speeds ---------------------------------------------------------*/

typedef enum {
	MOTOR_SPEED_0 = 0   ,
	MOTOR_SPEED_1 = 500 ,
	MOTOR_SPEED_2 = 700 ,
	MOTOR_SPEED_3 = 800 ,
	MOTOR_SPEED_4 = 1000
}Motor_Speed;

/*Enum for Motor Directions ---------------------------------------------------------*/

typedef enum {
	MOTOR_RIGHT_FORWAED  ,
	MOTOR_RIGHT_BACKWARD ,
	MOTOR_LEFT_FORWAED   ,
	MOTOR_LEFT_BACKWARD
}Motor_Direction;


/*Helpers Functions Prototypes -------------------------------------------------*/
void MX_TIM1_Init(void);
void Error_Handler(void);

/*Functions Prototypes ---------------------------------------------------------*/
void HMOTOR_voidInit 			(void);
void HMOTOR_voidStop 			(void);
void HMOTOR_voidSetSpeed 		(uint16_t Copy_uint16Speed);
void HMOTOR_voidMoveForward 	(uint16_t Copy_uint16Speed);
void HMOTOR_voidMoveBackward 	(uint16_t Copy_uint16Speed);
void HMOTOR_voidMoveRight 		(uint8_t Copy_uint8SDirection);
void HMOTOR_voidMoveLeft 		(uint8_t Copy_uint8SDirection);



#endif /* MOTOR_H_ */
