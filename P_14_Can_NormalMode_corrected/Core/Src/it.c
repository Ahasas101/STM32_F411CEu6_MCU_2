#include "stm32f1xx_hal.h"

extern CAN_HandleTypeDef can1;
extern TIM_HandleTypeDef tim2;

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

// for button, when button is pressed the timer is started and button is on pin_no_8
void EXTI9_5_IRQHandler(void)
{
	HAL_TIM_Base_Start_IT(&tim2);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
}



void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&tim2);
}

void USB_HP_CAN1_TX_IRQHandler(void)
{
	HAL_CAN_IRQHandler(&can1);
}

void USB_LP_CAN1_RX0_IRQHandler(void)
{
	HAL_CAN_IRQHandler(&can1);
}


void CAN1_RX1_IRQHandler(void)
{
	HAL_CAN_IRQHandler(&can1);
}

void CAN1_SCE_IRQHandler(void)
{
	HAL_CAN_IRQHandler(&can1);
}


