#include "doublelist.h"

WORD DoubleListInit(List_t *pDL)
{
	//判断是否合法
	if (NULL == pDL)
	{
		return ILLEGAL;
	}

	//初始化
	pDL->pHead = NULL;
	pDL->pCur = NULL;
	pDL->iCount = 0;

	return TRUE;
}

WORD DoubleListClear(List_t *pDL)
{
	List_Node *pTemp = NULL;
	//判断是否合法
	if (NULL == pDL)
	{
		return ILLEGAL;
	}

	pDL->pCur = pDL->pHead;

	//断链清空链表
	while (NULL != pDL->pCur)
	{
		pTemp = pDL->pCur;
		pDL->pCur = pDL->pCur->pNext;
		free(pTemp);
		pTemp = NULL;
	}
	return TRUE;
}

WORD DoubleListHead(List_t *pDL, int iInSize, void (*InputElem)(elemType *), WORD (*EqualElem)(elemType *, elemType *))
{
	List_Node *pTemp;
	List_Node *pTemp2;
	int i = 0;
	int iFlag = 0;
	elemType eData;
	//判断是否合法
	if (NULL == pDL)
	{
		return ILLEGAL;
	}
	//判断建表长度是否有效
	if (iInSize <= 0)
	{
		return ERROR;
	}

	for (; i < iInSize; i++)
	{
		printf("添加到链表的第%d个值: \n", (i+1));
		InputElem(&eData);

		//用来判断插入的元素是否表中已存在
		pTemp2 = pDL->pHead;
		while(NULL != pTemp2)
		{
			iFlag = EqualElem(&eData, &(pTemp2->iData));
			if (TRUE == iFlag)
			{
				break;
			}
			pTemp2 = pTemp2->pNext;
		}
		if (TRUE == iFlag)
		{
			continue;
		}

		//申请内存空间
		pDL->pCur = (List_Node *)malloc(sizeof(List_Node));
		if (NULL == pDL->pCur)
		{
			return OVERFLOW;
		}
		pDL->pCur->iData = eData;
		pDL->pCur->pNext = NULL;
		
		//断链
		if(NULL != pDL->pHead)
		{
			pTemp = pDL->pHead;
			pTemp->pPrev = pDL->pCur;
			pDL->pCur->pNext = pTemp;
		}
		
		pDL->pHead = pDL->pCur;
		pDL->iCount++;
	}
	printf("\n成功插入到链表的元素个数为: %d", pDL->iCount);

    return TRUE;
}

WORD DoubleListLast(List_t *pDL, int iInSize, void (*InputElem)(elemType *), WORD (*EqualElem)(elemType *, elemType *))
{
	List_Node *pTemp = NULL;
	List_Node *pTemp1 = NULL;
	List_Node *pTemp2 = NULL;
	int i = 0;
	int iFlag = 0;
	elemType eData;
	//判断是否合法
	if (NULL == pDL)
	{
		return ILLEGAL;
	}

	//判断建表长度是否有效
	if (iInSize <= 0)
	{
		return ERROR;
	}

	for (; i < iInSize; i++)
	{
		printf("添加到链表的第%d个值: \n", (i+1));
		InputElem(&eData);

		//用来判断插入的元素是否表中已存在
		pTemp = pDL->pHead;
		while(NULL != pTemp)
		{
			iFlag = EqualElem(&eData, &(pTemp->iData));
			if (TRUE == iFlag)
			{
				break;
			}
			pTemp = pTemp->pNext;
		}
		if (TRUE == iFlag)
		{
			continue;
		}
		
		//申请内存空间
		pTemp1 = (List_Node *)malloc(sizeof(List_Node));
		if (NULL == pTemp1)
		{
			return OVERFLOW;
		}
		pTemp1->iData = eData;
		pTemp1->pNext = NULL;

		//头结点
		pDL->pCur = pDL->pHead;
		
		//断链
		if (NULL != pDL->pCur)
		{
			while(NULL != pDL->pCur)
			{
				pTemp2 = pDL->pCur;
				pDL->pCur = pDL->pCur->pNext;
			}
			pTemp1->pPrev = pTemp2;
			pTemp2->pNext = pTemp1;
		}
		else
		{
			pDL->pHead = pTemp1;
		}
		
		pDL->iCount++;
	}

	printf("\n成功插入到链表的元素个数为: %d", pDL->iCount);
	
    return TRUE;
}

