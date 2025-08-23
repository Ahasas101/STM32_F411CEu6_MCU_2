/*
 * In this exercise we'll set current date and time in RTC and print the data whenever the user button is pressed
 * case 1: Time format 12hr
 * case 2: Time format 24hr
 * case 3: Do a system reset and observe the effects on RTC configuration
 * case 4: See the effects on RTC when you exit the standby mode
 *
 * RTC contents will be intact even in standby mode but configure the calender just once and it will remain there until power is available
 *
 *
 * @brief: GPIOA_PIN_0---> used to wakeup the processor from standy mode (active high)
 * 		   GPIOA_PIN_1---> used to get into standby mode (active low)
 * 		   GPIOA_PIN_2---> used to print the RTC MENU (active high)
 */

#include <stdio.h>
#include "stm32f4xx_hal.h"

RTC_HandleTypeDef rtc;

void Error_Handler(void);
void RTC_Init(void);
void RTC_CalenderConfig(void);
void button_init(void);
char* GetDayOfWeek(uint8_t day);

int main(void)
{
	HAL_Init();
	RTC_Init();
	button_init();
	RTC_CalenderConfig();
	printf("Hello...\n");
	// To check how the processor got into reset mode
		if(__HAL_PWR_GET_FLAG(PWR_FLAG_SB) != RESET)
		{
			// You have to clear flags manually
			__HAL_PWR_CLEAR_FLAG(PWR_FLAG_SB);
			__HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
			printf("Woke up from StandBy Mode\n");


		}
		HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);


		printf("Press button 1 to enter the StandBy Mode\n");
		printf("Press button 2 to print the RTC\n");
		while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) != GPIO_PIN_RESET);
		//HAL_Delay(100);
		printf("Entering StandBy Mode...\n");
		HAL_PWR_EnterSTANDBYMode();
	while(1);
}

void RTC_Init(void)
{
	rtc.Instance = RTC;
	rtc.Init.HourFormat = RTC_HOURFORMAT_12;
	rtc.Init.AsynchPrediv = 0x7F;
	rtc.Init.SynchPrediv = 0xFF; // for lse we are using this configuration
	rtc.Init.OutPut = RTC_OUTPUT_DISABLE;
	if(HAL_RTC_Init(&rtc) != HAL_OK) Error_Handler();
}

void RTC_CalenderConfig(void)
{
	// we are using binary format, and in binary format you can pass the values directly in decimal as they are stored in binary

	RTC_TimeTypeDef time;
	RTC_DateTypeDef date;

	time.Hours = 6;
	time.Minutes = 15;
	time.Seconds = 30;
	time.TimeFormat = RTC_HOURFORMAT12_PM;
	if(HAL_RTC_SetTime(&rtc, &time, RTC_FORMAT_BIN) != HAL_OK) Error_Handler();

	date.Date = 22;
	date.Month = RTC_MONTH_AUGUST;
	date.Year = 25;
	date.WeekDay = RTC_WEEKDAY_FRIDAY;

	if(HAL_RTC_SetDate(&rtc, &date, RTC_FORMAT_BIN) != HAL_OK) Error_Handler();
}

void button_init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef button;
	// This button is to print the data on screen
	button.Pin = GPIO_PIN_2;
	button.Mode = GPIO_MODE_IT_RISING;
	button.Pull = GPIO_PULLDOWN;
	button.Speed = GPIO_SPEED_FREQ_MEDIUM;

	HAL_NVIC_SetPriority(EXTI2_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(EXTI2_IRQn);

	HAL_GPIO_Init(GPIOA, &button);

	// This button is user button to get into  standby mode
	button.Pin = GPIO_PIN_1;
	button.Mode = GPIO_MODE_INPUT;
	button.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOA, &button);
}

char* GetDayOfWeek(uint8_t day)
{
	char* weekday[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	return weekday[day-1];
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	RTC_TimeTypeDef time;
	RTC_DateTypeDef date;

	HAL_RTC_GetTime(&rtc, &time, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&rtc, &date, RTC_FORMAT_BIN);


	printf("Current Time : %d:%d:%d \n", time.Hours, time.Minutes, time.Seconds);
	printf("Current Date: %d-%d-%d <%s> \n", date.Date, date.Month, date.Year, GetDayOfWeek(date.WeekDay) );



}

void Error_Handler(void)
{
	while(1);
}
