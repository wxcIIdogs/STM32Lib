#ifndef __COMMON_H__
#define	__COMMON_H__

#include "stm32f4xx.h"                  // Device header

#ifndef u8
	#define	u8 uint8_t
#endif

#ifndef vu8
	#define	vu8	volatile uint8_t
#endif

#ifndef s8
	#define	s8 int8_t
#endif
	
#ifndef vs8
	#define	vs8	volatile int8_t
#endif
	
#ifndef	u16
	#define	u16	uint16_t
#endif

#ifndef	vu16
	#define	vu16 volatile uint16_t
#endif
	
#ifndef	s16
	#define	s16	int16_t
#endif
	
#ifndef	vs16
	#define	vs16 volatile int16_t
#endif

#ifndef	u32
	#define	u32	uint32_t
#endif

#ifndef	vu32
	#define	vu32 volatile uint32_t
#endif
	
#ifndef	s32
	#define	s32 int32_t
#endif
	
#ifndef	vs32
	#define	vs32 volatile int32_t
#endif
	
#ifndef u64
	#define	u64 uint64_t
#endif
	
#ifndef vu64
	#define	vu64 volatile uint64_t
#endif
	
#ifndef s64
	#define	s64 int64_t
#endif
	
#ifndef vs64
	#define	vs64 volatile int64_t
#endif
	
#ifndef	true
	#define	true  (1UL)
#endif

#ifndef	false
	#define	false (0UL)
#endif
	
typedef enum 
{
	True = 0U,	
	False = !True,
}RpyStatus;
	
typedef struct
{
	u32 AHB1Clock;
	u32 AHB2Clock;
	u32 AHB3Clock;
	u32 APB1Clock;
	u32 APB2Clock;
}SystemClock_Typedef;

extern SystemClock_Typedef SystemClock;




#endif
