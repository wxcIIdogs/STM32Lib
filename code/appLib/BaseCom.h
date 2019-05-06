#ifndef BASECOM_H
#define BASECOM_H

#ifndef uint32_t 
#define uint32_t  unsigned int
#endif


#ifndef uint8_t 
#define uint8_t  unsigned char
#endif

#ifndef uint16_t 
#define uint16_t  unsigned short
#endif



typedef enum
{
	STM_OK 		= 0,
	STM_FALSE 	= 1,
}STM_STATUS;

typedef struct dev_node
{
 	void *obj;
	void *dev_info;
}stuDevNode;

typedef struct ops
{
	STM_STATUS (*open)(stuDevNode *node);		
	STM_STATUS (*write)(stuDevNode *node,const uint8_t *wbuff,uint32_t wlen);
	STM_STATUS (*read)(stuDevNode *node,uint8_t *rbuff,uint32_t rlen);
	STM_STATUS (*ioctl)(stuDevNode *node,uint32_t cmd,uint32_t arg);
	STM_STATUS (*release)(stuDevNode *node);
}stmOperations;


typedef struct deviceBase
{
	stmOperations ops;
	stuDevNode node;
	uint8_t devName[20];	
}


#endif





