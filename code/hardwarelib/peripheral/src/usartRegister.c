#include "stm32F4Define.h"
#include "usartRegister.h"
void USART_Init(USART_TypeDef* usart,u32 baud,u8 usart_cfg)
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
		}break;
		case USART2_BASE:
		{
			RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
			RCC->APB1RSTR |= RCC_APB1RSTR_USART2RST;
			RCC->APB1RSTR &= ~RCC_APB1RSTR_USART2RST;
			u32 DIV_Mantissa = SystemClock.APB1Clock/(baud*16);
			u32 DIV_Fraction = SystemClock.APB1Clock%(baud*16)/baud;
			usart->BRR = (DIV_Mantissa << 4) | DIV_Fraction;
		}break;
		case USART3_BASE:
		{
			RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
			RCC->APB1RSTR |= RCC_APB1RSTR_USART3RST;
			RCC->APB1RSTR &= ~RCC_APB1RSTR_USART3RST;
			u32 DIV_Mantissa = SystemClock.APB1Clock/(baud*16);
			u32 DIV_Fraction = SystemClock.APB1Clock%(baud*16)/baud;
			usart->BRR = (DIV_Mantissa << 4) | DIV_Fraction;
		}break;
		case UART4_BASE:
		{
			RCC->APB1ENR |= RCC_APB1ENR_UART4EN;
			RCC->APB1RSTR |= RCC_APB1RSTR_UART4RST;
			RCC->APB1RSTR &= ~RCC_APB1RSTR_UART4RST;
			u32 DIV_Mantissa = SystemClock.APB1Clock/(baud*16);
			u32 DIV_Fraction = SystemClock.APB1Clock%(baud*16)/baud;
			usart->BRR = (DIV_Mantissa << 4) | DIV_Fraction;
		}break;
		case UART5_BASE:
		{
			RCC->APB1ENR |= RCC_APB1ENR_UART5EN;
			RCC->APB1RSTR |= RCC_APB1RSTR_UART5RST;
			RCC->APB1RSTR &= ~RCC_APB1RSTR_UART5RST;
			u32 DIV_Mantissa = SystemClock.APB1Clock/(baud*16);
			u32 DIV_Fraction = SystemClock.APB1Clock%(baud*16)/baud;
			usart->BRR = (DIV_Mantissa << 4) | DIV_Fraction;
		}break;
		case USART6_BASE:
		{
			RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
			RCC->APB2RSTR |= RCC_APB2RSTR_USART6RST;
			RCC->APB2RSTR &= ~RCC_APB2RSTR_USART6RST;
			u32 DIV_Mantissa = SystemClock.APB1Clock/(baud*16);
			u32 DIV_Fraction = SystemClock.APB1Clock%(baud*16)/baud;
			usart->BRR = (DIV_Mantissa << 4) | DIV_Fraction;
		}break;
		default:break;
	}
	
	
}
