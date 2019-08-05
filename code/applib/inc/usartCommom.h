#ifndef __USARTCOMMON_H
#define __USARTCOMMON_H 
#include "stm32F4Define.h"




#define 	UARTINFO_SIZE				1024
#define 	UARTINFO_SEND_SIZE			1024


#define UART_REV_NULL			0x00
#define UART_REV_DMA			0x01
#define UART_REV_INT			0x02
#define UART_REV_POLL			0x03

#define UART_SEND_IO			0x04
#define UART_SEND_ANSY			0x05


typedef void (*usartRevFunc)(u8 *buff,u32 len);



typedef struct uartrevfifo
{
	enumUsart uart;
	usartRevFunc revFunc;
	uint8_t revBuff[UARTINFO_SIZE];
	uint8_t sendBuff[UARTINFO_SEND_SIZE];	
	uint8_t sendLen;
	uint8_t revCmd;	
}stuUartRevFifo;




/********************begin func *****************************************/
extern int32_t 		createFifoRev(enumUsart uart , revFunc revDataFunc,uint32_t revMode);

extern void 		delFifoRev(int32_t index);

extern void 		sendBuffFifo(int32_t index , uint8_t *buff,int32_t len,int32_t sendMode);

extern void 		UsartReceive_IDLE(UART_HandleTypeDef *huart);




/**********************end func *****************************************/














#endif


