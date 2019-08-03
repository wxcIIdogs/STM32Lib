#ifndef __GPIOOPT_H__
#define	__GPIOOPT_H__

#include "stm32F4Define.h"
#include "gpioRegister.h"



#define	 GET_GPIO_OBJ(__X__)			((GPIO_TypeDef *)((__X__) * 0x400 + GPIOA_BASE))


extern RpyStatus 			initGpioOpt(enumGPIO defGPIO,u8 pin_index,u16 pin_cfg);
extern RpyStatus 			writeGpioOpt(enumGPIO defGPIO,u8 pin_index,u8 data);
extern RpyStatus 			readGpioOpt(enumGPIO defGPIO,u8 pin_index,u8 *data);
extern RpyStatus 			ToggleGpioOpt(enumGPIO defGPIO,u8 pin_index,u8 *status);
extern RpyStatus 			setGpioOpt(enumGPIO defGPIO,u8 pin_index,u8 mode);
#endif
