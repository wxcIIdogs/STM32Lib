#include "gpioOpt.h"
#include "stm32F4Define.h"



RpyStatus gpioOpen(enumGPIO defGPIO,u16 pin_index,u16 pin_cfg)
{
	assert(defGPIO <= GPI);
	if(initGpioOpt(defGPIO,pin_index,pin_cfg) == False)
	{
		return False;
	}
	return True;
}

RpyStatus gpioWrite(enumGPIO defGPIO,u16 pin_index,u8 data)
{
	if(writeGpioOpt(defGPIO,pin_index,data) == False)
	{
		return False;
	}
	return True;
}

RpyStatus gpioRead(enumGPIO defGPIO,u16 pin_index,u8 *data)
{
	assert(data != NULL);
	if(readGpioOpt(defGPIO,pin_index,data) == False)
	{
		return False;
	}
	
	return True;

}

RpyStatus gpioRelease(enumGPIO defGPIO,u16 pin_index)
{
	gpioIoctl(defGPIO,pin_index,PIN_MODE_AN);
	return True;
}

RpyStatus gpioIoctl(enumGPIO defGPIO,u16 pin_index,u16 pin_cfg)
{
	assert(defGPIO <= GPI);
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




