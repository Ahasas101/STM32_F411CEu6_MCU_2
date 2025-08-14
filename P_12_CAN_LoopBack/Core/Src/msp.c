#include "main.h"

void HAL_CAN_MspInit(CAN_HandleTypeDef *hcan)
{
	__HAL_RCC_CAN1_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef can;
	can.Mode = GPIO_MODE_AF_PP;
	can.Pin = GPIO_PIN_11 | GPIO_PIN_12;
	can.Speed = GPIO_SPEED_FREQ_MEDIUM;
	can.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &can);

}
