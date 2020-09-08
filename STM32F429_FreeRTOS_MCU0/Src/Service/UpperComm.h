#ifndef _UPPERCOMM_H
#define _UPPERCOMM_H

#include "marco.h"

typedef enum
{
	TO_ROBOT= 0,
	TO_SENSORS = 1,
	TO_ALL = 2,
} cmdDirection_t;


typedef struct
{
	int cmd_index;
	char* cmdstr;
	int param_num;
	int direction;//0:to robot 1:to sensor 2:to all
	char *params[10];
	void (*func_cmd_exec)(void * para,u8 *data_frame);
} cmdReg_t;






void process_upper_comm(void);


#endif




