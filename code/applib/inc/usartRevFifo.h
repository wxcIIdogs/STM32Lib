#ifndef __USARTREVFIFO_H
#define __USARTREVFIFO_H 
#include "stm32F4Define.h"






typedef struct usartRevFifo
{
	stuAnalyInfo m_revAnalyData;
	struct usartRevFifo *m_next;
	USART_TypeDef *m_usart;	
}stuRevFifo;




RpyStatus 		initUsartRevFifo(int index);



RpyStatus 		insertUsartRevData(stuAnalyInfo *revData);



RpyStatus 		readUsartRevData(int index,stuAnalyInfo *revTemp);












#endif



