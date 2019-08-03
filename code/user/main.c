#include "stm32F4Define.h"

int main(void)
{
	SystemInit();
	main_test();
	while(1)
	{
		
	}
}

void SysTick_Handler(void)
{
	//loop_test();
}
