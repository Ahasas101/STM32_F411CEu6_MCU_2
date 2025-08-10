#include "stm32f4xx_hal.h"
void GPIO_Init_tim(void);

void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim)
{
	//1. Enable the clock for the peripheral
	__HAL_RCC_TIM2_CLK_ENABLE();

	//2. Enable the channel ( by alternate function mapping of the gpios)
	GPIO_Init_tim();

	//3. nvic settings
	HAL_NVIC_SetPriority(TIM2_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void GPIO_Init_tim(void)
{
	GPIO_InitTypeDef gpiotim;
	gpiotim.Alternate = GPIO_AF1_TIM2;
	gpiotim.Pin = GPIO_PIN_0;
	gpiotim.Mode = GPIO_MODE_AF_PP;
	gpiotim.Pull = GPIO_NOPULL;

	__HAL_RCC_GPIOA_CLK_ENABLE();

	HAL_GPIO_Init(GPIOA,  &gpiotim);
}
