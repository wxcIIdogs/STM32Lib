#include "stm32F4Define.h"
#include "usartRegister.h"

static const u32 _usart_isr_bit_table[4] = {USART_CR1_TXEIE,USART_CR1_RXNEIE,USART_CR1_TCIE,USART_CR1_IDLEIE};
static const u32 _usart_dma_bit_table[2] = {USART_CR3_DMAT,USART_CR3_DMAR};
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

void USART_WriteByte(USART_TypeDef* usart,u8 value)
{
	while((USART1->SR & USART_SR_TXE) == 0);
	usart->DR = value;	
}

u8 USART_ReadByte(USART_TypeDef* usart)
{
	return usart->DR;
}
u8 USART_checkPollRead(USART_TypeDef* usart)
{
	return (usart->SR & USART_SR_RXNE);
}
void USART_InterruptEnable(USART_TypeDef* usart,enumUSART_ISR_Source usart_isr_source)
{
	usart->CR1 |=  _usart_isr_bit_table[usart_isr_source];
}

void USART_InterruptDisable(USART_TypeDef* usart,enumUSART_ISR_Source usart_isr_source)
{
	usart->CR1 &= ~_usart_isr_bit_table[usart_isr_source];
}


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
		USART_TXE_Handler(USART1);
	}
	if((USART1->SR & USART_SR_RXNE) && (USART1->CR1 & USART_CR1_RXNEIE))
	{
		USART_RXNE_Handler(USART1);
	}
	if((USART1->SR & USART_SR_TC) && (USART1->CR1 & USART_CR1_TCIE))
	{
		USART_TC_Handler(USART1);
	}
	if((USART1->SR & USART_SR_IDLE) && (USART1->CR1 & USART_CR1_IDLEIE))
	{
		USART_IDLE_Handler(USART1);
		USART_ReadByte(USART1);
	}
}
__weak void USART_TXE_Handler(USART_TypeDef* uart)
{
	
}
__weak void USART_RXNE_Handler(USART_TypeDef* uart)
{
	
}
__weak void USART_TC_Handler(USART_TypeDef* uart)
{
	
}
__weak void USART_IDLE_Handler(USART_TypeDef* uart)
{
	
}

