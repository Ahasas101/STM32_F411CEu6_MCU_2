/*
 * Write  a program to send characters over UART to MCU , Mcu shoudl
 * convert all the lower case letter in to uppercase and send it back
 * to the user
 */
#include "stm32f4xx.h"
#include "main.h"
#include <string.h>
#include <stdio.h>

void SystemClockConfig(void);
void UART2_init(void);
void Error_Handler(void);

uint8_t convert_to_capital(uint8_t data);

UART_HandleTypeDef huart2;

uint8_t rec_data;
uint8_t data_buffer [100];

uint8_t count = 0;


char* user_data = "Testing for data transmission over UART...\r";

int main(void)
{
	HAL_Init();
	SystemClockConfig();
	UART2_init();
	HAL_UART_Transmit(&huart2, (uint8_t*)user_data, strlen(user_data), HAL_MAX_DELAY);
	data_buffer[count++] = '\r';

	HAL_UART_Receive_IT(&huart2, &rec_data, 1);
	while(1);

}

void SystemClockConfig(void)
{

}

void UART2_init(void)
{
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	if(HAL_UART_Init(&huart2) != HAL_OK)
	{
		Error_Handler();
	}


}

void Error_Handler(void)
{
	while(1);
}

uint8_t convert_to_capital(uint8_t data)
{
	if(data >= 'a' && data <= 'z')
	{
		return (data - ('a' - 'A'));
	}
	return data;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(rec_data == '\n')
	{
		data_buffer[count++] = '\r';
		HAL_UART_Transmit(&huart2, data_buffer, count, HAL_MAX_DELAY);
	}
	else
	{
		data_buffer[count++] = convert_to_capital(rec_data);
		HAL_UART_Receive_IT(&huart2, &rec_data, 1);
	}
}
