#ifndef __USART_H__
#define	__USART_H__

#include "stm32F4Define.h"

typedef enum
{
	UST1 = 0,UST2,UST3,UST4,UST5,UST6,USTCOUNT,
}enumUsart;

extern USART_TypeDef* (sg_UsartBuff[6]);


typedef enum
{
    m_usart_isr_txe = 0,
    m_usart_isr_rxne,
    m_usart_isr_tc,
    m_usart_isr_idle
}enumUSART_ISR_Source;

typedef enum
{
    m_usart_dma_tx = 0,
    m_usart_dma_rx
}enumUSART_DMA_Source;



typedef struct// ops
{
	RpyStatus (*open)(enumUsart defUSART,u32 baud,u8 mode);		
	RpyStatus (*write)(enumUsart defUSART,u8* data,uint32_t len);
	RpyStatus (*read)(enumUsart defUSART,u8* data,uint32_t *len);
	RpyStatus (*ioctl)(enumUsart defUSART,u8 pin_cfg);
	RpyStatus (*release)(enumUsart defUSART);
}usart_Operation;//STMOperations

extern usart_Operation 	usart_devOpt;

//void USART_Init(USART_TypeDef* usart,u32 baud);
//void USART_InterruptEnable(USART_TypeDef* usart,enumUSART_ISR_Source usart_isr_source);
//void USART_InterruptDisable(USART_TypeDef* usart,enumUSART_ISR_Source usart_isr_source);
//void USART_DMAEnable(USART_TypeDef* usart,enumUSART_DMA_Source usart_dma_source);
//void USART_DMADisable(USART_TypeDef* usart,enumUSART_DMA_Source usart_dma_source);

#endif
