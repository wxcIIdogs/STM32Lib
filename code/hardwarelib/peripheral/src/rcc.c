#include "rcc.h"

SystemClock_Typedef SystemClock;
void SystemInit(void)
{
	SystemClock.AHB1Clock = 16000000;
    SystemClock.AHB2Clock = 16000000;
	SystemClock.AHB3Clock = 16000000;
	SystemClock.APB1Clock = 16000000;
	SystemClock.APB2Clock = 16000000;
}