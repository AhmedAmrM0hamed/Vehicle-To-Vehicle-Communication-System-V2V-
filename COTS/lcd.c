/*
 * lcd.c
 *
 *  Created on: Jun 8, 2023
 *      Author: Dhairya
 */


#include "gpio_driver.h"
#include "stm32f401xx.h"
#include "USART_driver.h"
#include <stdbool.h>			// boolean header file

GPIO_HANDLE pin;

/*
 * Port B
 */

#define D4	14
#define D5	15
#define D6	10
#define D7	11
#define RS	12
#define EN	13


void tim_init()
{
	TIM2_EN;
	TIM2->TIMx_PSC = 16000-1;
}

void delay(uint8_t x)
{
	TIM2->TIMx_ARR = x;
	TIM2->TIMx_CR1 |= (1 << 0);
	while(TIM2->TIMx_CR1 < x);
}

void lcd_cmd(uint8_t command)
{
	GPIO_WriteOutputPin(GPIOB, RS, 0);

	GPIO_WriteOutputPin(GPIOB, D4, (command >> 4) & 1);
	GPIO_WriteOutputPin(GPIOB, D5, (command >> 5) & 1);
	GPIO_WriteOutputPin(GPIOB, D6, (command >> 6) & 1);
	GPIO_WriteOutputPin(GPIOB, D7, (command >> 7) & 1);

	GPIO_WriteOutputPin(GPIOB, EN, 1);
	delay(2);
	GPIO_WriteOutputPin(GPIOB, EN, 0);
	delay(2);



	GPIO_WriteOutputPin(GPIOB, D4, command & 1);
	GPIO_WriteOutputPin(GPIOB, D5, (command >> 1) & 1);
	GPIO_WriteOutputPin(GPIOB, D6, (command >> 2) & 1);
	GPIO_WriteOutputPin(GPIOB, D7, (command >> 3) & 1);

	GPIO_WriteOutputPin(GPIOB, EN, 1);
	delay(2);
	GPIO_WriteOutputPin(GPIOB, EN, 0);
	delay(2);
}


void lcd_data(uint8_t data)
{
	GPIO_WriteOutputPin(GPIOB, RS, 1);

	GPIO_WriteOutputPin(GPIOB, D4, (data >> 4) & 1);
	GPIO_WriteOutputPin(GPIOB, D5, (data >> 5) & 1);
	GPIO_WriteOutputPin(GPIOB, D6, (data >> 6) & 1);
	GPIO_WriteOutputPin(GPIOB, D7, (data >> 7) & 1);

	GPIO_WriteOutputPin(GPIOB, EN, 1);
	delay(2);
	GPIO_WriteOutputPin(GPIOB, EN, 0);
	delay(2);



	GPIO_WriteOutputPin(GPIOB, D4, data & 1);
	GPIO_WriteOutputPin(GPIOB, D5, (data >> 1) & 1);
	GPIO_WriteOutputPin(GPIOB, D6, (data >> 2) & 1);
	GPIO_WriteOutputPin(GPIOB, D7, (data >> 3) & 1);

	GPIO_WriteOutputPin(GPIOB, EN, 1);
	delay(2);
	GPIO_WriteOutputPin(GPIOB, EN, 0);
	delay(2);
}

void lcd_string(char *str)
{
	while(*str)
	{
		lcd_data(*str++);
		delay(1);
	}
}

void lcd_init()
{
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x01);
	lcd_cmd(0x0E);
	lcd_cmd(0x06);
	lcd_cmd(0x80);
}


int main()
{
	GPIOB_PCLK_EN;

	pin.pGPIOx = GPIOB;
	pin.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	pin.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUT_PUSHPULL;
	pin.GPIO_PinConfig.GPIO_PinOutSpeed = GPIO_OUT_SPEED_HIGH;
	pin.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_OUT_PU;

	pin.GPIO_PinConfig.GPIO_PinNumber = D4;
	GPIO_Init(&pin);

	pin.GPIO_PinConfig.GPIO_PinNumber = D5;
	GPIO_Init(&pin);

	pin.GPIO_PinConfig.GPIO_PinNumber = D6;
	GPIO_Init(&pin);

	pin.GPIO_PinConfig.GPIO_PinNumber = D7;
	GPIO_Init(&pin);

	pin.GPIO_PinConfig.GPIO_PinNumber = RS;
	GPIO_Init(&pin);

	pin.GPIO_PinConfig.GPIO_PinNumber = EN;
	GPIO_Init(&pin);

	tim_init();

	lcd_init();
	//lcd_cmd(0x01);		// lcd clear

	lcd_string("Hi");
	while(1)
	{

	}
}


