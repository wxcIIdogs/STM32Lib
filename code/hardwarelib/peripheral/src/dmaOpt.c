#include "dmaOpt.h"

void DMA_USART_Init(USART_TypeDef* usart,u8* pbuf,u32 length)
{
    if((RCC->AHB1ENR & RCC_AHB1ENR_DMA2EN) == 0)
	{
		RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;
	}
	if(DMA2_Stream2->CR & DMA_SxCR_EN)
	{
		DMA2_Stream2->CR &= ~DMA_SxCR_EN;
	}
	DMA2_Stream2->CR = (4 << DMA_SxCR_CHSEL_Pos) | (DMA_SxCR_MINC);
	DMA2_Stream2->NDTR = length;
	DMA2_Stream2->M0AR = (u32)pbuf;
	DMA2_Stream2->PAR = (u32)(&USART1->DR);
}

void DMA_USART_Start(USART_TypeDef* usart)
{
	DMA2->LIFCR = DMA_LIFCR_CTCIF2;
	DMA2_Stream2->CR |= DMA_SxCR_EN;
}

void DMA_USART_Stop(USART_TypeDef* usart)
{
	DMA2_Stream2->CR &= ~DMA_SxCR_EN;
}

u16 DMA_USART_GetRemain(USART_TypeDef* usart)
{
	return DMA2_Stream2->NDTR;
}
