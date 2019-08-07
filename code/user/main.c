#include "stm32F4Define.h"

int fputc(int ch,FILE *file)
{
	sendBuffFifo(0,(uint8_t *)&ch,1,UART_SEND_IO);
	return 1;
}



int main(void)
{
	main_test();
	while(1)
	{
		
	}
}

void SysTick_Handler(void)
{
	//loop_test();
}
