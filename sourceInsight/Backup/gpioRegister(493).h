#ifndef __GPIOREGISTER_H__
#define	__GPIOREGISTER_H__

#include "stm32F4Define.h"


/*
**************************************************
*FunctionName:	void GPIO_Init(GPIO_TypeDef* port,u8 pin_index,u16 pin_cfg)
*
*Descriptor:	��ʼ��ָ������
*
*Arguments:		port		�˿ڣ�GPIOA~GPIOI
*							pin_index	����ƫ�ƣ�0~15
*							pin_cfg		��������
*
*Returns:		��
*
*Attentions:	��
**************************************************
*/
extern void 	GPIO_Init(GPIO_TypeDef* port,u8 pin_index,u16 pin_cfg);

/*
**************************************************
*FunctionName:	void GPIO_MultiInit(GPIO_TypeDef* port,u16 pin_map,u16 pin_cfg)
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
extern void 	GPIO_MultiInit(GPIO_TypeDef* port,u16 pin_map,u16 pin_cfg);

/*
**************************************************
*FunctionName:	�꺯��@void GPIO_WritePort(GPIO_TypeDef* port,u32 value)
*
*Descriptor:	д�����˿ڵ�ֵ
*
*Arguments:		port		�˿ڣ�GPIOA~GPIOI
*				value		�˿�ֵ
*
*Returns:		��
*
*Attentions:	��
**************************************************
*/
#define	GPIO_WritePort(port,value)		(port->ODR = value)

/*
**************************************************
*FunctionName:	�꺯��@u32 GPIO_ReadPort(GPIO_TypeDef* port)
*
*Descriptor:	 �������˿ڵ�ֵ
*
*Arguments:		port		�˿ڣ�GPIOA~GPIOI
*
*Returns:		�˿ڵ�ֵ
*
*Attentions:	��
**************************************************
*/
#define	GPIO_ReadPort(port)		(port->IDR)

/*
**************************************************
*FunctionName:	�꺯��@void GPIO_WriteBit(GPIO_TypeDef* port,u8 pin_index,u8 value)
*
*Descriptor:	дָ������
*
*Arguments:		port		�˿ڣ�GPIOA~GPIOI
*				pin_index	����ƫ�ƣ�0~15
*				value		����ֵ��0����1
*
*Returns:		��
*
*Attentions:	��
**************************************************
*/
#define	GPIO_WriteBit(port,pin_index,value)		(port->ODR = (port->ODR & (~(1<<pin_index))) | (value == 0 ? 0 : (1<<pin_index)))

/*
**************************************************
*FunctionName:	�꺯��@u8 GPIO_ReadBit(GPIO_TypeDef* port,u8 pin_index)
*
*Descriptor:	��ָ������
*
*Arguments:		port		�˿ڣ�GPIOA~GPIOI
*				pin_index	����ƫ�ƣ�0~15
*
*Returns:		����ֵ
*
*Attentions:	��
**************************************************
*/
#define	GPIO_ReadBit(port,pin_index)			((port->IDR >> pin_index) & 0x01UL)

/*
**************************************************
*FunctionName:	�꺯��@void GPIO_SetBit(GPIO_TypeDef* port,u8 pin_index)
*
*Descriptor:	��ָ��������λ
*
*Arguments:		port		�˿ڣ�GPIOA~GPIOI
*				pin_index	����ƫ�ƣ�0~15
*
*Returns:		��
*
*Attentions:	��
**************************************************
*/
#define	GPIO_SetBit(port,pin_index)				(port->BSRR = 1<<pin_index)

/*
**************************************************
*FunctionName:	�꺯��@void GPIO_ResetBit(GPIO_TypeDef* port,u8 pin_index)
*
*Descriptor:	��ָ����������
*
*Arguments:		port		�˿ڣ�GPIOA~GPIOI
*				pin_index	����ƫ�ƣ�0~15
*
*Returns:		��
*
*Attentions:	��
**************************************************
*/
#define	GPIO_ResetBit(port,pin_index)			(port->BSRR = 1<<(pin_index+15))

/*
**************************************************
*FunctionName:	�꺯��@void GPIO_ToggleBit(GPIO_TypeDef* port,u8 pin_index)
*
*Descriptor:	д�����˿ڵ�ֵ
*
*Arguments:		port		�˿ڣ�GPIOA~GPIOI
*				pin_index	����ƫ�ƣ�0~15
*
*Returns:		��
*
*Attentions:	��
**************************************************
*/
#define	GPIO_ToggleBit(port,pin_index)			(port->ODR ^= 1<<pin_index)

#endif
