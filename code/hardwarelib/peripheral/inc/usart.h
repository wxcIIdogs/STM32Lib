#ifndef __USART_H__
#define	__USART_H__

#include "common.h"


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


void USART_Init(USART_TypeDef* usart,u32 baud);
void USART_InterruptEnable(USART_TypeDef* usart,enumUSART_ISR_Source usart_isr_source);
void USART_InterruptDisable(USART_TypeDef* usart,enumUSART_ISR_Source usart_isr_source);
void USART_DMAEnable(USART_TypeDef* usart,enumUSART_DMA_Source usart_dma_source);
void USART_DMADisable(USART_TypeDef* usart,enumUSART_DMA_Source usart_dma_source);

#endif
