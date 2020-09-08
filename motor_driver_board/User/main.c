#include "main.h"

#include "driver.h"


#include "string.h"

typedef struct
{
  int cmd_index;
  char* cmdstr;
  char *params[10];
  void (*func_cmd_exec)(void * para,u8 *data_frame);
} cmdReg_t;

typedef void cb_cmdPara_Split( char *str, int i,cmdReg_t* curCmdPara);




static void cb_cmd_para_split( char *str, int i,cmdReg_t* curCmdPara)
{      
  if(0 == i)
  {
    return;
  }
  curCmdPara->params[i-1] = str;	
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


void cmd_fwd_exec(void * para,u8 *data_frame)
{
  
  cmdReg_t* curCmdPara = (cmdReg_t*)para;
  
  //printf("para0 %s   para1 %s\r\n",curCmdPara->params[1],curCmdPara->params[2]);
  Locate_Rle(atoi(curCmdPara->params[1]),atoi(curCmdPara->params[2]),1);
  
  
  
}


void cmd_rev_exec(void * para,u8 *data_frame)
{
  
  cmdReg_t* curCmdPara = (cmdReg_t*)para;
  
  printf("para0 %s   para1 %s\r\n",curCmdPara->params[1],curCmdPara->params[2]);
  Locate_Rle(atoi(curCmdPara->params[1]),atoi(curCmdPara->params[2]),0);
  

  
}

void cmd_stop_exec(void * para,u8 *data_frame)
{
  TIM8_Stop();
}

void cmd_lock_exec(void * para,u8 *data_frame)
{
moto_lock();
}

void cmd_unlock_exec(void * para,u8 *data_frame)
{
moto_unlock();
}


cmdReg_t cmdRegTempList[] =
{
  { 1,"fwd",{"","","","","","","","","",""},cmd_fwd_exec},
  { 2,"rev",{"","","","","","","","","",""},cmd_rev_exec},
  { 3,"stop",{"","","","","","","","","",""},cmd_stop_exec},
  { 4,"lock",{"","","","","","","","","",""},cmd_lock_exec},
  { 5,"unlock",{"","","","","","","","","",""},cmd_unlock_exec},
  
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



static void upper_protocol_parsing(u8 *data_frame,u32 data_len)
{
  char cmdget[10] ={0};
  int i = 0;
  int cmd_len ;
  if(0 == data_len)
  {
    return;
  }
  cmd_len = get_cmdstr_by_data_frame(data_frame,data_len,cmdget);
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
int main()
{
  u8 len;	
  SystemInit(); 
  delay_init();
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  uart_init(230400);	
  LED_Init();
  Driver_Init();
  TIM8_OPM_RCR_Init(999,72-1); 	   
  while(1)
  {      
    if(USART_RX_STA&0x8000)
    {					   
      len=USART_RX_STA&0x3fff;
      printf("%s\r\n",USART_RX_BUF);
      upper_protocol_parsing(USART_RX_BUF,USART_RX_STA&0X3FFF);
      memset(USART_RX_BUF,0,len);
      USART_RX_STA=0;
      
    }
    
  }
  
}