#include "stm32F4Define.h"
#include "gpioRegister.h"
#include "gpioOpt.h"



RpyStatus initGpioOpt(enumGPIO defGPIO,u8 pin_index,u16 pin_cfg)
{
	if(pin_index > 15 ||  defGPIO > GPI)
	{
		return False;
	}
	//init gpio 
	GPIO_Init(GET_GPIO_OBJ(defGPIO),pin_index,pin_cfg);
	return True;
}

RpyStatus writeGpioOpt(enumGPIO defGPIO,u8 pin_index,u8 data)
{
	if(pin_index > 15 || defGPIO > GPI )
	{
		return False;
	}
	GPIO_WriteBit(GET_GPIO_OBJ(defGPIO),pin_index,data);
	return True;
}

RpyStatus readGpioOpt(enumGPIO defGPIO,u8 pin_index,u8 *data)
{
	if(pin_index > 15 || defGPIO > GPI || data == NULL)
	{
		return False;
	}
	*data = GPIO_ReadBit(GET_GPIO_OBJ(defGPIO),pin_index);
	return True;
}

RpyStatus ToggleGpioOpt(enumGPIO defGPIO,u8 pin_index,u8 *status)
{
	if(pin_index > 15 || defGPIO > GPI )
	{
		return False;
	}
	GPIO_ToggleBit(GET_GPIO_OBJ(defGPIO),pin_index);
	if(status != NULL)
	{
		*status = GPIO_ReadBit(GET_GPIO_OBJ(defGPIO),pin_index);
	}
	return True;
}

RpyStatus setGpioOpt(enumGPIO defGPIO,u8 pin_index,u8 mode)
{
	return True;
}







