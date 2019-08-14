#include "stm32F4Define.h"



static stuUsartSendFifo sg_usartSendFifoBuff[USTCOUNT] = {0};


/***********************************
*func:
*parm:
*return:
*info:
***********************************/
void initUsartSendFifo(int index,u32 buffLen,char *name)
{
	assert(index >= 0);
	assert(index < USTCOUNT);
	sg_usartSendFifoBuff[index].m_buffLen = buffLen;
	memcpy(sg_usartSendFifoBuff[index].m_name,name,strlen(name));
	sg_usartSendFifoBuff[index].m_writeIndex = 0;
	sg_usartSendFifoBuff[index].m_readIndex = 0;	
	sg_usartSendFifoBuff[index].m_sendBuff = (u8*)malloc(buffLen);
	
}
/***********************************
*func:
*parm:
*return:
*info:
***********************************/

void closeUsartSendFifo(int index)
{	
	assert(index >= 0);
	assert(index < USTCOUNT);
	sg_usartSendFifoBuff[index].m_buffLen = 0;
	memset(sg_usartSendFifoBuff[index].m_name,0,20);
	sg_usartSendFifoBuff[index].m_writeIndex = 0;
	sg_usartSendFifoBuff[index].m_readIndex = 0;	
	free(sg_usartSendFifoBuff[index].m_sendBuff);	
}

/***********************************
*func:
*parm:
*return:
*info:
***********************************/
RpyStatus inputUsartSendFifo_io(int index,u8 *buff,u32 len)
{
	assert(buff != NULL);
	assert(index >= 0);
	assert(index < USTCOUNT);
	usart_devOpt.write((enumUsart)index,buff,len);
	return True;
}
/***********************************
*func:
*parm:
*return:
*info:
***********************************/
RpyStatus inputUsartSendFifo(int index,u8 *buff,u32 len)
{	
	assert(index >= 0);
	assert(index < USTCOUNT);
	assert(buff != NULL);
	memcpy(sg_usartSendFifoBuff[index].m_sendBuff + sg_usartSendFifoBuff[index].m_writeIndex,buff,len);
	sg_usartSendFifoBuff[index].m_writeIndex += len;
	if(sg_usartSendFifoBuff[index].m_writeIndex > sg_usartSendFifoBuff[index].m_buffLen)
	{
		sg_usartSendFifoBuff[index].m_writeIndex %= sg_usartSendFifoBuff[index].m_buffLen; 
	}	
	return True;
}

/***********************************
*func:
*parm:
*return:
*info:
***********************************/
RpyStatus outputUsartSendFifo(int index)
{	
	assert(index >= 0);
	assert(index < USTCOUNT);
	u8 buff[sg_usartSendFifoBuff[index].m_buffLen];
	int i;
	//memcpy(buff,sg_usartSendFifoBuff[index].m_sendBuff + sg_usartSendFifoBuff[index].m_readIndex,len);	
	for(i = 0 ;sg_usartSendFifoBuff[index].m_readIndex != sg_usartSendFifoBuff[index].m_writeIndex ; i ++ )
	{
		buff[i] = sg_usartSendFifoBuff[index].m_sendBuff[sg_usartSendFifoBuff[index].m_readIndex];
		sg_usartSendFifoBuff[index].m_readIndex ++;
		sg_usartSendFifoBuff[index].m_readIndex %= sg_usartSendFifoBuff[index].m_buffLen;
	}
	usart_devOpt.write((enumUsart)index,buff,i);
	return True;
}


void loopUsartSendFifo()
{
	for(int i = UST1; i < USTCOUNT ; i ++)
	{
		outputUsartSendFifo(i);
	}
}



