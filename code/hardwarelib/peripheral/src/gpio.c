#include "gpioOpt.h"
#include "stm32F4Define.h"



RpyStatus gpioOpen()
{
	
}

RpyStatus gpioWrite(enumGPIO defGPIO,u8* pin_index,u8 *data)
{
	if(data  == NULL || pin_index == NULL)
	{
		return False;
	}
	while(pin_index != NULL && data != NULL)
	{
		if(writeGpioOpt(defGPIO,*pin_index,*data) == False)
		{
			return False;
		}
		pin_index ++;
		data++;
	}
	return True;
}

RpyStatus gpioRead(enumGPIO defGPIO,u8* pin_index,u8 *data)
{
	if(data  == NULL || pin_index == NULL)
	{
		return False;
	}
	while(pin_index != NULL && data != NULL)
	{
		if(readGpioOpt(defGPIO,*pin_index,data) == False)
		{
			return False;
		}
		pin_index ++;
		data++;
	}
	return True;
}

RpyStatus gpioRelease()
{
	
}

RpyStatus gpioIoctl(enumGPIO defGPIO,u8* pin_index,u16 pin_cfg)
{
	if(pin_cfg > PIN_OTP_OD || defGPIO > GPI || pin_index == NULL)
	{
		return False;
	}
	while(pin_index != NULL)
	{
		if(initGpioOpt(defGPIO,*pin_index,pin_cfg) == False)
		{
			return False;
		}
		pin_index ++;
	}
	return True;
}


gpio_Operation gpio_devOpt = 
{
	.open = gpioOpen,
	.write = gpioWrite,
	.read = gpioRead,
	.release = gpioRelease,
	.ioctl = gpioIoctl,
};

