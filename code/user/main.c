#include "stm32F4Define.h"


void SystemInit(void)
{
	
}

int main(void)
{
	//SysTick_Config(1600000-1);
	initDev_test();
	while(1)
	{
		
	}
}

void SysTick_Handler(void)
{
	loop_test();
}
