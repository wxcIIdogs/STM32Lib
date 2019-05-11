#ifndef __GPIO_H__
#define	__GPIO_H__

#include "common.h"

//pin_cfg Bitmap
/*
pin_cfg:
    bit15 bit14 bit13 bit12 bit11 bit10 bit9 bit8 bit7 bit6 bit5 bit4 bit3 bit2 bit1 bit0
    ----------------------- --------------------- ---- ---- --------- --------- ---------
	           |                       |            |    |      |         |         |    
               |                       |            |    |      |         |         |---PIN_MODE：引脚模式
               |                       |            |    |      |         |---PIN_PDU：引脚上下拉选择
               |                       |            |    |      |---PIN_SPD：引脚输出速度选择
               |                       |            |    |---PIN_OTP：引脚输出类型
               |                       |            |---保留，未使用
               |                       |---PIN_AF(n)：引脚复用功能选择                  
               |---保留，未使用
*/
#define	PIN_MODE_IN		(0<<0)	// 输入模式(Input)。默认
#define	PIN_MODE_OUT	(1<<0)	//输出模式(General purpose output mode)
#define	PIN_MODE_AF		(2<<0)	//复用功能模式(Alternate function mode)
#define PIN_MODE_AN		(3<<0)	//模拟功能模式(Analog mode)

#define	PIN_PUD_NULL	(0<<2)	//无上下拉(No pull-up,pull-down)。默认
#define	PIN_PUD_UP		(1<<2)	//上拉(Pull-up)
#define	PIN_PUD_DOWN	(2<<2)	//下拉(Pull-down)

#define	PIN_SPD_LS		(0<<4)	//低速(Low speed)。默认
#define	PIN_SPD_MS		(1<<4)	//中速(Medium speed)
#define	PIN_SPD_HS		(2<<4)	//高速(High speed)
#define	PIN_SPD_VHS		(3<<4)	//非常高速(Very high speed)

#define	PIN_OTP_PP		(0<<6)	//推挽输出(Output push-pull)
#define	PIN_OTP_OD		(1<<6)	//开漏输出(Output open-drain)

#define	PIN_AF(n)		(n<<8)	//复用功能选择(AFRLy selection)

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
void GPIO_Init(GPIO_TypeDef* port,u8 pin_index,u16 pin_cfg);

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
void GPIO_MultiInit(GPIO_TypeDef* port,u16 pin_map,u16 pin_cfg);

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
#define	GPIO_WritePort(port,value)		port->ODR = value

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
#define	GPIO_WriteBit(port,pin_index,value)		port->ODR = (port->ODR & (~(1<<pin_index))) | (value == 0 ? 0 : (1<<pin_index))

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
#define	GPIO_SetBit(port,pin_index)				port->BSRR = 1<<pin_index

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
#define	GPIO_ResetBit(port,pin_index)			port->BSRR = 1<<(pin_index+15)

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
#define	GPIO_ToggleBit(port,pin_index)			port->ODR ^= 1<<pin_index

#endif
