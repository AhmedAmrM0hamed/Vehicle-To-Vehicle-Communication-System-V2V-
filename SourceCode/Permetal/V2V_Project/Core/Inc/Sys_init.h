/***********************************************************************************/
/**************		Author	:	 FU_ES Team        	********************************/
/**************		SWC  	:	 Sys_Init		   	********************************/
/**************		Date  	:	 2/15/2024         	********************************/
/**************		Version :	 V1            		********************************/
/***********************************************************************************/

#ifndef SYSTEM_INIT_H_
#define SYSTEM_INIT_H_

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_SPI1_Init(void);
void MX_TIM1_Init(void);
void MX_USART1_UART_Init(void);

#endif
