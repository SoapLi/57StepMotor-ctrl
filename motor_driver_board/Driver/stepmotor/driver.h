#ifndef __DRIVER_H
#define __DRIVER_H
#include "sys.h"
#include "stdlib.h"	

/********** 驱动器 端口定义 **************
//DRIVER_DIR   PC0 
//DRIVER_OE    PC2 
//STEP_PULSE   PC7 (TIM8_CH2,LCD_RW)
******************************************/
#define DRIVER_DIR   PCout(0) // 旋转方向 
#define DRIVER_OE    PCout(2) // 使能脚 低电平有效
#define RCR_VAL    255  //每计数（RCR_VAL+1）次，中断一次，这个值（0~255）设置大一些可以降低中断频率

typedef enum
{
	CW = 1,//高电平顺时针
	CCW = 0,//低电平逆时针
}DIR_Type;//运行方向

extern long target_pos;//有符号方向
extern long current_pos;//有符号方向

void Driver_Init(void);//驱动器初始化
void TIM8_OPM_RCR_Init(u16 arr,u16 psc);//TIM8_CH2 单脉冲输出+重复计数功能初始化
void TIM8_Startup(u32 frequency);   //启动定时器8
void TIM8_Stop()  ;
void Locate_Rle(long num,u32 frequency,DIR_Type dir); //相对定位函数
void Locate_Abs(long num,u32 frequency);//绝对定位函数
void moto_lock();
void moto_unlock();

#endif


