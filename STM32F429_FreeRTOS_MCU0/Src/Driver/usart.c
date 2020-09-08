#include "usart.h"
#include "marco.h"

u8 USART2_RX_BUF[USART2_REC_LEN];
u16 USART2_RX_STA = 0;
u8 aUart2RxBuffer[RXBUFFERSIZE];
u8 USART3_RX_BUF[USART3_REC_LEN];
u16 USART3_RX_STA = 0;
u8 aUart3RxBuffer[RXBUFFERSIZE];

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;

void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 230400;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
}

void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 230400;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
}

void MX_USART3_UART_Init(void)
{

  huart3.Instance = USART3;
  huart3.Init.BaudRate = 230400;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
}

DMA_HandleTypeDef UART2RxDMA_Handler; //DMA句柄
void UART2_DMA_RX_CONF(void)
{
  __HAL_RCC_DMA1_CLK_ENABLE(); //DMA1时钟使能
  HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);

  //DMA配置
  UART2RxDMA_Handler.Instance = DMA1_Stream5;
  UART2RxDMA_Handler.Init.Channel = DMA_CHANNEL_4;
  UART2RxDMA_Handler.Init.Direction = DMA_PERIPH_TO_MEMORY;
  UART2RxDMA_Handler.Init.PeriphInc = DMA_PINC_DISABLE;              //外设非增量模式
  UART2RxDMA_Handler.Init.MemInc = DMA_MINC_ENABLE;                  //存储器增量模式
  UART2RxDMA_Handler.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE; //外设数据长度:8位
  UART2RxDMA_Handler.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;    //存储器数据长度:8位
  UART2RxDMA_Handler.Init.Mode = DMA_NORMAL;                         //外设普通模式
  UART2RxDMA_Handler.Init.Priority = DMA_PRIORITY_MEDIUM;            //中等优先级
  UART2RxDMA_Handler.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
  UART2RxDMA_Handler.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
  UART2RxDMA_Handler.Init.MemBurst = DMA_MBURST_SINGLE;    //存储器突发单次传输
  UART2RxDMA_Handler.Init.PeriphBurst = DMA_PBURST_SINGLE; //外设突发单次传输
  HAL_DMA_Init(&UART2RxDMA_Handler);
  __HAL_LINKDMA(&huart2, hdmarx, UART2RxDMA_Handler);


  //打开DMA接收，指定接收缓存区和接收大小
  //	HAL_UART_Receive_DMA(&huart2, (u8 *)&usart2_rx_buffer, USART_DMA_RX_BUFFER_MAXIMUM);
}

void HAL_UART_MspInit(UART_HandleTypeDef *uartHandle)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if (uartHandle->Instance == USART1)
  {
    __HAL_RCC_USART1_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    GPIO_InitStruct.Pin = GPIO_PIN_9 | GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  }
  else if (uartHandle->Instance == USART2)
  {
    __HAL_RCC_USART2_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    GPIO_InitStruct.Pin = GPIO_PIN_2 | GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    __HAL_UART_DISABLE_IT(uartHandle, UART_IT_TC);
    __HAL_UART_ENABLE_IT(uartHandle, UART_IT_RXNE);
    __HAL_UART_ENABLE_IT(uartHandle, UART_IT_ERR);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
    HAL_NVIC_SetPriority(USART2_IRQn, 3, 3);
    //开启空闲接收中断
    //	__HAL_UART_ENABLE_IT(uartHandle, UART_IT_IDLE);

    //   UART2_DMA_RX_CONF();
  }
  else if (uartHandle->Instance == USART3)
  {
    __HAL_RCC_USART3_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_InitStruct.Pin = GPIO_PIN_10 | GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    __HAL_UART_DISABLE_IT(uartHandle, UART_IT_TC);
    __HAL_UART_ENABLE_IT(uartHandle, UART_IT_RXNE);
    __HAL_UART_ENABLE_IT(uartHandle, UART_IT_ERR);
    HAL_NVIC_EnableIRQ(USART3_IRQn);
    HAL_NVIC_SetPriority(USART3_IRQn, 3, 3);
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef *uartHandle)
{
  if (uartHandle->Instance == USART1)
  {
    __HAL_RCC_USART1_CLK_DISABLE();
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9 | GPIO_PIN_10);
  }
  else if (uartHandle->Instance == USART2)
  {
    __HAL_RCC_USART2_CLK_DISABLE();
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2 | GPIO_PIN_3);
    HAL_NVIC_DisableIRQ(USART2_IRQn);
  }
  else if (uartHandle->Instance == USART3)
  {
    __HAL_RCC_USART3_CLK_DISABLE();
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_10 | GPIO_PIN_11);
    HAL_NVIC_DisableIRQ(USART3_IRQn);
  }
}
