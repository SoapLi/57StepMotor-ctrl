#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include <stdio.h>
#include "usart.h"
#include "spi.h"
#include "semphr.h"
#include "UpperComm.h"
#include "RobotComm.h"

#define SPI_INT_MSG_Q_NUM    1  	
osThreadId_t upperProcHandle;
const osThreadAttr_t upperProc_attributes = {
    .name = "upper_proc_task",
    .priority = (osPriority_t)osPriorityHigh1,
    .stack_size = 256 * 4};
osThreadId_t robotProcHandle;
const osThreadAttr_t robotProc_attributes = {
    .name = "robot_proc_task",
    .priority = (osPriority_t)osPriorityHigh2,
    .stack_size = 256 * 4};
osThreadId_t test0Handle;
const osThreadAttr_t test0_attributes = {
    .name = "test0",
    .priority = (osPriority_t)osPriorityBelowNormal1,
    .stack_size = 128 * 4};
osThreadId_t test1Handle;
const osThreadAttr_t test1_attributes = {
    .name = "test1",
    .priority = (osPriority_t)osPriorityBelowNormal2,
    .stack_size = 128 * 4};

void test0_task(void *argument);
void test1_task(void *argument);
void upper_proc_task(void *argument);
void robot_proc_task(void *argument);

void MX_FREERTOS_Init(void);

extern SemaphoreHandle_t BinarySemaphoreACKSync;

void MX_FREERTOS_Init(void)
{
  extern QueueHandle_t Spi_Int_Queue;
  BinarySemaphoreACKSync = xSemaphoreCreateBinary();
  Spi_Int_Queue = xQueueCreate(SPI_INT_MSG_Q_NUM,sizeof(u8));
  test0Handle = osThreadNew(test0_task, NULL, &test0_attributes);
  test1Handle = osThreadNew(test1_task, NULL, &test1_attributes);
  upperProcHandle = osThreadNew(upper_proc_task, NULL, &upperProc_attributes);
  robotProcHandle = osThreadNew(robot_proc_task, NULL, &robotProc_attributes);       
}


void test0_task(void *argument)
{
  for (;;)
  {
    int inter_value = 0;
    extern QueueHandle_t Spi_Int_Queue;
    if(Spi_Int_Queue!=NULL)
    {
      if(xQueueReceive(Spi_Int_Queue,&inter_value,portMAX_DELAY))
      {
        switch(inter_value)
        {
          case 111:     SPI2_MCU1_TEST();       break;
        }
      }

    }
    osDelay(1);
  }
}


void test1_task(void *argument)
{
  for (;;)
  {
    osDelay(1000);
    //xQueueSend(Spi_Int_Queue,&g_test_flag222,10);
  }
}

void upper_proc_task(void *argument)
{
  static int cnt = 0;
  for (;;)
  {
    process_upper_comm();
    osDelay(1);
    cnt++;
    if (cnt == 100)
    {
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
    }
    if (cnt == 200)
    {
      cnt = 0;
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
    }
  }
}

void robot_proc_task(void *argument)
{
  static int cnt = 0;
  for (;;)
  {
    process_robot_comm();
    osDelay(1);
    cnt++;
    if (cnt == 100)
    {
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
    }
    if (cnt == 200)
    {
      cnt = 0;
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
    }
  }
}