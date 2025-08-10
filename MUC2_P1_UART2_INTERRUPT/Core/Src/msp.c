#include "stm32f4xx_hal.h"

GPIO_InitTypeDef gpio_uart;

void HAL_MspInit(void)
{
  // 1. Set the priority grouping for cortex mx processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	//2. Enable the processor exceptions
	SCB->SHCSR |= (0x7) << 16; // to enable the usage, memory and bus fault exception

	//3. Set the priority for the system exceptions
	HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
	HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
	HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
  // 1. Enable the peripheral clock , the macros for hal layer starts with __HAL
	__HAL_RCC_USART2_CLK_ENABLE();

//2.Do the pin muxing configurations.
	__HAL_RCC_GPIOA_CLK_ENABLE();

	gpio_uart.Pin = GPIO_PIN_2 | GPIO_PIN_3;
	gpio_uart.Pull = GPIO_MODE_OUTPUT_PP;
	gpio_uart.Speed = GPIO_SPEED_LOW;
	gpio_uart.Alternate = GPIO_AF7_USART2;
	gpio_uart.Mode = GPIO_MODE_AF_PP;

	HAL_GPIO_Init(GPIOA,  &gpio_uart);

	//3.enable the irq and set the priority( nvic settings)
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	HAL_NVIC_SetPriority(USART2_IRQn, 15, 0);
}
