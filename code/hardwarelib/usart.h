#ifndef __USART_H__
#define	__USART_H__

#include "common.h"

#define USART_DATA_LENGTH_8BIT	(0<<0)
#define	USART_DATA_LENGTH_9BIT	(1<<0)

#define	USART_PARITY_NONE		(0<<1)
#define	USART_PARITY_EVEN		(1<<1)
#define	USART_PARITY_ODD		(2<<1)

#define	USART_STOP_1BIT			(0<<3)
#define	USART_STOP_0P5BIT		(1<<3)
#define	USART_STOP_2BIT			(2<<3)
#define	USART_STOP_1P5BIT		(3<<3)

#endif
