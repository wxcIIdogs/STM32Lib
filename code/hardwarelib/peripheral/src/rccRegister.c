#include "rccRegister.h"
#include "stm32F4Define.h"

SystemClock_Typedef SystemClock= {168000000,168000000,168000000,42000000,84000000};
void SystemInitRegister(void)
{
	//Enable HSE
	RCC->CR |= RCC_CR_HSEON;
	while((RCC->CR & RCC_CR_HSERDY) == 0);
	
	//Config PLL:SRC=HSE,PLLQ=7,PLLP=2,PLLN=336,PLLM=8
	RCC->PLLCFGR = \
	(RCC_PLLCFGR_PLLSRC) | \
	(7UL << RCC_PLLCFGR_PLLQ_Pos) | \
	(0UL << RCC_PLLCFGR_PLLP_Pos) | \
	(336UL << RCC_PLLCFGR_PLLN_Pos) | \
	(8UL << RCC_PLLCFGR_PLLM_Pos);
	
	//Enable PLL
	RCC->CR |= RCC_CR_PLLON;
	while((RCC->CR & RCC_CR_PLLRDY) == 0);
	
	//Config APB1,APB2
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2 | RCC_CFGR_PPRE2_DIV4;
	
	//Config Flash latency
	FLASH->ACR = (FLASH->ACR & (~FLASH_ACR_LATENCY_Msk)) | FLASH_ACR_LATENCY_5WS;
	
	//switch system clock to PLL's output
	RCC->CFGR = (RCC->CFGR & (~RCC_CFGR_SW_Msk)) | RCC_CFGR_SW_PLL;
	while((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_PLL);
}


