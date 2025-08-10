#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <string.h>

#define SYS_CLOCK_FREQ_50MHz		1
#define SYS_CLOCK_FREQ_75MHz		2
#define SYS_CLOCK_FREQ_100MHz		3

void Error_Handler(void);
void GPIO_SWO(void);
void Clock_cnfg(uint8_t clock_freq);

int main(void)
{

	HAL_Init();
	GPIO_SWO();
	Clock_cnfg(SYS_CLOCK_FREQ_50MHz);
	printf("SysClk Freq = %lu\n", HAL_RCC_GetSysClockFreq());
	printf("Hclk Freq = %lu\n", HAL_RCC_GetHCLKFreq());

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

void Clock_cnfg(uint8_t clock_freq)
{
	RCC_OscInitTypeDef osc_init;
	RCC_ClkInitTypeDef clk_init;

	osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	osc_init.HSEState = RCC_HSE_ON;
	osc_init.HSIState = RCC_HSI_OFF;


	osc_init.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	osc_init.PLL.PLLState = RCC_PLL_ON;
	osc_init.PLL.PLLM = 25;
	osc_init.PLL.PLLP = 2;


	switch(clock_freq)
	{
		case SYS_CLOCK_FREQ_50MHz:
		{
			osc_init.PLL.PLLN = 100;
			if (HAL_RCC_OscConfig(&osc_init) != HAL_OK) Error_Handler();

			clk_init.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | \
								 RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
			clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
			clk_init.AHBCLKDivider = RCC_SYSCLK_DIV2;
			clk_init.APB1CLKDivider = RCC_HCLK_DIV2;
			clk_init.APB2CLKDivider = RCC_HCLK_DIV2;
			if (HAL_RCC_ClockConfig(&clk_init, FLASH_ACR_LATENCY_0WS) != HAL_OK) Error_Handler();
			break;
		}
		case SYS_CLOCK_FREQ_75MHz:
		{
			osc_init.PLL.PLLN = 150;
			if (HAL_RCC_OscConfig(&osc_init) != HAL_OK) Error_Handler();

			clk_init.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | \
								 RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
			clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
			clk_init.AHBCLKDivider = RCC_SYSCLK_DIV2;
			clk_init.APB1CLKDivider = RCC_HCLK_DIV2;
			clk_init.APB2CLKDivider = RCC_HCLK_DIV2;
			if (HAL_RCC_ClockConfig(&clk_init, FLASH_ACR_LATENCY_1WS) != HAL_OK) Error_Handler();
			break;
		}
		case SYS_CLOCK_FREQ_100MHz:
		{
			osc_init.PLL.PLLN = 200;
			if (HAL_RCC_OscConfig(&osc_init) != HAL_OK) Error_Handler();

			clk_init.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | \
								 RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
			clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
			clk_init.AHBCLKDivider = RCC_SYSCLK_DIV2;
			clk_init.APB1CLKDivider = RCC_HCLK_DIV2;
			clk_init.APB2CLKDivider = RCC_HCLK_DIV2;
			if (HAL_RCC_ClockConfig(&clk_init, FLASH_ACR_LATENCY_1WS) != HAL_OK) Error_Handler();
			break;
		}
	}







}
void Error_Handler(void)
{
	while(1);
}


