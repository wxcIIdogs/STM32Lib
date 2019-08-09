#ifndef __BASECOM_H__
#define __BASECOM_H__

#include "stm32F4Define.h"

typedef enum
{
	STM_OK 		= 0,
	STM_FALSE 	= 1,
}STM_STATUS;

typedef struct dev_node
{
 	void *obj;
	void *dev_info;
}stuDevNode;	//StuDevNode

typedef struct// ops
{
	STM_STATUS (*open)(stuDevNode *node);		
	STM_STATUS (*write)(stuDevNode *node,const uint8_t *wbuff,uint32_t wlen);
	STM_STATUS (*read)(stuDevNode *node,uint8_t *rbuff,uint32_t rlen);
	STM_STATUS (*ioctl)(stuDevNode *node,uint32_t cmd,uint32_t arg);
	STM_STATUS (*release)(stuDevNode *node);
}stmOperations;//STMOperations


typedef struct 
{
	stmOperations ops;				//STMOperations
	stuDevNode node;					//StuDevNode
	uint8_t devName[20];			//DevName
}deviceBase;								//DeviceBase





uint32_t 			stm_getTick(void);
void 					stm_Delay(uint32_t ms);



#endif





