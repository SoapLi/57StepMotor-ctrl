#include "FreeRTOS.h"
#include "semphr.h"
#include "RobotComm.h"
#include "marco.h"
#include "usart.h"
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "GlobalData.h"

extern SemaphoreHandle_t BinarySemaphoreACKSync;
void transparent_to_upper(u8 *data_frame){
  
  char send_str[UART_FRAM_TMP_BUF] = {0};
  sprintf(send_str,"%s%s",data_frame,"\r\n");
  HAL_UART_Transmit(&huart2,send_str,strlen(send_str),1000);	
  while(__HAL_UART_GET_FLAG(&huart2,UART_FLAG_TC)!=SET);
  BaseType_t upperTaskWoken;
  xSemaphoreGiveFromISR(BinarySemaphoreACKSync,&upperTaskWoken);	
  portYIELD_FROM_ISR(upperTaskWoken);//task toggle if needed
}

void robot_ack_parsing(u8 *data_ack,u32 data_len){
  printf("data_len[%d] - %s\r\n",data_len,data_ack);
  transparent_to_upper(data_ack);
}

void process_robot_comm(void)
{
  if(USART3_RX_STA&0x8000)
  {					   
    robot_ack_parsing(USART3_RX_BUF,USART3_RX_STA&0X3FFF);
    memset(USART3_RX_BUF,0,sizeof(USART3_RX_BUF));
    USART3_RX_STA=0;
  }
}

