#include "stm32F4Define.h"


void delay(u32 ms)
{
	int time = 100000;
	while(ms--)
	{
		if(time-- == 0)
		{
			time = 100000;
		}
	}
}


void USART1_TXE_Handler(void)
{
	
}
void USART1_RXNE_Handler(void)
{
	//u8 value = USART_ReadByte(USART1);
//	if((value >= 97) && (value <= 122))	//大写字母转小写
//	{
//		value -= 32;
//	}
//	USART_WriteByte(USART1,value);
}
void USART1_TC_Handler(void)
{
	
}
void USART1_IDLE_Handler(void)
{
	
}

void initDev_test()
{
	gpio_devOpt.open(GPE,GPIO_PIN_11,PIN_MODE_OUT);
	
	usart_devOpt.open(UST1,115200,m_usart_dma);
}

void loop_test()
{
	u8 revbuff[100];
	u32 revLen = 0;
	static u8 gpstatus = 0;
	gpio_devOpt.write(GPE,GPIO_PIN_11,gpstatus);
	gpstatus = !gpstatus;
	usart_devOpt.read(UST1,revbuff,&revLen);
	if(revLen != 0)
		usart_devOpt.write(UST1,revbuff,revLen);
	delay(1000000);
}

void main_test()
{
	initDev_test();
	while(1)
	{
		loop_test();
	}
	
}













