#include "marco.h"
#include "exti.h"

void EXTI_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_GPIOC_CLK_ENABLE();               
    GPIO_Initure.Pin=GPIO_PIN_13;          
    GPIO_Initure.Mode=GPIO_MODE_IT_FALLING;    
    GPIO_Initure.Pull=GPIO_PULLUP;
    HAL_GPIO_Init(GPIOC,&GPIO_Initure);
    HAL_NVIC_SetPriority(EXTI15_10_IRQn,2,3);   
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);         
}

void EXTI15_10_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
}


