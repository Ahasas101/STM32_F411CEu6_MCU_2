#include "stm32f4xx_hal.h"

//HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
//{
//  /* Configure the SysTick to have interrupt in 1ms time basis*/
//  if (HAL_SYSTICK_Config(SystemCoreClock / (1000U / uwTickFreq)) > 0U)
//  {
//    return HAL_ERROR;
//  }
//
//  /* Configure the SysTick IRQ priority */
//  if (TickPriority < (1UL << __NVIC_PRIO_BITS))
//  {
//    HAL_NVIC_SetPriority(SysTick_IRQn, TickPriority, 0U);
//    uwTickPrio = TickPriority;
//  }
//  else
//  {
//    return HAL_ERROR;
//  }
//
//  /* Return function status */
//  return HAL_OK;
//}



void HAL_MspInit(void)
{



  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

}


