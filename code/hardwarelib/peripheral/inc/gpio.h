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


#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected    */
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected    */
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected    */
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected    */
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected   */
#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected */

#define GPIO_PIN_MASK              0x0000FFFFU /* PIN mask for assert test */




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
	RpyStatus (*open)(enumGPIO defGPIO,u16 pin_index,u16 pin_cfg);		
	RpyStatus (*write)(enumGPIO defGPIO,u16 pin_index,u8 data);
	RpyStatus (*read)(enumGPIO defGPIO,u16 pin_index,u8 *data);
	RpyStatus (*ioctl)(enumGPIO defGPIO,u16 pin_index,u16 pin_cfg);
	RpyStatus (*release)(enumGPIO defGPIO,u16 pin_index);
}gpio_Operation;//STMOperations

extern gpio_Operation 	gpio_devOpt;











#endif
