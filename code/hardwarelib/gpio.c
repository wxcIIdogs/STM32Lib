#include "gpio.h"

static const uint32_t MaskTable_2Bit[16] = 
{
	~(3UL<<0),	~(3UL<<2),	~(3UL<<4),	~(3UL<<6),
	~(3UL<<8),	~(3UL<<10),	~(3UL<<12),	~(3UL<<14),
	~(3UL<<16),	~(3UL<<18),	~(3UL<<20),	~(3UL<<22),
	~(3UL<<24),	~(3UL<<26),	~(3UL<<28),	~(3UL<<30)
};

/*
**************************************************
*FunctionName:	void GPIO_Init(GPIO_TypeDef* port,uint8_t pin_index,uint16_t pin_cfg)
*
*Descriptor:	��ʼ��ָ������
*
*Arguments:		port		�˿ڣ�GPIOA~GPIOI
*				pin_index	����ƫ�ƣ�0~15
*				pin_cfg		��������
*
*Returns:		��
*
*Attentions:	��
**************************************************
*/
void GPIO_Init(GPIO_TypeDef* port,uint8_t pin_index,uint16_t pin_cfg)
{
	if(pin_index > 15)
	{
		return;
	}
	switch((uint32_t)port)
	{
		case GPIOA_BASE:
		{
			if((RCC->AHB1ENR & RCC_AHB1ENR_GPIOAEN) == 0)
			{
				RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
			}
		}break;
		case GPIOB_BASE:
		{
			if((RCC->AHB1ENR & RCC_AHB1ENR_GPIOBEN) == 0)
			{
				RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
			}
		}break;
		case GPIOC_BASE:
		{
			if((RCC->AHB1ENR & RCC_AHB1ENR_GPIOCEN) == 0)
			{
				RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
			}
		}break;
		case GPIOD_BASE:
		{
			if((RCC->AHB1ENR & RCC_AHB1ENR_GPIODEN) == 0)
			{
				RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
			}
		}break;
		case GPIOF_BASE:
		{
			if((RCC->AHB1ENR & RCC_AHB1ENR_GPIOFEN) == 0)
			{
				RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
			}
		}break;
		case GPIOG_BASE:
		{
			if((RCC->AHB1ENR & RCC_AHB1ENR_GPIOFEN) == 0)
			{
				RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
			}
		}break;
		case GPIOH_BASE:
		{
			if((RCC->AHB1ENR & RCC_AHB1ENR_GPIOFEN) == 0)
			{
				RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
			}
		}break;
		case GPIOI_BASE:
		{
			if((RCC->AHB1ENR & RCC_AHB1ENR_GPIOFEN) == 0)
			{
				RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
			}
		}break;
		default:return;
	}
	port->MODER = 	(port->MODER & MaskTable_2Bit[pin_index]) 	| ((uint32_t)((pin_cfg>>0) & 0x0003) << (pin_index*2));
	port->PUPDR = 	(port->PUPDR & MaskTable_2Bit[pin_index]) 	| ((uint32_t)((pin_cfg>>2) & 0x0003) << (pin_index*2));
	port->OSPEEDR =	(port->OSPEEDR & MaskTable_2Bit[pin_index]) | ((uint32_t)((pin_cfg>>4) & 0x0003) << (pin_index*2));
	port->OTYPER = 	(port->OTYPER & (~(1<<pin_cfg))) 			| ((uint32_t)((pin_cfg>>6) & 0x0001) << pin_index);
	if(pin_index < 8)
	{
		port->AFR[0] = (port->AFR[0] & (~(0x0FUL << (pin_index*4)))) | ((uint32_t)((pin_cfg>>8) & 0x000F) << (pin_index*4));
	}
	else
	{
		port->AFR[1] = (port->AFR[1] & (~(0x0FUL << (pin_index*4-32)))) | ((uint32_t)((pin_cfg>>8) & 0x000F) << (pin_index*4-32));
	}
}

/*
**************************************************
*FunctionName:	void GPIO_MultiInit(GPIO_TypeDef* port,uint16_t pin_map,uint16_t pin_cfg)
*
*Descriptor:	ͬһ�˿ڶ�����ų�ʼ��Ϊͬһ����
*
*Arguments:		port		�˿ڣ�GPIOA~GPIOI
*				pin_map		����bitmap���
*				pin_cfg		������
*
*Returns:		��
*
*Attentions:	��
**************************************************
*/
void GPIO_MultiInit(GPIO_TypeDef* port,uint16_t pin_map,uint16_t pin_cfg)
{
	for(uint8_t i=0;i<16;i++)
	{
		if(pin_map & (1<<i))
		{
			GPIO_Init(port,i,pin_cfg);
		}
	}
}
