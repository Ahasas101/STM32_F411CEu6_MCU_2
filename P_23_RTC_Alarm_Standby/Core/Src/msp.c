#include "stm32f4xx_hal.h"

void HAL_RTC_MspInit(RTC_HandleTypeDef *hrtc)
{
    // 0) Power clock + allow access to backup domain (BDCR)
    __HAL_RCC_PWR_CLK_ENABLE();
    HAL_PWR_EnableBkUpAccess();

	// 1. Turn on the LSE
  RCC_OscInitTypeDef osc;

  osc.OscillatorType = RCC_OSCILLATORTYPE_LSE;
  osc.LSEState = RCC_LSE_ON;
  osc.PLL.PLLState = RCC_PLL_NONE;
  HAL_RCC_OscConfig(&osc);

  //2. Select the LSE as RTC clock source
  RCC_PeriphCLKInitTypeDef rcc_rtc;
  rcc_rtc.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  rcc_rtc.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
  HAL_RCCEx_PeriphCLKConfig(&rcc_rtc);

  //3. Enable the RTC clock in RCC_BDCR ( it is a backup domain register, it is not changed under reset)
  __HAL_RCC_RTC_ENABLE();

  //4. Enable the interrup for the alarm
  HAL_NVIC_SetPriority(RTC_Alarm_IRQn, 15, 0);
  HAL_NVIC_EnableIRQ(RTC_Alarm_IRQn);


}
