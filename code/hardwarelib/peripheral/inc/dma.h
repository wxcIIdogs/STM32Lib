#ifndef __DMAOPT_H__
#define __DMAOPT_H__

#include "common.h"

void DMA_USART_Init(USART_TypeDef* usart,u8* pbuf,u32 length);
void DMA_USART_Start(USART_TypeDef* usart);
void DMA_USART_Stop(USART_TypeDef* usart);
u16 DMA_USART_GetRemain(USART_TypeDef* usart);

#endif
