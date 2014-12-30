#include "cyclelklist.h"

/**************************************************
* 函数名称: cycleLkListInit
* 功能描述: 初始化循环单链表
* 输入参数: 指向循环单链表的指针的指针
* 输出参数: 无
* 返 回 值: OK 表示成功   ILLEGAL 表示非法
* 其他说明:
* 修改日期		版本号		修改人		修改内容
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListInit(CycleLkList **cycleLkList)
{
	//判断是否合法
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}

	(*cycleLkList)->head = NULL;
	(*cycleLkList)->current = NULL;
	(*cycleLkList)->trail = NULL;
	(*cycleLkList)->length = 0;

	return OK;
}

/**************************************************
* 函数名称: cycleLkListClear
* 功能描述: 清空循环单链表
* 输入参数: 指向循环单链表的指针
* 输出参数: 无
* 返 回 值: OK 表示成功   ILLEGAL 表示非法
* 其他说明:
* 修改日期		版本号		修改人		修改内容
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListClear(CycleLkList *cycleLkList)
{
	//判断是否合法
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}
	
	cycleLkList->current = cycleLkList->head;
	for (; cycleLkList->current->next != cycleLkList->head;)
	{
		cycleLkList->head = cycleLkList->current->next;
		cycleLkList->trail->next = cycleLkList->head;

		cycleLkList->current->next = NULL;
		free(cycleLkList->current);
		cycleLkList->length -= 1;

		cycleLkList->current = cycleLkList->head;
	}

	cycleLkList->current->next = NULL;
	free(cycleLkList->current);
	cycleLkList->length -= 1;

	cycleLkListInit(&cycleLkList);

	return OK;

}

/**************************************************
* 函数名称: cycleLkListIsEmpty
* 功能描述: 判断循环链表是否为空
* 输入参数: 指向循环单链表的指针
* 输出参数: 无
* 返 回 值: OK 表示成功 FALSE 表示失败 ILLEGAL 表示非法
* 其他说明:
* 修改日期		版本号		修改人		修改内容
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListIsEmpty(CycleLkList *cycleLkList)
{
	//判断是否合法
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}

	if (0 == cycleLkList->length)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**************************************************
* 函数名称: cycleLkListClear
* 功能描述: 创建循环单链表的第一个结点
* 输入参数: 指向循环单链表的指针，结点
* 输出参数: 无
* 返 回 值: OK 表示成功 FALSE 表示失败 ILLEGAL 表示非法
* 其他说明:
* 修改日期		版本号		修改人		修改内容
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListCreate(CycleLkList *cycleLkList, LkNode lkNode)
{
	LkNode *lkNd;
	//判断是否合法
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}

	if (TRUE != cycleLkListIsEmpty(cycleLkList))
	{
		return FALSE;
	}

	lkNd = (LkNode *)malloc(sizeof(LkNode));
	if (NULL == lkNd)
	{
		return FALSE;
	}

	LkNodeCpy(lkNd,&lkNode);
	cycleLkList->head = lkNd;
	cycleLkList->trail = lkNd;
	cycleLkList->trail->next = cycleLkList->head;
	cycleLkList->length += 1;

	lkNd = NULL;

	return TRUE;
}

/**************************************************
* 函数名称: cycleLkListDisplay
* 功能描述: 循环链表遍历
* 输入参数: 指向循环单链表的指针
* 输出参数: 无
* 返 回 值: OK 表示成功  ILLEGAL 表示非法
* 其他说明:
* 修改日期		版本号		修改人		修改内容
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListDisplay(CycleLkList *cycleLkList)
{
	//判断是否合法
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}

	LkNodeDisplay(cycleLkList->head);

	cycleLkList->current = cycleLkList->head->next;
	for (;cycleLkList->current != cycleLkList->head;)
	{
		LkNodeDisplay(cycleLkList->current);
		cycleLkList->current = cycleLkList->current->next;

	}

	return OK;
}

/**************************************************
* 函数名称: cycleLkListHeadInsert
* 功能描述: 循环链表头插法
* 输入参数: 指向循环单链表的指针，结点
* 输出参数: 无
* 返 回 值: TRUE 表示成功 FALSE 表示失败 ILLEGAL 表示非法
* 其他说明:
* 修改日期		版本号		修改人		修改内容
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListHeadInsert(CycleLkList *cycleLkList, LkNode lkNode)
{
	LkNode *lkNd;
	//判断是否合法
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}

	if (TRUE == cycleLkListIsEmpty(cycleLkList))
	{
		return FALSE;
	}

	lkNd = (LkNode *)malloc(sizeof(LkNode));
	if (NULL == lkNd)
	{
		return FALSE;
	}

	LkNodeCpy(lkNd,&lkNode);
	lkNd->next = cycleLkList->head;
	cycleLkList->head = lkNd;
	cycleLkList->trail->next = cycleLkList->head;
	cycleLkList->length += 1;

	lkNd = NULL;

	return TRUE;
}

/**************************************************
* 函数名称: cycleLkListTrailInsert
* 功能描述: 循环链表尾插法
* 输入参数: 指向循环单链表的指针，结点
* 输出参数: 无
* 返 回 值: TRUE 表示成功 FALSE 表示失败 ILLEGAL 表示非法
* 其他说明:
* 修改日期		版本号		修改人		修改内容
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListTrailInsert(CycleLkList *cycleLkList, LkNode lkNode)
{
	LkNode *lkNd;
	//判断是否合法
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}

	if (TRUE == cycleLkListIsEmpty(cycleLkList))
	{
		return FALSE;
	}

	lkNd = (LkNode *)malloc(sizeof(LkNode));
	if (NULL == lkNd)
	{
		return FALSE;
	}

	LkNodeCpy(lkNd,&lkNode);
	cycleLkList->trail->next = lkNd;
	cycleLkList->trail = lkNd;
	cycleLkList->trail->next = cycleLkList->head;
	cycleLkList->length += 1;

	lkNd = NULL;

	return TRUE;
}

/**************************************************
* 函数名称: cycleLkListDelete
* 功能描述: 循环链表尾删除指定序号结点
* 输入参数: 指向循环单链表的指针，序号
* 输出参数: 无
* 返 回 值: OK 表示成功 ERROR 表示非法序号 ILLEGAL 表示非法
* 其他说明:
* 修改日期		版本号		修改人		修改内容
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListDeleteByOrder(CycleLkList *cycleLkList,const int order)
{
	//判断是否合法
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}
	
	//判断序号是否小于0，或大于循环单链表的长度
	if ((order < 1) || (order > cycleLkList->length))
	{
		return ERROR;
	}
	
	//如果序号等于1，即删除头结点
	if (1 == order)
	{
		cycleLkList->current = cycleLkList->head;
		
		//脱离出被删除的结点
		cycleLkList->head = cycleLkList->head->next;
		cycleLkList->trail->next = cycleLkList->head;
		cycleLkList->current->next = NULL;

		free(cycleLkList->current);
	} 
	else if (cycleLkList->length == order)//如果序号等于循环单链表的长度，即删除尾结点
	{
		int i;
		//找到尾结点的前一个结点
		cycleLkList->current = cycleLkList->head;
		for (i = 1; i < order - 1; i++)
		{
			cycleLkList->current = cycleLkList->current->next;
		}

		//脱离出被删除的结点
		cycleLkList->trail = cycleLkList->current;
		cycleLkList->current = cycleLkList->current->next;
		cycleLkList->trail->next = cycleLkList->head;
		cycleLkList->current->next = NULL;

	}
	else
	{
		int i;
		LkNode *lkNodeTemp;

		//找到需删除结点的前一个结点
		cycleLkList->current = cycleLkList->head;
		for (i = 1; i < order - 1; i++)
		{
			cycleLkList->current = cycleLkList->current->next;
		}

		lkNodeTemp = cycleLkList->current;
		cycleLkList->current = cycleLkList->current->next;
		lkNodeTemp->next = cycleLkList->current->next;
		cycleLkList->current->next = NULL;

		lkNodeTemp = NULL;
	}

	//删除结点，并循环链表长度-1
	free(cycleLkList->current);
	cycleLkList->length -= 1;

	return OK;
}

/**************************************************
* 函数名称: cycleLkListUpdateByOrder
* 功能描述: 循环链表尾更新指定序号结点
* 输入参数: 指向循环单链表的指针，序号，结点
* 输出参数: 无
* 返 回 值: OK 表示成功 ERROR 表示非法序号 ILLEGAL 表示非法
* 其他说明:
* 修改日期		版本号		修改人		修改内容
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListUpdateByOrder(CycleLkList *cycleLkList,const int order, LkNode lkNode)
{
	int i;
	//判断是否合法
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}
	
	//判断序号是否小于0，或大于循环单链表的长度
	if ((order < 1) || (order > cycleLkList->length))
	{
		return ERROR;
	}
	
	//找到需更新结点
	cycleLkList->current = cycleLkList->head;
	for (i = 1; i < order; i++)
	{
		cycleLkList->current = cycleLkList->current->next;
	}

	LkNodeCpy(cycleLkList->current,&lkNode);

	return OK;
}

/**************************************************
* 函数名称: cycleLkListInsertByOrder
* 功能描述: 循环链表尾更新指定序号结点
* 输入参数: 指向循环单链表的指针，序号，结点
* 输出参数: 无
* 返 回 值: OK 表示成功 ERROR 表示非法序号 ILLEGAL 表示非法
* 其他说明:
* 修改日期		版本号		修改人		修改内容
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListInsertByOrder(CycleLkList *cycleLkList,const int order, LkNode lkNode)
{
	int i;
	LkNode *lkNodeTemp;
	//判断是否合法
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}
	
	//判断序号是否小于0，或大于循环单链表的长度
	if ((order < 1) || (order > cycleLkList->length))
	{
		return ERROR;
	}

    lkNodeTemp = (LkNode *)malloc(sizeof(LkNode));
	if (NULL == lkNodeTemp)
	{
		return ERROR;
	}
	//结点赋值
	LkNodeCpy(lkNodeTemp,&lkNode);

	if (cycleLkList->length == order)
	{
		cycleLkList->current = cycleLkList->trail;
		cycleLkList->current->next = lkNodeTemp;
		cycleLkList->trail = lkNodeTemp;
		cycleLkList->trail->next = cycleLkList->head;
	}
	else
	{
		//找到需更新结点
		cycleLkList->current = cycleLkList->head;
		for (i = 1; i < order; i++)
		{
			cycleLkList->current = cycleLkList->current->next;
		}

		lkNodeTemp->next = cycleLkList->current->next;
		cycleLkList->current->next = lkNodeTemp;
	}

	return OK;
}

/**************************************************
* 函数名称: cycleLkListFindByOrder
* 功能描述: 循环链表尾查找指定序号结点
* 输入参数: 指向循环单链表的指针，序号
* 输出参数: 结点结构体
* 返 回 值: OK 表示成功 ERROR 表示非法序号 ILLEGAL 表示非法
* 其他说明:
* 修改日期		版本号		修改人		修改内容
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListFindByOrder(CycleLkList *cycleLkList, const int order, LkNode *outLkNode)
{
	int i;
	//判断是否合法
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}
	
	//判断序号是否小于0，或大于循环单链表的长度
	if ((order < 1) || (order > cycleLkList->length))
	{
		return ERROR;
	}

	//找到需更新结点
	cycleLkList->current = cycleLkList->head;
	for (i = 1; i < order; i++)
	{
		cycleLkList->current = cycleLkList->current->next;
	}

	LkNodeCpy(outLkNode,cycleLkList->current);

	return OK;
}

/**************************************************
* 函数名称: cycleLkListFindByLkNodeMember
* 功能描述: 通过结点成员查找循环单链表结点
* 输入参数: 指向循环单链表的指针，结点成员输入函数指针，结点成员比较函数指针
* 输出参数: 循环单链表指针
* 返 回 值: TRUE 表示成功 FALSE 表示内存不够 ILLEGAL 表示非法
* 其他说明: 比较不同结点成员，LkNodeMemberEqual赋值不同函数
* 修改日期		版本号		修改人		修改内容
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListFindByLkNodeMember(CycleLkList *cycleLkList, CycleLkList *outCycleLkList, WORD (*LkNodeMemberInput)(LkNode *inLkNode),WORD (*LkNodeMemberEqual)(LkNode *fristLkNode, LkNode *secondNode))
{
	int flag = 1;
	int i;
	LkNode *outLkNode,*inLkNode;
	//判断是否合法
	if ((NULL == cycleLkList) || (NULL == outCycleLkList))
	{
		return ILLEGAL;
	}
	
	outLkNode = (LkNode *)(malloc)(sizeof(LkNode));
	inLkNode = (LkNode *)(malloc)(sizeof(LkNode));
	if (NULL == outLkNode || NULL == inLkNode)
	{
		return FALSE;
	}
	
	LkNodeMemberInput(inLkNode);
	cycleLkList->current = cycleLkList->head;
	for (i = 1; i <= cycleLkList->length; i++)
	{
		if (TRUE == LkNodeMemberEqual(cycleLkList->current,inLkNode))
		{
			LkNodeCpy(outLkNode,cycleLkList->current);
			outLkNode->next = NULL;
			
			if (1 != flag)
			{
				cycleLkListTrailInsert(outCycleLkList,*outLkNode);

			}
			else
			{
				flag = 0;
				cycleLkListCreate(outCycleLkList,*outLkNode);
			}
		}
		cycleLkList->current = cycleLkList->current->next;
	}

	return TRUE;
}
