#ifndef __USARTREGISTER_H__
#define	__USARTREGISTER_H__

#include "stm32F4Define.h"


#define USART_DATA_LENGTH_8BIT	(0<<0)
#define	USART_DATA_LENGTH_9BIT	(1<<0)

#define	USART_PARITY_NONE		(0<<1)
#define	USART_PARITY_EVEN		(1<<1)
#define	USART_PARITY_ODD		(2<<1)

#define	USART_STOP_1BIT			(0<<3)
#define	USART_STOP_0P5BIT		(1<<3)
#define	USART_STOP_2BIT			(2<<3)
#define	USART_STOP_1P5BIT		(3<<3)

extern void 		USART_TXE_Handler(USART_TypeDef* uart);
extern void 		USART_RXNE_Handler(USART_TypeDef* uart);
extern void 		USART_TC_Handler(USART_TypeDef* uart);
extern void 		USART_IDLE_Handler(USART_TypeDef* uart);

void USART_Init(USART_TypeDef* usart,u32 baud);
void USART_WriteByte(USART_TypeDef* usart,u8 value);
u8   USART_ReadByte(USART_TypeDef* usart);
u8 	 USART_checkPollRead(USART_TypeDef* usart);
void USART_InterruptEnable(USART_TypeDef* usart,enumUSART_ISR_Source usart_isr_source);
void USART_InterruptDisable(USART_TypeDef* usart,enumUSART_ISR_Source usart_isr_source);
void USART_DMAEnable(USART_TypeDef* usart,enumUSART_DMA_Source usart_dma_source);
void USART_DMADisable(USART_TypeDef* usart,enumUSART_DMA_Source usart_dma_source);
#endif
