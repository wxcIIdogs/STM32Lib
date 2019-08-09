#include "stm32F4Define.h"



stuRevFifo sg_revFifoHead[USTCOUNT];
stuRevFifo* sg_revFifoPoint[USTCOUNT];


RpyStatus initUsartRevFifo(int index)
{
	assert(index >=0);
	assert(index < USTCOUNT);
	sg_revFifoHead[index].m_next = NULL;
	sg_revFifoHead[index].m_usart = sg_UsartBuff[index];
	sg_revFifoPoint[index] = sg_revFifoHead + index;
	return True;
}

stuRevFifo *getRevDataForUsart(USART_TypeDef *usart)
{
	for(int i = 0; i < USTCOUNT ; i ++)
	{
		if(usart == sg_revFifoHead[i].m_usart)
			return sg_revFifoPoint[i];
	}
	return NULL;
}


RpyStatus insertUsartRevData(stuAnalyInfo *revData)
{
	stuRevFifo* point = getRevDataForUsart(revData->m_usart);
	stuRevFifo *newPoint = (stuRevFifo *)malloc(sizeof(stuRevFifo));
	if(newPoint == NULL)
		return False;
	memcpy(&newPoint->m_revAnalyData,revData,sizeof(stuRevFifo));
	newPoint->m_next = NULL;
	
	point->m_next = newPoint;
	point = newPoint;	
	return True;
}


RpyStatus readUsartRevData(int index,stuAnalyInfo *revTemp)
{
	assert(revTemp != NULL);
	assert(index >=0);
	assert(index < USTCOUNT);
	stuRevFifo* temp = sg_revFifoHead[index].m_next;
	if(temp != NULL)
	{
		memcpy(revTemp,&temp->m_revAnalyData,sizeof(stuAnalyInfo));
		sg_revFifoHead[index].m_next = temp->m_next;
		free(temp);
		return True;
	}
	else
	{
		return False;
	}
	
}





















