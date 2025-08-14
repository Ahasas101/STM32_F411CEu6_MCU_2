/*
 *In this exercise we are using input capture mode of the timer
 *steps--> 1. config the timer using TIM_HandleTypeDef
 *steps--> 2. Config the channel
 *steps--> 3. use the HAL_TIM_IC_ConfigChannel
 *steps--> 4. configure the gpio for the timer channel in msp.c
 *steps--> 5. Enable the interrupt in IT.c and call the hal_tim_irqHanler
 *steps--> 6. look for the proper callback in the irq handler
 *steps--> 7. Implement callback i.e HAL_TIM_IC_CaptureCallback here in main.c
 *steps-->
 */
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <string.h>

void Error_Handler(void);
void GPIO_SWO(void);

void TIMER_Init(void);
void LSE_Init(void);
void SysClk_config(void);

TIM_HandleTypeDef timer2;

uint8_t count = 1;
uint32_t capture[2] = {0};
uint8_t is_capture_done = 0;

int main(void)
{
	HAL_Init();
	GPIO_SWO();
	LSE_Init();
	SysClk_config();
	TIMER_Init();
	printf("Hello \n");

	// Start the timer
	if (HAL_TIM_IC_Start_IT(&timer2, TIM_CHANNEL_1) != HAL_OK) Error_Handler();
	uint32_t difference = 0;
	double counter_time_period = 0;
	double counter_freq;
	double signal_time_period = 0;
	double signal_freq = 0;
	while(1)
	{
		if(is_capture_done == 1)
		{
			if(capture[1] > capture[0])
			{
				difference = capture[1] - capture[0];
			}
			else
			{
				difference = (0xFFFFFFFF - capture[0]) + capture[1];
			}

			counter_freq = (HAL_RCC_GetPCLK1Freq() * 1) / (timer2.Init.Prescaler + 1);
			counter_time_period = 1.0 / counter_freq;
			signal_time_period = difference * counter_time_period;
			signal_freq = 1.0 / signal_time_period;
			printf("pclk1 = %lu\n", HAL_RCC_GetPCLK1Freq());
			printf("%f \n",signal_freq);
			is_capture_done = 0;
		}
	}



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
	timer2.Instance = TIM2;
	timer2.Init.CounterMode = TIM_COUNTERMODE_UP;
	timer2.Init.Period = 0xFFFFFFFF;
	timer2.Init.Prescaler = 1;
	if(HAL_TIM_IC_Init(&timer2) != HAL_OK) Error_Handler();

	TIM_IC_InitTypeDef timer2IC;

	timer2IC.ICFilter = 1;
	timer2IC.ICPolarity = TIM_ICPOLARITY_RISING;
	timer2IC.ICPrescaler = TIM_ICPSC_DIV1;
	timer2IC.ICSelection = TIM_ICSELECTION_DIRECTTI;

	if(HAL_TIM_IC_ConfigChannel(&timer2, &timer2IC, TIM_CHANNEL_1) != HAL_OK) Error_Handler();

}

void LSE_Init(void)
{
	RCC_OscInitTypeDef lse;
	lse.OscillatorType = RCC_OSCILLATORTYPE_LSE | RCC_OSCILLATORTYPE_HSE;// Hse is configured here as it is used as sys
	// clk here
	lse.LSEState = RCC_LSE_ON;
	lse.HSEState = RCC_HSE_ON;
	lse.PLL.PLLState = RCC_PLL_NONE;
	if(HAL_RCC_OscConfig(&lse) != HAL_OK) Error_Handler();

	HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_LSE, RCC_MCODIV_1);

}

void SysClk_config(void)
{
	RCC_ClkInitTypeDef clk;
	clk.ClockType = RCC_CLOCKTYPE_SYSCLK;
	clk.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
	HAL_RCC_ClockConfig(&clk, FLASH_ACR_LATENCY_0WS);
	__HAL_RCC_HSI_DISABLE();// always disable hsi after making hse as clock source not before that

}


void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(is_capture_done == 0)
	{
		if(count == 1)
		{
			capture[0] = __HAL_TIM_GET_COMPARE(htim, TIM_CHANNEL_1);
			count ++;
		}
		else if (count == 2)
		{
			capture[1] = __HAL_TIM_GET_COMPARE(htim, TIM_CHANNEL_1);
			is_capture_done = 1;
			count = 1;
		}
	}
}

