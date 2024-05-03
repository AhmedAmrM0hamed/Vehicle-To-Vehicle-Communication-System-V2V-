/***********************************************************************************/
/**************		Auther	:	 FU_ES Team        	********************************/
/**************		SWC  	:	 MOTOR			   	********************************/
/**************		Date  	:	 12/8/2023         	********************************/
/**************		Version :	 V1            		********************************/
/***********************************************************************************/

/*	Includes	-------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------*/

/**
  * @brief : Motor Initialization Function -> 1- Initialize Timer 1 to generate PWM
  *										 ->	2- Start PWM on channel 1 & channel 2
  * @param None
  * @retval None
  */
void HMOTOR_voidInit 			(void)
{
	/*			Stop All Motors				*/
	HMOTOR_voidStop();
	/*		Timer 1 Initialization			*/
	MX_TIM1_Init ();
	/*	Initialize Timer 1 to generate PWM	*/
	HAL_TIM_PWM_Init (&htim1);
	/*	Start PWM generation at channel 1 & channel 2	*/
	HAL_TIM_PWM_Start (&htim1 , TIM_CHANNEL_1);
	HAL_TIM_PWM_Start (&htim1 , TIM_CHANNEL_2);

}

/*---------------------------------------------------------------------------------*/

/**
  * @brief : Motor Stop Function -> 1- Stop all the motors and stop generation of PWM
  * @param None
  * @retval None
  */

void HMOTOR_voidStop 			(void)
{
	/*			Stop All Motors				*/
	HAL_GPIO_WritePin(Motor1_GPIO_Port , Motor1_V1_Pin|Motor1_V2_Pin , GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Motor2_GPIO_Port , Motor2_V1_Pin|Motor2_V2_Pin , GPIO_PIN_RESET);
	/*	Stop generation of PWM	*/
	__HAL_TIM_SET_COMPARE(&htim1 , TIM_CHANNEL_1 , 0);
	__HAL_TIM_SET_COMPARE(&htim1 , TIM_CHANNEL_2 , 0);
}

/*---------------------------------------------------------------------------------*/

/**
  * @brief : This Function to set the speed of the motors 
  * @param Copy_uint16Speed : Motor speed -> Cpmpare match value
  * @retval None
  */

void HMOTOR_voidSetSpeed 		(uint16_t Copy_uint16Speed)
{
	__HAL_TIM_SET_COMPARE(&htim1 , TIM_CHANNEL_1 , Copy_uint16Speed);
    __HAL_TIM_SET_COMPARE(&htim1 , TIM_CHANNEL_2 , Copy_uint16Speed);
}

/*---------------------------------------------------------------------------------*/

/**
  * @brief : This Function to Move the car forward
  * @param Copy_uint16Speed : Motor speed -> Cpmpare match value
  * @retval None
  */

void HMOTOR_voidMoveForward 	(uint16_t Copy_uint16Speed)
{
	/*			Stop All Motors				*/
	HMOTOR_voidStop ();

	/*		Set Motor Speed		*/
	
	HMOTOR_voidSetSpeed (Copy_uint16Speed);
	
	/*	Set Motors Direction to move forward	*/
	HAL_GPIO_WritePin(Motor1_GPIO_Port , Motor1_V1_Pin , GPIO_PIN_SET);
	HAL_GPIO_WritePin(Motor2_GPIO_Port , Motor2_V1_Pin , GPIO_PIN_SET);
	HAL_GPIO_WritePin(Motor1_GPIO_Port , Motor1_V2_Pin , GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Motor2_GPIO_Port , Motor2_V2_Pin , GPIO_PIN_RESET);


}

/*---------------------------------------------------------------------------------*/

/**
  * @brief : This Function to Move the car backward
  * @param Copy_uint16Speed : Motor speed -> Cpmpare match value
  * @retval None
  */

void HMOTOR_voidMoveBackward 	(uint16_t Copy_uint16Speed)
{
	/*			Stop All Motors				*/
	HMOTOR_voidStop();

	/*		Set Motor Speed		*/
	
	HMOTOR_voidSetSpeed (Copy_uint16Speed);

	/*	Set Motors Direction to move backward	*/
	HAL_GPIO_WritePin(Motor1_GPIO_Port, Motor1_V1_Pin , GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Motor2_GPIO_Port, Motor2_V1_Pin , GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Motor1_GPIO_Port, Motor1_V2_Pin , GPIO_PIN_SET);
	HAL_GPIO_WritePin(Motor2_GPIO_Port, Motor2_V2_Pin , GPIO_PIN_SET);

}

