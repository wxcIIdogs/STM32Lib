#include "usart.h"

void USART1_TXE_Handler(void);
void USART1_RXNE_Handler(void);
void USART1_TC_Handler(void);
void USART1_IDLE_Handler(void);

void USART_Init(USART_TypeDef* usart,u32 baud)
{
	switch((u32)usart)
	{
		case USART1_BASE:
		{
			RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
			RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST;
			RCC->APB2RSTR &= ~RCC_APB2RSTR_USART1RST;
			u32 DIV_Mantissa = SystemClock.APB2Clock/(baud*16);
			u32 DIV_Fraction = SystemClock.APB2Clock%(baud*16)/baud;
			usart->BRR = (DIV_Mantissa << 4) | DIV_Fraction;
			usart->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
			NVIC_EnableIRQ(USART1_IRQn);
		}break;
		case USART2_BASE:
		{
			RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
			RCC->APB1RSTR |= RCC_APB1RSTR_USART2RST;
			RCC->APB1RSTR &= ~RCC_APB1RSTR_USART2RST;
			u32 DIV_Mantissa = SystemClock.APB1Clock/(baud*16);
			u32 DIV_Fraction = SystemClock.APB1Clock%(baud*16)/baud;
			usart->BRR = (DIV_Mantissa << 4) | DIV_Fraction;
			usart->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
			NVIC_EnableIRQ(USART2_IRQn);
		}break;
		case USART3_BASE:
		{
			RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
			RCC->APB1RSTR |= RCC_APB1RSTR_USART3RST;
			RCC->APB1RSTR &= ~RCC_APB1RSTR_USART3RST;
			u32 DIV_Mantissa = SystemClock.APB1Clock/(baud*16);
			u32 DIV_Fraction = SystemClock.APB1Clock%(baud*16)/baud;
			usart->BRR = (DIV_Mantissa << 4) | DIV_Fraction;
			usart->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
			NVIC_EnableIRQ(USART3_IRQn);
		}break;
		case UART4_BASE:
		{
			RCC->APB1ENR |= RCC_APB1ENR_UART4EN;
			RCC->APB1RSTR |= RCC_APB1RSTR_UART4RST;
			RCC->APB1RSTR &= ~RCC_APB1RSTR_UART4RST;
			u32 DIV_Mantissa = SystemClock.APB1Clock/(baud*16);
			u32 DIV_Fraction = SystemClock.APB1Clock%(baud*16)/baud;
			usart->BRR = (DIV_Mantissa << 4) | DIV_Fraction;
			usart->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
			NVIC_EnableIRQ(UART4_IRQn);
		}break;
		case UART5_BASE:
		{
			RCC->APB1ENR |= RCC_APB1ENR_UART5EN;
			RCC->APB1RSTR |= RCC_APB1RSTR_UART5RST;
			RCC->APB1RSTR &= ~RCC_APB1RSTR_UART5RST;
			u32 DIV_Mantissa = SystemClock.APB1Clock/(baud*16);
			u32 DIV_Fraction = SystemClock.APB1Clock%(baud*16)/baud;
			usart->BRR = (DIV_Mantissa << 4) | DIV_Fraction;
			usart->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
			NVIC_EnableIRQ(UART5_IRQn);
		}break;
		case USART6_BASE:
		{
			RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
			RCC->APB2RSTR |= RCC_APB2RSTR_USART6RST;
			RCC->APB2RSTR &= ~RCC_APB2RSTR_USART6RST;
			u32 DIV_Mantissa = SystemClock.APB1Clock/(baud*16);
			u32 DIV_Fraction = SystemClock.APB1Clock%(baud*16)/baud;
			usart->BRR = (DIV_Mantissa << 4) | DIV_Fraction;
			usart->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
			NVIC_EnableIRQ(USART6_IRQn);
		}break;
		default:break;
	}
}

static const u32 _usart_isr_bit_table[4] = {USART_CR1_TXEIE,USART_CR1_RXNEIE,USART_CR1_TCIE,USART_CR1_IDLEIE};

void USART_InterruptEnable(USART_TypeDef* usart,enumUSART_ISR_Source usart_isr_source)
{
	usart->CR1 |= _usart_isr_bit_table[usart_isr_source];
}

void USART_InterruptDisable(USART_TypeDef* usart,enumUSART_ISR_Source usart_isr_source)
{
	usart->CR1 &= ~_usart_isr_bit_table[usart_isr_source];
}

static const u32 _usart_dma_bit_table[2] = {USART_CR3_DMAT,USART_CR3_DMAR};
void USART_DMAEnable(USART_TypeDef* usart,enumUSART_DMA_Source usart_dma_source)
{
	usart->CR3 |= _usart_dma_bit_table[usart_dma_source];
}

void USART_DMADisable(USART_TypeDef* usart,enumUSART_DMA_Source usart_dma_source)
{
	usart->CR3 |= _usart_dma_bit_table[usart_dma_source];
}

void USART1_IRQHandler(void)
{
	if((USART1->SR & USART_SR_TXE) && (USART1->CR1 & USART_CR1_TXEIE))
	{
		USART1_TXE_Handler();
	}
	if((USART1->SR & USART_SR_RXNE) && (USART1->CR1 & USART_CR1_RXNEIE))
	{
		USART1_RXNE_Handler();
	}
	if((USART1->SR & USART_SR_TC) && (USART1->CR1 & USART_CR1_TCIE))
	{
		USART1_TC_Handler();
	}
	if((USART1->SR & USART_SR_IDLE) && (USART1->CR1 & USART_CR1_IDLEIE))
	{
		USART1_IDLE_Handler();
	}
}