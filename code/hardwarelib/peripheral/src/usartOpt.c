#include "stm32F4Define.h"
#include "usartRegister.h"
#include "usartOpt.h"
static USART_TypeDef* (sg_UsartBuff[]) = {USART1,USART2,USART3,UART4,UART5,USART6}; 

RpyStatus initUsartOpt(enumUsart defUSART,u32 baud)
{
	if(baud < 100 || baud > 460800 || defUSART >= USTCOUNT)
	{
		return False;
	}
	//init usart 
	USART_Init(sg_UsartBuff[defUSART],baud);
	USART_InterruptEnable(sg_UsartBuff[defUSART]);
	return True;
}

RpyStatus writeUsartOpt(enumUsart defUSART,u8* data,u32 len)
{
	if(defUSART >= USTCOUNT || data == NULL)
	{
		return False;
	}		
	return True;
}

RpyStatus readUsartOpt(enumUsart defUSART,u8 *data,u32 *len)
{
	if(defUSART >= USTCOUNT || data == NULL || len == NULL)
	{
		return False;
	}

	return True;
}

RpyStatus setUsartOpt(enumUsart defUSART,u8 pin_index,u8 mode)
{
	return True;
}


















