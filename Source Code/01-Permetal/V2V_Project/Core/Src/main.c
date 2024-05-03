/***********************************************************************************/
/**************		Author	:	 FU_ES Team        	********************************/
/**************		SWC  	:	 Main			   	********************************/
/**************		Date  	:	 12/8/2023         	********************************/
/**************		Version :	 V1            		********************************/
/***********************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "Sys_init.h"
#include "Motor.h"
#include "App.h"

uint8_t USRT_Recived_Data = 255 ;
uint8_t SPI_Recived_Data = 255 ;

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim1;

UART_HandleTypeDef huart1;



uint16_t x = MOTOR_SPEED_1 ;


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	HAL_UART_Receive_IT(&huart1, &USRT_Recived_Data, 1);

	static uint8_t counter = 0 ;
	if (counter == 0 )
	{
		for (int i=0 ; i<1000 ; i++)
		{
			for (int j=0 ; j<=100 ; j++)
			{
				asm("NOP");
			}
		}
		counter = 1 ;
	}
	if (huart->Instance == USART1)
	{
		HAL_UART_Transmit(&huart1, &USRT_Recived_Data, 1, 50);
		/*	Set the car motion	*/
		CAR_voidMotion (USRT_Recived_Data);
	}

}

void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
	if (hspi->Instance == SPI1)
	{
		HAL_SPI_Receive_IT(&hspi1 , &SPI_Recived_Data , 1);
		CAR_voidMotion (SPI_Recived_Data);
	}
}


/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	MX_SPI1_Init();
	MX_USART1_UART_Init();
	HMOTOR_voidInit();
	/* USER CODE BEGIN 2 */
	HAL_UART_Receive_IT(&huart1, &USRT_Recived_Data, 1);
	HAL_SPI_Receive_IT(&hspi1, &SPI_Recived_Data, 1);



	while (1)
	{

	}
	/* USER CODE END 3 */
}


/* USER CODE BEGIN 4 */

/* USER CODE END 4 */



#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
