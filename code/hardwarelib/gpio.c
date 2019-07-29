#include "gpio.h"

static const u32 MaskTable_2Bit[16] = 
{
	~(3UL<<0),	~(3UL<<2),	~(3UL<<4),	~(3UL<<6),
	~(3UL<<8),	~(3UL<<10),	~(3UL<<12),	~(3UL<<14),
	~(3UL<<16),	~(3UL<<18),	~(3UL<<20),	~(3UL<<22),
	~(3UL<<24),	~(3UL<<26),	~(3UL<<28),	~(3UL<<30)
};

/*
**************************************************
*FunctionName:	void GPIO_Init(GPIO_TypeDef* port,u8 pin_index,u16 pin_cfg)
*
*Descriptor:	初始化指定引脚
*
*Arguments:		port		端口：GPIOA~GPIOI
*				pin_index	引脚偏移：0~15
*				pin_cfg		引脚配置
*
*Returns:		无
*
*Attentions:	无
**************************************************
*/
void GPIO_Init(GPIO_TypeDef* port,u8 pin_index,u16 pin_cfg)
{
	if(pin_index > 15)
	{
		return;
	}
	switch((u32)port)
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
		case GPIOE_BASE:
		{
			if((RCC->AHB1ENR & RCC_AHB1ENR_GPIOFEN) == 0)
			{
				RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
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
	port->MODER = 	(port->MODER & MaskTable_2Bit[pin_index]) 	| ((u32)((pin_cfg>>0) & 0x0003) << (pin_index*2));
	port->PUPDR = 	(port->PUPDR & MaskTable_2Bit[pin_index]) 	| ((u32)((pin_cfg>>2) & 0x0003) << (pin_index*2));
	port->OSPEEDR =	(port->OSPEEDR & MaskTable_2Bit[pin_index]) | ((u32)((pin_cfg>>4) & 0x0003) << (pin_index*2));
	port->OTYPER = 	(port->OTYPER & (~(1<<pin_cfg))) 			| ((u32)((pin_cfg>>6) & 0x0001) << pin_index);
	if(pin_index < 8)
	{
		port->AFR[0] = (port->AFR[0] & (~(0x0FUL << (pin_index*4)))) | ((u32)((pin_cfg>>8) & 0x000F) << (pin_index*4));
	}
	else
	{
		port->AFR[1] = (port->AFR[1] & (~(0x0FUL << (pin_index*4-32)))) | ((u32)((pin_cfg>>8) & 0x000F) << (pin_index*4-32));
	}
}

/*
**************************************************
*FunctionName:	void GPIO_MultiInit(GPIO_TypeDef* port,u16 pin_map,u16 pin_cfg)
*
*Descriptor:	同一端口多个引脚初始化为同一配置
*
*Arguments:		port		端口：GPIOA~GPIOI
*				pin_map		引脚bitmap组合
*				pin_cfg		脚配置
*
*Returns:		无
*
*Attentions:	无
**************************************************
*/
void GPIO_MultiInit(GPIO_TypeDef* port,u16 pin_map,u16 pin_cfg)
{
	for(u8 i=0;i<16;i++)
	{
		if(pin_map & (1<<i))
		{
			GPIO_Init(port,i,pin_cfg);
		}
	}
}
