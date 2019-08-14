

#ifndef __USARTSENDFIFO_H
#define __USARTSENDFIFO_H 
#include "stm32F4Define.h"




typedef struct
{
	int m_usartIndex;
	u32 m_buffLen;
	char m_name[20];

	__IO u32 m_readIndex;
	__IO u32 m_writeIndex;	
	u8 *m_sendBuff;
}stuUsartSendFifo;

extern void 			initUsartSendFifo(int index,u32 buffLen,char *name);
extern void 			closeUsartSendFifo(int index);
extern RpyStatus 		inputUsartSendFifo_io(int index,u8 *buff,u32 len);
extern RpyStatus 		inputUsartSendFifo(int index,u8 *buff,u32 len);
extern void 			loopUsartSendFifo(void);
#endif



