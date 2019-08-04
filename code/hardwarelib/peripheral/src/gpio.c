#include "gpioOpt.h"
#include "stm32F4Define.h"



RpyStatus gpioOpen()
{
	return True;
}

RpyStatus gpioWrite(enumGPIO defGPIO,u8 pin_index,u8 data)
{
	if(writeGpioOpt(defGPIO,pin_index,data) == False)
	{
		return False;
	}
	return True;
}

RpyStatus gpioRead(enumGPIO defGPIO,u8 pin_index,u8 *data)
{
	if(data  == NULL)
	{
		return False;
	}
	if(data != NULL)
	{
		if(readGpioOpt(defGPIO,pin_index,data) == False)
		{
			return False;
		}
	}
	return True;
}

RpyStatus gpioRelease()
{
	return True;
}

RpyStatus gpioIoctl(enumGPIO defGPIO,u8 pin_index,u16 pin_cfg)
{
	if(defGPIO > GPI)
	{
		return False;
	}
	if(initGpioOpt(defGPIO,pin_index,pin_cfg) == False)
	{
		return False;
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

