#include "stm32f4xx_hal.h"

void HAL_MspInit(void)
{
	HAL_NVIC_SetPriority(EXTI0_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

