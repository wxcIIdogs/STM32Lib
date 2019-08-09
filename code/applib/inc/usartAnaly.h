#ifndef USARTANALY_H_
#define USARTANALY_H_

#include "stm32F4Define.h"


typedef enum
{
	m_head = 0,
	m_funcode,
	m_dataLen,
	m_data,
	m_crc,
}enumAnaly;


typedef struct
{
	enumAnaly m_status;
	u8 m_Head;
	u8 m_funcode;
	u8 m_dataLen;
	u8 *m_dataBuff;
	u8 m_crc;
	u8 m_count;	
	u32 m_timeOut;
	u32 m_timeCount;
	USART_TypeDef *m_usart;	
}stuAnalyInfo;









RpyStatus 	initUsartAnaly(int index,u8 revBuffLen);

RpyStatus 	setUsartAnalyHead(int index,u8 head);

RpyStatus 	setUsartAnalyTimeOut(int index,u32 timeout);


void 		inputAnalyData(u8 *revData,u8 revlen,USART_TypeDef *usart);








#endif



