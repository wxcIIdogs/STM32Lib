#include "stm32F4Define.h"

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
	u8 gpio_pin[] = {GPIO_PIN_11};
	
	gpio_devOpt.open();
	
	gpio_devOpt.ioctl(GPE,gpio_pin,PIN_MODE_OUT);
//	gpio_devOpt.ioctl(GPA,GPIO_PIN_9,PIN_MODE_AF | PIN_SPD_VHS | PIN_OTP_PP | PIN_AF(7));
//	gpio_devOpt.ioctl(GPA,GPIO_PIN_10,PIN_MODE_AF | PIN_SPD_VHS | PIN_OTP_PP | PIN_AF(7));
	//GPIO_Init(GPIOE,11,PIN_MODE_OUT);
//	GPIO_Init(GPIOA,9,PIN_MODE_AF | PIN_SPD_VHS | PIN_OTP_PP | PIN_AF(7));
//	GPIO_Init(GPIOA,10,PIN_MODE_AF | PIN_SPD_VHS | PIN_OTP_PP | PIN_AF(7));
//	USART_Init(USART1,115200);
//	USART_InterruptEnable(USART1,m_usart_isr_rxne);
}

void loop_test()
{
	//GPIO_ToggleBit(GPIOE,11);
	
}

void main_test()
{
	initDev_test();
	while(1)
	{
		loop_test();
	}
	
}













