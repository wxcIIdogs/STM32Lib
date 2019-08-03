#ifndef __GPIOREGISTER_H__
#define	__GPIOREGISTER_H__

#include "stm32F4Define.h"


/*
**************************************************
*FunctionName:	void GPIO_Init(GPIO_TypeDef* port,u8 pin_index,u16 pin_cfg)
*
*Descriptor:	初始化指定引脚
*
*Arguments:		port		端口：GPIOA~GPIOI
*							pin_index	引脚偏移：0~15
*							pin_cfg		引脚配置
*
*Returns:		无
*
*Attentions:	无
**************************************************
*/
extern void 	GPIO_Init(GPIO_TypeDef* port,u8 pin_index,u16 pin_cfg);

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
extern void 	GPIO_MultiInit(GPIO_TypeDef* port,u16 pin_map,u16 pin_cfg);

/*
**************************************************
*FunctionName:	宏函数@void GPIO_WritePort(GPIO_TypeDef* port,u32 value)
*
*Descriptor:	写整个端口的值
*
*Arguments:		port		端口：GPIOA~GPIOI
*				value		端口值
*
*Returns:		无
*
*Attentions:	无
**************************************************
*/
#define	GPIO_WritePort(port,value)		(port->ODR = value)

/*
**************************************************
*FunctionName:	宏函数@u32 GPIO_ReadPort(GPIO_TypeDef* port)
*
*Descriptor:	 读整个端口的值
*
*Arguments:		port		端口：GPIOA~GPIOI
*
*Returns:		端口的值
*
*Attentions:	无
**************************************************
*/
#define	GPIO_ReadPort(port)		(port->IDR)

/*
**************************************************
*FunctionName:	宏函数@void GPIO_WriteBit(GPIO_TypeDef* port,u8 pin_index,u8 value)
*
*Descriptor:	写指定引脚
*
*Arguments:		port		端口：GPIOA~GPIOI
*				pin_index	引脚偏移：0~15
*				value		引脚值：0或者1
*
*Returns:		无
*
*Attentions:	无
**************************************************
*/
#define	GPIO_WriteBit(port,pin_index,value)		(port->ODR = (port->ODR & (~(1<<pin_index))) | (value == 0 ? 0 : (1<<pin_index)))

/*
**************************************************
*FunctionName:	宏函数@u8 GPIO_ReadBit(GPIO_TypeDef* port,u8 pin_index)
*
*Descriptor:	读指定引脚
*
*Arguments:		port		端口：GPIOA~GPIOI
*				pin_index	引脚偏移：0~15
*
*Returns:		引脚值
*
*Attentions:	无
**************************************************
*/
#define	GPIO_ReadBit(port,pin_index)			((port->IDR >> pin_index) & 0x01UL)

/*
**************************************************
*FunctionName:	宏函数@void GPIO_SetBit(GPIO_TypeDef* port,u8 pin_index)
*
*Descriptor:	将指定引脚置位
*
*Arguments:		port		端口：GPIOA~GPIOI
*				pin_index	引脚偏移：0~15
*
*Returns:		无
*
*Attentions:	无
**************************************************
*/
#define	GPIO_SetBit(port,pin_index)				(port->BSRR = 1<<pin_index)

/*
**************************************************
*FunctionName:	宏函数@void GPIO_ResetBit(GPIO_TypeDef* port,u8 pin_index)
*
*Descriptor:	将指定引脚清零
*
*Arguments:		port		端口：GPIOA~GPIOI
*				pin_index	引脚偏移：0~15
*
*Returns:		无
*
*Attentions:	无
**************************************************
*/
#define	GPIO_ResetBit(port,pin_index)			(port->BSRR = 1<<(pin_index+15))

/*
**************************************************
*FunctionName:	宏函数@void GPIO_ToggleBit(GPIO_TypeDef* port,u8 pin_index)
*
*Descriptor:	写整个端口的值
*
*Arguments:		port		端口：GPIOA~GPIOI
*				pin_index	引脚偏移：0~15
*
*Returns:		无
*
*Attentions:	无
**************************************************
*/
#define	GPIO_ToggleBit(port,pin_index)			(port->ODR ^= 1<<pin_index)

#endif
