#include "stm32F4Define.h"
#include "usartRegister.h"
#include "usartOpt.h"

RpyStatus initUsartOpt(enumUsart defUSART,u32 baud)
{
	if(baud < 100 || baud > 460800 || defUSART >= USTCOUNT)
	{
		return False;
	}
	//init usart 
	USART_Init(sg_UsartBuff[defUSART],baud);
	return True;
}

RpyStatus writeUsartOpt(enumUsart defUSART,u8* data,u32 len)
{
	if(defUSART >= USTCOUNT || data == NULL)
	{
		return False;
	}	
	for(int i = 0 ; i < len && data[i] != '\0'; i ++)
	{
		USART_WriteByte(sg_UsartBuff[defUSART],data[i]);
	}
	return True;
}

RpyStatus readUsartOpt(enumUsart defUSART,u8 *data,u32 *len)
{
	if(defUSART >= USTCOUNT || data == NULL || len == NULL)
	{
		return False;
	}
	*len = 0;
	while(1)
	{
		if(USART_checkPollRead(sg_UsartBuff[defUSART]) == 0)
				break;
		u8 tmp = USART_ReadByte(sg_UsartBuff[defUSART]);	
		if(data + *len != NULL)
			data[(*len)++] = tmp;
		else
			break;
	}
	return True;
}

RpyStatus setUsartOpt(enumUsart defUSART,u8 mode)
{
	return True;
}
RpyStatus closeUsartOpt(enumUsart defUSART)
{
	return True;
}


















