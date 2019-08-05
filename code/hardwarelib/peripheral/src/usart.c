#include "usartOpt.h"
#include "stm32F4Define.h"



RpyStatus usartOpen(enumUsart defUSART,u32 baud,enumUSART_Mode mode)
{
	//gpio_devOpt.ioctl(GPE,s_gpio_pin,PIN_MODE_OUT);
	switch((u8)defUSART)
	{
		case UST1:					
			gpio_devOpt.open(GPA,GPIO_PIN_9,PIN_MODE_AF | PIN_SPD_VHS | PIN_OTP_PP | PIN_AF(7));
			gpio_devOpt.open(GPA,GPIO_PIN_10,PIN_MODE_AF | PIN_SPD_VHS | PIN_OTP_PP | PIN_AF(7));
			break;
		case UST2:
			gpio_devOpt.open(GPA,GPIO_PIN_9,PIN_MODE_AF | PIN_SPD_VHS | PIN_OTP_PP | PIN_AF(7));
			gpio_devOpt.open(GPA,GPIO_PIN_10,PIN_MODE_AF | PIN_SPD_VHS | PIN_OTP_PP | PIN_AF(7));
			break;		
		case UST3:
			gpio_devOpt.open(GPA,GPIO_PIN_9,PIN_MODE_AF | PIN_SPD_VHS | PIN_OTP_PP | PIN_AF(7));
			gpio_devOpt.open(GPA,GPIO_PIN_10,PIN_MODE_AF | PIN_SPD_VHS | PIN_OTP_PP | PIN_AF(7));			
			break;	
		case UST4:
			gpio_devOpt.open(GPA,GPIO_PIN_9,PIN_MODE_AF | PIN_SPD_VHS | PIN_OTP_PP | PIN_AF(7));
			gpio_devOpt.open(GPA,GPIO_PIN_10,PIN_MODE_AF | PIN_SPD_VHS | PIN_OTP_PP | PIN_AF(7));			
			break;	
		case UST5:
			gpio_devOpt.open(GPA,GPIO_PIN_9,PIN_MODE_AF | PIN_SPD_VHS | PIN_OTP_PP | PIN_AF(7));
			gpio_devOpt.open(GPA,GPIO_PIN_10,PIN_MODE_AF | PIN_SPD_VHS | PIN_OTP_PP | PIN_AF(7));			
			break;	
		case UST6:
			
			gpio_devOpt.open(GPA,GPIO_PIN_9,PIN_MODE_AF | PIN_SPD_VHS | PIN_OTP_PP | PIN_AF(7));
			gpio_devOpt.open(GPA,GPIO_PIN_10,PIN_MODE_AF | PIN_SPD_VHS | PIN_OTP_PP | PIN_AF(7));			
			break;	
	}
	initUsartOpt(defUSART,baud);
	return True; 
}

usart_Operation usart_devOpt = 
{
	.open = usartOpen,
	.write = writeUsartOpt,
	.read = readUsartOpt,
	.release = closeUsartOpt,
	.ioctl = setUsartOpt,
};

