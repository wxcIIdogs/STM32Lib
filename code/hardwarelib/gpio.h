#ifndef __GPIO_H__
#define	__GPIO_H__

#include "common.h"

//pin_cfg Bitmap
/*
pin_cfg:
    bit15 bit14 bit13 bit12 bit11 bit10 bit9 bit8 bit7 bit6 bit5 bit4 bit3 bit2 bit1 bit0
    ----------------------- --------------------- ---- ---- --------- --------- ---------
	           |                       |            |    |      |         |         |    
               |                       |            |    |      |         |         |---PIN_MODE������ģʽ
               |                       |            |    |      |         |---PIN_PDU������������ѡ��
               |                       |            |    |      |---PIN_SPD����������ٶ�ѡ��
               |                       |            |    |---PIN_OTP�������������
               |                       |            |---������δʹ��
               |                       |---PIN_AF(n)�����Ÿ��ù���ѡ��                  
               |---������δʹ��
*/
#define	PIN_MODE_IN		(0<<0)	// ����ģʽ(Input)��Ĭ��
#define	PIN_MODE_OUT	(1<<0)	//���ģʽ(General purpose output mode)
#define	PIN_MODE_AF		(2<<0)	//���ù���ģʽ(Alternate function mode)
#define PIN_MODE_AN		(3<<0)	//ģ�⹦��ģʽ(Analog mode)

#define	PIN_PUD_NULL	(0<<2)	//��������(No pull-up,pull-down)��Ĭ��
#define	PIN_PUD_UP		(1<<2)	//����(Pull-up)
#define	PIN_PUD_DOWN	(2<<2)	//����(Pull-down)

#define	PIN_SPD_LS		(0<<4)	//����(Low speed)��Ĭ��
#define	PIN_SPD_MS		(1<<4)	//����(Medium speed)
#define	PIN_SPD_HS		(2<<4)	//����(High speed)
#define	PIN_SPD_VHS		(3<<4)	//�ǳ�����(Very high speed)

#define	PIN_OTP_PP		(0<<6)	//�������(Output push-pull)
#define	PIN_OTP_OD		(1<<6)	//��©���(Output open-drain)

#define	PIN_AF(n)		(n<<8)	//���ù���ѡ��(AFRLy selection)

/*
**************************************************
*FunctionName:	void GPIO_Init(GPIO_TypeDef* port,u8 pin_index,u16 pin_cfg)
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
void GPIO_Init(GPIO_TypeDef* port,u8 pin_index,u16 pin_cfg);

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
void GPIO_MultiInit(GPIO_TypeDef* port,u16 pin_map,u16 pin_cfg);

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
#define	GPIO_WritePort(port,value)		port->ODR = value

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
#define	GPIO_WriteBit(port,pin_index,value)		port->ODR = (port->ODR & (~(1<<pin_index))) | (value == 0 ? 0 : (1<<pin_index))

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
#define	GPIO_SetBit(port,pin_index)				port->BSRR = 1<<pin_index

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
#define	GPIO_ResetBit(port,pin_index)			port->BSRR = 1<<(pin_index+15)

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
#define	GPIO_ToggleBit(port,pin_index)			port->ODR ^= 1<<pin_index

#endif
