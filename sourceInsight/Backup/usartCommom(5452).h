#ifndef __USARTCOMMON_H
#define __USARTCOMMON_H 



#include "stm32F4Define.h"






typedef void (*revFunc)(uint8_t *buff,int32_t len);



typedef struct uartrevfifo
{
	UART_HandleTypeDef *uart;
	revFunc revFunc;
	uint8_t revBuff[ZQ_UARTINFO_SIZE];
	uint8_t sendBuff[ZQ_UARTINFO_SEND_SIZE];	
	uint8_t sendLen;
	uint8_t revCmd;	
}stuUartRevFifo;


















#endif


