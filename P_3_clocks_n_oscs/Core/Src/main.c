#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <string.h>


void Error_Handler(void);
void GPIO_SWO(void);


int main(void)
{

	HAL_Init();
	GPIO_SWO();
	RCC_OscInitTypeDef osc_init;
	RCC_ClkInitTypeDef clk_init;
	memset(&osc_init, 0, sizeof(osc_init));
	osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	osc_init.HSEState = RCC_HSE_ON;
	if(HAL_RCC_OscConfig(&osc_init) != HAL_OK)
	{
		Error_Handler();
	}

	clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
	clk_init.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | \
						RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
	clk_init.APB1CLKDivider = RCC_HCLK_DIV2;
	clk_init.APB2CLKDivider = RCC_HCLK_DIV2;
	if(	HAL_RCC_ClockConfig(&clk_init, FLASH_ACR_LATENCY_0WS) != HAL_OK)
	{
		Error_Handler();
	}
	__HAL_RCC_HSI_DISABLE();

	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

	printf("Hello\n");

	printf("Sysclk freq  = %lu\n", HAL_RCC_GetSysClockFreq());
	printf("pclk1 freq = %lu\n", HAL_RCC_GetPCLK1Freq());
	printf("pclk2 freq = %lu\n", HAL_RCC_GetPCLK2Freq());
	printf("hclk freq = %lu\n", HAL_RCC_GetHCLKFreq());

while(1);

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


