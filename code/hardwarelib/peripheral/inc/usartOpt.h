#ifndef __USARTOPT_H__
#define	__USARTOPT_H__
#include "usartRegister.h"
#include "stm32F4Define.h"


extern RpyStatus 	initUsartOpt(enumUsart defUSART,u32 baud);
extern RpyStatus 	writeUsartOpt(enumUsart defUSART,u8* data,u32 len);
extern RpyStatus 	readUsartOpt(enumUsart defUSART,u8 *data,u32 *len);
extern RpyStatus 	setUsartOpt(enumUsart defUSART,u8 mode);
extern RpyStatus 	closeUsartOpt(enumUsart defUSART);
#endif