/*---------------------------------------------------------------------------------*/

/**
  * @brief : This Function to Move the car Right
  * @param Copy_uint8SDirection : Direction of the car -> Right forward / Right backward
  * @retval None
  */

void HMOTOR_voidMoveRight 		(uint8_t Copy_uint8SDirection)
{
	/*			Stop All Motors				*/
	HMOTOR_voidStop();

	/*	Motor move to the right direction	*/
	__HAL_TIM_SET_COMPARE(&htim1 , TIM_CHANNEL_2 , MOTOR_SPEED_1);
	__HAL_TIM_SET_COMPARE(&htim1 , TIM_CHANNEL_1 , MOTOR_SPEED_0);

	switch (Copy_uint8SDirection)
	{
	case MOTOR_RIGHT_FORWAED :
								/*	Set Motors Direction to move forward	*/
								HAL_GPIO_WritePin(Motor1_GPIO_Port , Motor1_V1_Pin , GPIO_PIN_SET);
								HAL_GPIO_WritePin(Motor2_GPIO_Port , Motor2_V1_Pin , GPIO_PIN_SET);
								HAL_GPIO_WritePin(Motor1_GPIO_Port , Motor1_V2_Pin , GPIO_PIN_RESET);
								HAL_GPIO_WritePin(Motor2_GPIO_Port , Motor2_V2_Pin , GPIO_PIN_RESET);
								break ;

	case MOTOR_RIGHT_BACKWARD :
								/*	Set Motors Direction to move backward	*/
								HAL_GPIO_WritePin(Motor1_GPIO_Port , Motor1_V1_Pin , GPIO_PIN_RESET);
								HAL_GPIO_WritePin(Motor2_GPIO_Port , Motor2_V1_Pin , GPIO_PIN_RESET);
								HAL_GPIO_WritePin(Motor1_GPIO_Port , Motor1_V2_Pin , GPIO_PIN_SET);
								HAL_GPIO_WritePin(Motor2_GPIO_Port , Motor2_V2_Pin , GPIO_PIN_SET);
								break ;
	}

}

/*---------------------------------------------------------------------------------*/

/**
  * @brief : This Function to Move the car left
  * @param Copy_uint16Speed : Direction of the car -> left forward / left backward
  * @retval None
  */

void HMOTOR_voidMoveLeft 		(uint8_t Copy_uint8SDirection)
{
	/*			Stop All Motors				*/
	HMOTOR_voidStop();

	/*	Motor move to the left direction	*/
	__HAL_TIM_SET_COMPARE(&htim1 , TIM_CHANNEL_1 , MOTOR_SPEED_1);
	__HAL_TIM_SET_COMPARE(&htim1 , TIM_CHANNEL_2 , MOTOR_SPEED_0);

	switch (Copy_uint8SDirection)
	{
	case MOTOR_RIGHT_FORWAED :
								/*	Set Motors Direction to move forward	*/
								HAL_GPIO_WritePin(Motor1_GPIO_Port , Motor1_V1_Pin , GPIO_PIN_SET);
								HAL_GPIO_WritePin(Motor2_GPIO_Port , Motor2_V1_Pin , GPIO_PIN_SET);
								HAL_GPIO_WritePin(Motor1_GPIO_Port , Motor1_V2_Pin , GPIO_PIN_RESET);
								HAL_GPIO_WritePin(Motor2_GPIO_Port , Motor2_V2_Pin , GPIO_PIN_RESET);
								break ;

	case MOTOR_RIGHT_BACKWARD :
								/*	Set Motors Direction to move backward	*/
								HAL_GPIO_WritePin(Motor1_GPIO_Port , Motor1_V1_Pin , GPIO_PIN_RESET);
								HAL_GPIO_WritePin(Motor2_GPIO_Port , Motor2_V1_Pin , GPIO_PIN_RESET);
								HAL_GPIO_WritePin(Motor1_GPIO_Port , Motor1_V2_Pin , GPIO_PIN_SET);
								HAL_GPIO_WritePin(Motor2_GPIO_Port , Motor2_V2_Pin , GPIO_PIN_SET);
								break ;
	}

}
