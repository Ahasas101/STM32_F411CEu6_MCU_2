/*
 * In this program the interrupt based implementation of the generation of 10Hz signal by toggling the gpio is acheived
 *
 * for the interrupt based implementaions follow the steps:
 * 1. Start the timer with the API having IT
 * 2. Enable the irq and set the priority in the msp.c
 * 3. Search for the ISR from syscall.c
 * 4. Implement it by calling the HAL_TIM_IRQ_Handler
 * 5. in HAL_TIM_IRQ_Handler search for the callback of the interest
 * 6. Implement it in the main.c
 *
 */


#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <string.h>



void Error_Handler(void);
void GPIO_SWO(void);
void Clock_cnfg(uint8_t clock_freq);
void TIMER_Init(void);
void GPIO_LED(void);

TIM_HandleTypeDef timer10;

int main(void)
{

	HAL_Init();
	GPIO_SWO();
	GPIO_LED();
	TIMER_Init();
	// starting timer
	HAL_TIM_Base_Start_IT(&timer10);


}

void GPIO_SWO(void)
{
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitTypeDef gpio_swo;
	gpio_swo.Mode = GPIO_MODE_AF_PP;
	gpio_swo.Pin = GPIO_PIN_3;
	gpio_swo.Alternate = GPIO_AF0_SWJ;
	gpio_swo.Pull = GPIO_NOPULL;
	gpio_swo.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(GPIOB, &gpio_swo);
}



void Error_Handler(void)
{
	while(1);
}


void TIMER_Init(void)
{
	timer10.Instance = TIM10;
	timer10.Init.Prescaler = 24;
	timer10.Init.Period = 64000 - 1;
	if(HAL_TIM_Base_Init(&timer10) != HAL_OK) Error_Handler();
}

void GPIO_LED(void)
{
	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitTypeDef gpioled;
	gpioled.Mode = GPIO_MODE_OUTPUT_PP;
	gpioled.Pull = GPIO_NOPULL;
	gpioled.Pin = GPIO_PIN_13;
	HAL_GPIO_Init(GPIOC, &gpioled);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
}

