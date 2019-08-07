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

static u32 sg_Usart1Index = 0;
void usart1RevFunc(u8 *buff,u32 len)
{
	//sendBuffFifo(sg_Usart1Index,buff,len,UART_SEND_IO);
	if(len != 100)
		printf("error:%s,len = %d\r\n",buff,len);
	static u32 sum = 0;
	sum += len;
	if(strcmp((char *)buff,"reset") == 0)
	{
		sum = 0;
		printf("reset:sum = %d\r\n",sum);
	}
	else		
	//sendBuffFifo(sg_Usart1Index,buff,len,UART_SEND_IO);
		printf("sum = %d\r\n",sum);
}

void initDev_test()
{
	sg_Usart1Index = createFifoRev(UST1, 115200, usart1RevFunc, UART_REV_DMA);
	gpio_devOpt.open(GPE,GPIO_PIN_11,PIN_MODE_OUT);
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













