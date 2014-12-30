#include "type.h"

/***************************************
 * 结点类型不用，修改type.c和type.h文件
 **************************************/

WORD LkNodeInput(LkNode *lkNode)
{
	//判断是否合法
	if (NULL == lkNode)
	{
		return ILLEGAL;
	}

	printf("请输入结点成员编号：");
	scanf("%d",&(lkNode->data));

	return OK;
}

WORD LkNodeMemberInput(LkNode *lkNode)
{
	//判断是否合法
	if (NULL == lkNode)
	{
		return ILLEGAL;
	}

	printf("请输入结点成员编号：");
	scanf("%d",&(lkNode->data));

	return OK;
}

WORD LkNodeDisplay(LkNode *lkNode)
{
	//判断是否合法
	if (NULL == lkNode)
	{
		return ILLEGAL;
	}

	printf("data = %d\n",lkNode->data);

	return OK;
}

WORD LkNodeCpy(LkNode *targetLkNode, LkNode *sourceLkNode)
{
	//判断是否合法
	if (NULL == targetLkNode || NULL == sourceLkNode)
	{
		return ILLEGAL;
	}

	targetLkNode->data = sourceLkNode->data;
	//无需指定目标结点的next，出去再选择，防止更新链表中结点数据将链表断开

	return OK;
}

WORD LkNodeMemberEqual(LkNode *fristLkNode, LkNode *secondLkNode)
{
	//判断是否合法
	if (NULL == fristLkNode || NULL == secondLkNode)
	{
		return ILLEGAL;
	}

	if (fristLkNode->data == secondLkNode->data)
	{
		return TRUE;
	}
	
	return FALSE;
}
