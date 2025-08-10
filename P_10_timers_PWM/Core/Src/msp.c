#include "stm32f4xx_hal.h"
//void HAL_MspInit(void)
//{
//}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
	//1. Enable the peripheral clock
	__HAL_RCC_TIM2_CLK_ENABLE();

	//2. Initialize the gpio pins for the purpose..
	GPIO_InitTypeDef gpiotim;
	gpiotim.Alternate = GPIO_AF1_TIM2 ;
	gpiotim.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;
	gpiotim.Mode = GPIO_MODE_AF_PP;
	gpiotim.Pull = GPIO_NOPULL;

	__HAL_RCC_GPIOA_CLK_ENABLE();

	HAL_GPIO_Init(GPIOA,  &gpiotim);

	//3. Interrupt config
	HAL_NVIC_SetPriority(TIM2_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);

}
