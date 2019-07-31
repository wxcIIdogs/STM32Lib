#ifndef __GPIO_H__
#define	__GPIO_H__

#include "stm32F4Define.h"



//pin_cfg Bitmap
/*
pin_cfg:
    bit15 bit14 bit13 bit12 bit11 bit10 bit9 bit8 bit7 bit6 bit5 bit4 bit3 bit2 bit1 bit0
    ----------------------- --------------------- ---- ---- --------- --------- ---------
	           |                       |            |    |      |         |         |    
               |                       |            |    |      |         |         |---PIN_MODE
               |                       |            |    |      |         |---PIN_PDU
               |                       |            |    |      |---PIN_SPD
               |                       |            |    |---PIN_OTP
               |                       |            |---reserved
               |                       |---PIN_AF(n)                
               |---reserved
*/

#define	PIN_MODE_IN		(0<<0)	//(Input)
#define	PIN_MODE_OUT	(1<<0)	//(General purpose output mode)
#define	PIN_MODE_AF		(2<<0)	//(Alternate function mode)
#define PIN_MODE_AN		(3<<0)	//(Analog mode)

#define	PIN_PUD_NULL	(0<<2)	//(No pull-up,pull-down)
#define	PIN_PUD_UP		(1<<2)	//(Pull-up)
#define	PIN_PUD_DOWN	(2<<2)	//(Pull-down)

#define	PIN_SPD_LS		(0<<4)	//(Low speed)
#define	PIN_SPD_MS		(1<<4)	//(Medium speed)
#define	PIN_SPD_HS		(2<<4)	//High speed)
#define	PIN_SPD_VHS		(3<<4)	//(Very high speed)

#define	PIN_OTP_PP		(0<<6)	//(Output push-pull)
#define	PIN_OTP_OD		(1<<6)	//(Output open-drain)

#define	PIN_AF(n)		(n<<8)	//(AFRLy selection)


typedef enum
{
	PIN_GPIO_0 = 0,
	PIN_GPIO_1,
	PIN_GPIO_2,
	PIN_GPIO_3,
	PIN_GPIO_4,
	PIN_GPIO_5,
	PIN_GPIO_6,
	PIN_GPIO_7,
	PIN_GPIO_8,
	PIN_GPIO_9,
	PIN_GPIO_10,
	PIN_GPIO_11,
	PIN_GPIO_12,
	PIN_GPIO_13,
	PIN_GPIO_14,
	PIN_GPIO_15,
}enumPinGpio;



typedef enum
{
	GPA = 0,
	GPB,
	GPC,
	GPD,
	GPE,
	GPF,
	GPG,
	GPH,
	GPI,	
}enumGPIO;


typedef struct// ops
{
	RpyStatus (*open)(void);		
	RpyStatus (*write)(enumGPIO defGPIO,u8* pin_index,u8 *data);
	RpyStatus (*read)(enumGPIO defGPIO,u8* pin_index,u8 *data);
	RpyStatus (*ioctl)(enumGPIO defGPIO,u8* pin_index,u16 pin_cfg);
	RpyStatus (*release)(void);
}gpio_Operation;//STMOperations

extern gpio_Operation 	gpio_devOpt;











#endif
