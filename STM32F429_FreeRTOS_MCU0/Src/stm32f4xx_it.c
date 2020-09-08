#include "main.h"
#include "stm32f4xx_it.h"
#include "marco.h"
#include "usart.h"
#include "spi.h"

extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern TIM_HandleTypeDef htim1;
extern DMA_HandleTypeDef UART2RxDMA_Handler;
void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{

  while (1)
  {
  }
}

void MemManage_Handler(void)
{

  while (1)
  {
  }
}

void BusFault_Handler(void)
{

  while (1)
  {
  }
}

void UsageFault_Handler(void)
{

  while (1)
  {
  }
}

void DebugMon_Handler(void)
{
}

void TIM1_UP_TIM10_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&htim1);
}

void USART2_IRQHandler(void)
{
  u8 res;
  if (USART2->SR & (1 << 5))
  {
    res = USART2->DR;
    if ((USART2_RX_STA & 0x8000) == 0)
    {
      if (USART2_RX_STA & 0x4000)
      {
        if (res != 0x0a)
          USART2_RX_STA = 0;
        else
          USART2_RX_STA |= 0x8000;
      }
      else
      {
        if (res == 0x0d)
          USART2_RX_STA |= 0x4000;
        else
        {
          USART2_RX_BUF[USART2_RX_STA & 0X3FFF] = res;
          USART2_RX_STA++;
          if (USART2_RX_STA > (USART2_REC_LEN - 1))
            USART2_RX_STA = 0;
        }
      }
    }
  }
}

void USART3_IRQHandler(void)
{
  u8 Res;
  if ((__HAL_UART_GET_FLAG(&huart3, UART_FLAG_RXNE) != RESET))
  {
    HAL_UART_Receive(&huart3, &Res, 1, 1000);
    if ((USART3_RX_STA & 0x8000) == 0)
    {
      if (USART3_RX_STA & 0x4000)
      {
        if (Res != 0x0a)
          USART3_RX_STA = 0;
        else
          USART3_RX_STA |= 0x8000;
      }
      else
      {
        if (Res == 0x0d)
          USART3_RX_STA |= 0x4000;
        else
        {
          USART3_RX_BUF[USART3_RX_STA & 0X3FFF] = Res;
          USART3_RX_STA++;
          if (USART3_RX_STA > (USART3_REC_LEN - 1))
            USART3_RX_STA = 0;
        }
      }
    }
  }
  HAL_UART_IRQHandler(&huart3);
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
  uint32_t isrflags = READ_REG(huart->Instance->SR);
  if ((__HAL_UART_GET_FLAG(huart, UART_FLAG_PE)) != RESET)
  {
    READ_REG(huart->Instance->DR);
    __HAL_UART_CLEAR_FLAG(huart, UART_FLAG_PE);
  }
  if ((__HAL_UART_GET_FLAG(huart, UART_FLAG_FE)) != RESET)
  {
    READ_REG(huart->Instance->DR);
    __HAL_UART_CLEAR_FLAG(huart, UART_FLAG_FE);
  }

  if ((__HAL_UART_GET_FLAG(huart, UART_FLAG_NE)) != RESET)
  {
    READ_REG(huart->Instance->DR);
    __HAL_UART_CLEAR_FLAG(huart, UART_FLAG_NE);
  }

  if ((__HAL_UART_GET_FLAG(huart, UART_FLAG_ORE)) != RESET)
  {
    READ_REG(huart->Instance->CR1);
    __HAL_UART_CLEAR_FLAG(huart, UART_FLAG_ORE);
  }
}

void DMA1_Stream5_IRQHandler(void)
{

  HAL_DMA_IRQHandler(&UART2RxDMA_Handler);
}

int g_test_flag = 111;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  BaseType_t err;
  BaseType_t xHigherPriorityTaskWoken = pdFALSE;
  switch(GPIO_Pin)
  {
    case GPIO_PIN_13:
    if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)==0)  
    {
      extern QueueHandle_t Spi_Int_Queue;
      err = xQueueSendFromISR(Spi_Int_Queue,(void *)&g_test_flag, &xHigherPriorityTaskWoken);
      //portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
      if(err==errQUEUE_FULL)   
      {
          printf("!!!Spi_Int_Queue is FULL!xQueueSendFromISR FAIL\r\n");
      }
    }
    break;
  }
}