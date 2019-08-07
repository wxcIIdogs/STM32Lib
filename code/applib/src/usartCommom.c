#include "stm32F4Define.h"
#include "dmaOpt.h"



static stuUartRevFifo sg_uartRevFifoBuff[USTCOUNT] = {0};




void 		setUartIntRev(stuUartRevFifo *revinfo);

void 		setUartDmaIdleRev(stuUartRevFifo *revinfo);


/***********************************
*func:
*parm:
*return:
*info:
***********************************/
int32_t getFifoIndex(void)
{
	for(int32_t i = 0 ; i < USTCOUNT ; i ++)
	{
		if(sg_uartRevFifoBuff[i].revCmd == UART_REV_NULL)
			return i;
	}
	return -1;
}

/***********************************
*func:
*parm:
*return:
*info:
***********************************/
int32_t createFifoRev(enumUsart uart , u32 brud,usartRevFunc revFuncParm,u8 revMode)
{	

	int32_t fifoIndex = getFifoIndex();
	assert(fifoIndex != -1);

	sg_uartRevFifoBuff[fifoIndex].uart = sg_UsartBuff[uart];
	sg_uartRevFifoBuff[fifoIndex].uartNum = uart;
	sg_uartRevFifoBuff[fifoIndex].brud= brud;
	sg_uartRevFifoBuff[fifoIndex].revFunc = revFuncParm;
	sg_uartRevFifoBuff[fifoIndex].revCmd = revMode;	
	switch(revMode)
	{
		case UART_REV_DMA:
			setUartDmaIdleRev(sg_uartRevFifoBuff + fifoIndex);
			break;
		case UART_REV_INT:
			setUartIntRev(sg_uartRevFifoBuff + fifoIndex);	
			break;		
	}
	return fifoIndex;
}


/***********************************
*func:
*parm:
*return:
*info:
***********************************/
void delFifoRev(int32_t index)
{
	sg_uartRevFifoBuff[index].revCmd = UART_REV_NULL;
	sg_uartRevFifoBuff[index].revFunc = NULL;
}

/***********************************
*func:
*parm:
*return:
*info:
***********************************/
void sendBuffFifo(int32_t index , uint8_t *buff,int32_t len,int32_t sendMode)
{
	assert(index < USTCOUNT);

	memcpy(sg_uartRevFifoBuff[index].sendBuff,buff,len);
	sg_uartRevFifoBuff[index].sendLen = len;
	if(sendMode == UART_SEND_IO)
	{
		usart_devOpt.write(sg_uartRevFifoBuff[index].uartNum,buff,len);
		//HAL_UART_Transmit(sg_uartRevFifoBuff[index].uart,sg_uartRevFifoBuff[index].sendBuff,sg_uartRevFifoBuff[index].sendLen,0x05);
	}
	else if(sendMode == UART_SEND_ANSY)
	{
		//send data for ansy
		
		//HAL_UART_Transmit_DMA(sg_stufifoList.uart,sg_sendbuff,sg_stufifoList.count));
		//HAL_UART_Transmit_IT(sg_uartRevFifoBuff[index].uart,sg_uartRevFifoBuff[index].sendBuff,sg_uartRevFifoBuff[index].sendLen);
	}
}

/***********************************
*func:
*parm:
*return:
*info:
***********************************/
void USART_IDLE_Handler(USART_TypeDef *huart)
{

	//rev data for dma idle
	stuUartRevFifo *revinfo;
	for(int32_t i = 0 ; i < USTCOUNT ; i ++)
	{
		if(huart == sg_uartRevFifoBuff[i].uart && sg_uartRevFifoBuff[i].revCmd == UART_REV_DMA)
		{
			// is you 
			 revinfo = &(sg_uartRevFifoBuff[i]);
		}
	}	
	DMA_USART_Stop(revinfo->uart);
	u16 temp = UARTINFO_SIZE - DMA_USART_GetRemain(revinfo->uart);
	revinfo->revFunc(revinfo->revBuff,temp);
	memset(revinfo->revBuff,0,UARTINFO_SIZE);
	usartDMAConfig(revinfo->uartNum,revinfo->revBuff ,UARTINFO_SIZE);
}

/***********************************
*func:
*parm:
*return:
*info:
***********************************/
static void setUartIntRev(stuUartRevFifo *revinfo)
{
	//set usart int rev 
	usart_devOpt.open(revinfo->uartNum,revinfo->brud,revinfo->revCmd);
//	HAL_UART_Receive_IT(revinfo->uart,revinfo->revBuff,1);
//	__HAL_UART_ENABLE_IT(revinfo->uart, UART_IT_RXNE);
}

/***********************************
*func:
*parm:
*return:
*info:
***********************************/
static void setUartDmaIdleRev(stuUartRevFifo *revinfo)
{
	//set dma idle
	usart_devOpt.open(revinfo->uartNum,revinfo->brud,revinfo->revCmd);
	usartDMAConfig(revinfo->uartNum,revinfo->revBuff ,UARTINFO_SIZE);
}
//
///***********************************
//*func:
//*parm:
//*return:
//*info:
//***********************************/
void USART_RXNE_Handler(USART_TypeDef *huart)
{
	//rev data
	
}


