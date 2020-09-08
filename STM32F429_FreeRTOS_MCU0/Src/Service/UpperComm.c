#include "FreeRTOS.h"
#include "semphr.h"
#include "UpperComm.h"
#include "marco.h"
#include "usart.h"
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "RobotComm.h"
#include "GlobalData.h"

typedef void cb_cmdPara_Split( char *str, int i,cmdReg_t* curCmdPara);

extern SemaphoreHandle_t BinarySemaphoreACKSync;

void transparent_to_robot(void * para,u8 *data_frame){
  
  BaseType_t err;
  char send_str[UART_FRAM_TMP_BUF] = {0};
  sprintf(send_str,"%s%s",data_frame,"\r\n");
  HAL_UART_Transmit(&huart3,send_str,strlen(send_str),1000);	
  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)!=SET);
  
  if(BinarySemaphoreACKSync != NULL)										
  {
    err=xSemaphoreTake(BinarySemaphoreACKSync,3000);	
    if(err==pdTRUE)										
    {
      printf("BinarySemaphoreACKSync get success!\r\n");
    }
    else
    {
      printf("BinarySemaphoreACKSync time out !\r\n");
      HAL_UART_Transmit(&huart2,"robot ack time out\r\n",20,1000);	
      while(__HAL_UART_GET_FLAG(&huart2,UART_FLAG_TC)!=SET);
      
    }
  }		
  
}


void cmd_rc_exec(void * para,u8 *data_frame)
{

  cmdReg_t* curCmdPara = (cmdReg_t*)para;
  
  int read_val = SPI2_MCU1_CONF_READ_TEST(atoi(curCmdPara->params[0]),0); 
  char send_str[UART_FRAM_TMP_BUF] = {0};
  sprintf(send_str,"[%s] [0x%x] %s",data_frame,read_val,"\r\n");
  HAL_UART_Transmit(&huart2,send_str,strlen(send_str),1000);
  while(__HAL_UART_GET_FLAG(&huart2,UART_FLAG_TC)!=SET);

}

void cmd_wc_exec(void * para,u8 *data_frame)
{
  cmdReg_t* curCmdPara = (cmdReg_t*)para;
  
  SPI2_MCU1_CONF_WRITE_TEST(atoi(curCmdPara->params[0]),atoi(curCmdPara->params[1])); 
  char send_str[UART_FRAM_TMP_BUF] = {0};
  sprintf(send_str,"[%s]%s",data_frame,"\r\n");
  HAL_UART_Transmit(&huart2,send_str,strlen(send_str),1000);
  while(__HAL_UART_GET_FLAG(&huart2,UART_FLAG_TC)!=SET);
}

void cmd_res_exec(void * para,u8 *data_frame)
{
#if 0
  char send_str[100];
  cmdReg_t* curCmdPara = (cmdReg_t*)para;
  printf("[cmd]:%s\t[param_num]:%d\t[direct]:%d\n",curCmdPara->cmdstr,curCmdPara->param_num,curCmdPara->direction);
  for(int i = 0;i<curCmdPara->param_num;i++)
  {
    printf("para[%d]: %s\n",i,curCmdPara->params[i]);
  }
  sprintf(send_str,"%s%s",curCmdPara->cmdstr,"\r\n");
  printf("SPI SEND: %s\n",send_str);
#endif
}

cmdReg_t cmdRegTempList[] =
{
  { 0,"home",0,TO_ROBOT,{"","","","","","","","","",""},transparent_to_robot},
  { 1,"park",0,TO_ROBOT,{"","","","","","","","","",""},transparent_to_robot},
  { 2,"fpark",0,TO_ROBOT,{"","","","","","","","","",""},transparent_to_robot},
  { 3,"next",0,TO_ROBOT,{"","","","","","","","","",""},transparent_to_robot},
  { 4,"setproduct",1,TO_ROBOT,{"","","","","","","","","",""},transparent_to_robot},
  { 5,"pos",3,TO_ROBOT,{"","","","","","","","","",""},transparent_to_robot},
  { 6,"goup",0,TO_ROBOT,{"","","","","","","","","",""},transparent_to_robot},
  { 7,"getpos",0,TO_ROBOT,{"","","","","","","","","",""},transparent_to_robot},
  { 8,"res",0,TO_SENSORS,{"","","","","","","","","",""},cmd_res_exec},
    //demo show mode cmd
  { 9,"rev",0,TO_ROBOT,{"","","","","","","","","",""},transparent_to_robot},
  { 10,"fwd",0,TO_ROBOT,{"","","","","","","","","",""},transparent_to_robot},
  { 11,"rc",0,TO_SENSORS,{"","","","","","","","","",""},cmd_rc_exec},//e2rom test only
  { 12,"wc",0,TO_SENSORS,{"","","","","","","","","",""},cmd_wc_exec},//e2rom test only
  { 13,"stop",0,TO_ROBOT,{"","","","","","","","","",""},transparent_to_robot},
  { 14,"lock",0,TO_ROBOT,{"","","","","","","","","",""},transparent_to_robot},
  { 15,"unlock",0,TO_ROBOT,{"","","","","","","","","",""},transparent_to_robot},
};

static int get_cmdstr_by_data_frame(u8 *data_frame,u32 data_len, char*cmdstr)
{
  int check_index = 0;
  for(check_index = 0;check_index  <data_len; check_index++){
    if(' '==data_frame[check_index]){
      strncpy(cmdstr,data_frame,check_index);
      return check_index;
    }
  }
  strncpy(cmdstr,data_frame,data_len);
  return data_len;
}


static void cb_cmd_para_split( char *str, int i,cmdReg_t* curCmdPara)
{      
  if(0 == i)
  {
    return;
  }
  curCmdPara->params[i-1] = str;	
  curCmdPara->param_num = i;
}


static int split_cmd_str(const char *str, const char ch,cb_cmdPara_Split callback_func,cmdReg_t* curCmdPara)

{
  char *t_str = NULL;
  char *p = NULL;
  char *t = NULL;
  int i = 0;
  t_str = (char *)malloc(strlen(str)+1);
  if(!t_str){
    return -1;
  }
  t = t_str;
  strcpy(t_str, str);
  p = t_str;
  while(*p){
    if(*p == ch){
      *p++ = '\0';
      callback_func(t,i++,curCmdPara);
      t = p;
    }
    else
      p++;
  }
  callback_func(t,i,curCmdPara);
  if(t_str){
    free(t_str);
    t_str = t = p = NULL;
  }
  return 0;
}


static void upper_protocol_parsing(u8 *data_frame,u32 data_len)
{
  char cmdget[10] ={0};
  int i = 0;
  if(0 == data_len)
  {
    return;
  }
  int cmd_len = get_cmdstr_by_data_frame(data_frame,data_len,cmdget);
  for (i = 0; i < sizeof(cmdRegTempList) / sizeof(cmdReg_t); i++)
  {
    if (!strncmp(cmdget, cmdRegTempList[i].cmdstr,strlen(cmdget)))
    {
      split_cmd_str(data_frame,' ',cb_cmd_para_split,&cmdRegTempList[i]);
      cmdRegTempList[i].func_cmd_exec(&cmdRegTempList[i],data_frame);
      return;
    }
  }
  
}

void process_upper_comm(void)
{
  if(USART2_RX_STA&0x8000)
  {					   
    upper_protocol_parsing(USART2_RX_BUF,USART2_RX_STA&0X3FFF);
    memset(USART2_RX_BUF,0,sizeof(USART2_RX_BUF));
    USART2_RX_STA=0;
  }
  
}