WORD DoubleListInsert(List_t *pDL, int iPosition, elemType *peInValue, WORD (*EqualElem)(elemType *, elemType *))
{
	List_Node *pTemp = NULL;
	List_Node *pTemp1 = NULL;
	List_Node *pTemp2 = NULL;
	int i = 0;
	int iFlag = 0;

	//判断是否合法
	if (NULL == pDL)
	{
		return ILLEGAL;
	}

	//验证位置是否有效
	if (iPosition < 1 || iPosition > pDL->iCount)
	{
		return ERROR; 
	}

	//取到头结点
	pTemp = pDL->pHead;
	while (NULL != pTemp)
	{
		iFlag = EqualElem(peInValue, (&pTemp->iData));
		if (TRUE == iFlag)
		{
			return EXIST;
		}
		pTemp = pTemp->pNext;
	}

	//申请空间
	pDL->pCur = (List_Node *)malloc(sizeof(List_Node));
	if (NULL == pDL->pCur)
	{
		return OVERFLOW;
	}
	pDL->pCur->iData = *peInValue;
	pDL->pCur->pNext = NULL;

	if (TRUE == DoubleListEmpty(pDL))
	{
		pDL->pHead = pDL->pCur;
	}
	else if(FALSE == DoubleListEmpty(pDL))
	{
		//再将pTemp1赋值为头结点
		pTemp1 = pDL->pHead;

		//插值到第一个位置
		if (1 == iPosition)
		{
			pDL->pCur->pNext = pDL->pHead;
			pDL->pHead->pPrev = pDL->pCur;
			pDL->pHead = pDL->pCur;
		}
		//在最后一个位置插值
		else if (pDL->iCount == iPosition)
		{
			while(NULL != pTemp1)
			{
				pTemp2 = pTemp1;
				pTemp1 = pTemp1->pNext;
			}
			pTemp2->pNext = pDL->pCur;
			pDL->pCur->pPrev = pTemp2;
		}
		else
		{
			//找到插入位置
			for (i = iPosition - 1; i > 0; i--)
			{
				pTemp1 = pTemp1->pNext;
			}
			pTemp1->pPrev->pNext = pDL->pCur;
			pDL->pCur->pPrev = pTemp1->pPrev;
			pDL->pCur->pNext = pTemp1;
			pTemp1->pPrev = pDL->pCur;
		}
	}
	else
	{
		return ILLEGAL;
	}

	pDL->iCount++;
	return TRUE;
}

WORD DoubleListValueFind(List_t *pDL, elemType *peInValue, int *piOutPosition, WORD (*EqualElem)(elemType *, elemType *))
{
	int iFlag = 0;
	int iPostion = 1;
	//判断是否合法
	if (NULL == pDL)
	{
		return ILLEGAL;
	}

	//取当前结点为头结点
	pDL->pCur = pDL->pHead;

	while (NULL != pDL->pCur)
	{
		iFlag = EqualElem(peInValue, &pDL->pCur->iData);
		if (TRUE == iFlag)
		{
			*piOutPosition = iPostion;
			return EXIST;
		}
		iPostion++;
		pDL->pCur = pDL->pCur->pNext;
	}

	return NOEXIST;
}

WORD DoubleListEmpty(List_t *pDL)
{
	//判断是否合法
	if (NULL == pDL)
	{
		return ILLEGAL;
	}

	if (NULL == pDL->pHead)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

WORD DoubleListLength(List_t *pDL)
{
	int iLength;
	//判断是否合法
	if (NULL == pDL)
	{
		return ILLEGAL;
	}

	iLength = pDL->iCount;
	return iLength;
}

WORD DoubleListDisplay(List_t *pDL, void(*OutPut)(elemType *))
{
	int iCount = 0;
	//判断是否合法
	if (NULL == pDL)
	{
		return ILLEGAL;
	}
	//判断是否为空
	if (TRUE == DoubleListEmpty(pDL))
	{
		return ERROR;
	}

	pDL->pCur = pDL->pHead;
	while(NULL != pDL->pCur)
	{
		iCount++;
		printf("\n第%d个元素：", iCount);
		//打印出当前结点
		OutPut(&pDL->pCur->iData);

		pDL->pCur = pDL->pCur->pNext;
	}

	return TRUE;
}

WORD DoubleListDelete(List_t *pDL, int iPosition, elemType *peOutValue)
{
	int i;

	//判断是否合法
	if (NULL == pDL)
	{
		return ILLEGAL;
	}
	//判断是否为空
	if (TRUE == DoubleListEmpty(pDL))
	{
		return FALSE;
	}
	//验证位置是否有效
	if (iPosition < 1 || iPosition > pDL->iCount)
	{
		return ERROR; 
	}
	//当删除位置为1时
	if (1 == iPosition)
	{
		pDL->pCur = pDL->pHead;
		pDL->pHead = pDL->pCur->pNext;
		pDL->iCount--;

		*peOutValue = pDL->pCur->iData;
		free(pDL->pCur);
		pDL->pCur = NULL;
	}
	//删除位置不为1
	else
	{
		List_Node *pTemp = NULL;

		pDL->pCur = pDL->pHead;
		for (i = iPosition - 1; i > 0; i--)
		{
			pDL->pCur = pDL->pCur->pNext;
		}
		
		pTemp = pDL->pCur->pNext;
		pTemp->pPrev = pDL->pCur->pPrev;
		pDL->pCur->pPrev->pNext = pTemp;
		pDL->iCount--;

		*peOutValue = pDL->pCur->iData;
		free(pDL->pCur);
		pDL->pCur = NULL;
	}
	return TRUE;
}