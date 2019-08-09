
#include "stm32F4Define.h"


stuAnalyInfo sg_analyBuff[USTCOUNT];

RpyStatus initUsartAnaly(int index,u8 revBuffLen)
{
	assert(index >=0);
	assert(index < USTCOUNT);
	sg_analyBuff[index].m_status = m_head;
	sg_analyBuff[index].m_usart = sg_UsartBuff[index];		
	sg_analyBuff[index].m_dataBuff = (u8 *)malloc(revBuffLen);
	sg_analyBuff[index].m_timeCount = 0;
	sg_analyBuff[index].m_timeOut = 50;
	return True;
}

RpyStatus setUsartAnalyHead(int index,u8 head)
{
	assert(index >=0);
	assert(index < USTCOUNT);
	sg_analyBuff[index].m_Head = head;
	return True;
}

RpyStatus setUsartAnalyTimeOut(int index,u32 timeout)
{
	assert(index >=0);
	assert(index < USTCOUNT);
	sg_analyBuff[index].m_timeOut = timeout;
	return True;
}

stuAnalyInfo *getAnalyForUsart(USART_TypeDef *usart)
{
	for(int i = 0; i < USTCOUNT ; i ++)
	{
		if(usart == sg_analyBuff[i].m_usart)
			return sg_analyBuff + i;
	}
	return NULL;
}

void inputAnalyData(u8 *revData,u8 revlen,USART_TypeDef *usart)
{
	stuAnalyInfo *temp = getAnalyForUsart(usart);
	if(temp == NULL)
		return;
	//checkout 50ms
	if(stm_getTick() - temp->m_timeCount > temp->m_timeOut)
	{
		temp->m_status = m_funcode;
	}
	temp->m_timeCount = stm_getTick();
	for(int i = 0 ; i < revlen ; i ++)
	{
		u8 data = revData[i];
		switch (temp->m_status)
		{
			case m_head:
				if(data == temp->m_Head)
				{
					temp->m_status = m_funcode;
					temp->m_count  = 0;
					temp->m_crc = 0;					
				}
				break;
			case m_funcode:
				temp->m_status = m_dataLen;
				temp->m_funcode = data;
				temp->m_crc += data;
				break;
			case m_dataLen:
				temp->m_status = m_data;
				temp->m_dataLen = data;
				temp->m_crc += data;
				break;
			case m_data:
				if(temp->m_count ++ == temp->m_dataLen)
				{
					temp->m_status = m_crc;					
					temp->m_count  = 0;					
				}

				else
				{
					if(temp->m_dataBuff != NULL)
						temp->m_dataBuff[temp->m_count - 1] = data;
					temp->m_crc += data;
				}
				break;
			case m_crc:
				if(data == temp->m_crc)
				{
					//crc success
					
				}
				temp->m_status = m_head;
				break;			
		}
	}
		
}





















