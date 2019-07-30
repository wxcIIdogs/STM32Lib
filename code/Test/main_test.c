#include "stm32F4Define.h"

void initDev_test()
{
	GPIO_Init(GPIOE,11,PIN_MODE_OUT);
	GPIO_Init(GPIOE,12,PIN_MODE_OUT);
	
}

void loop_test()
{
	GPIO_ToggleBit(GPIOE,11);
	GPIO_ToggleBit(GPIOE,12);	
}

void main_test()
{
	initDev_test();
	loop_test();
}












