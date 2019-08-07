#include "stm32F4Define.h"
#include "gpioRegister.h"
#include "gpioOpt.h"



RpyStatus initGpioOpt(enumGPIO defGPIO,u16 pin_index,u16 pin_cfg)
{

	//init gpio 
	assert(defGPIO <= GPI);
	for(u8 i = 0 ; i < 16; i ++)
	{
		if(pin_index & (0x0001 << i))			
		{
			GPIO_Init(GET_GPIO_OBJ(defGPIO),i,pin_cfg);

		}		
	}
	return True;
}

RpyStatus writeGpioOpt(enumGPIO defGPIO,u16 pin_index,u8 data)
{
	assert(defGPIO <= GPI);

	for(u8 i = 0 ; i < 16; i ++)
	{
		if(pin_index & (0x0001 << i))			
		{
			GPIO_WriteBit(GET_GPIO_OBJ(defGPIO),i,data);
		}		
	}
	
	return True;
}

RpyStatus readGpioOpt(enumGPIO defGPIO,u16 pin_index,u8 *data)
{
	assert(defGPIO <= GPI);
	assert(pin_index > 15);
	*data = GPIO_ReadBit(GET_GPIO_OBJ(defGPIO),pin_index);
	return True;
}

RpyStatus ToggleGpioOpt(enumGPIO defGPIO,u16 pin_index)
{
	assert(defGPIO <= GPI);
	for(u8 i = 0 ; i < 16; i ++)
	{
		if(pin_index & (0x0001 << i))			
		{
			GPIO_ToggleBit(GET_GPIO_OBJ(defGPIO),i);
		}		
	}
	return True;
}

RpyStatus setGpioOpt(enumGPIO defGPIO,u16 pin_index,u16 pin_cfg)
{
	assert(defGPIO <= GPI);
	for(u8 i = 0 ; i < 16; i ++)
	{
		if(pin_index & (0x0001 << i))			
		{
			GPIO_Init(GET_GPIO_OBJ(defGPIO),i,pin_cfg);

		}		
	}
	return True;
}




