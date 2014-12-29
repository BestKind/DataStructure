#include "list.h"

/**************************************************
* 函数名称: ListInit
* 功能描述: 初始化链表，为其函数指针赋值
* 输入参数: 指向链表的指针的指针
* 输出参数: 无
* 返 回 值: OK 表示成功   ILLEGAL 表示非法
* 其他说明:
* 修改日期		版本号		修改人		修改内存
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD ListInit(List **list)
{
	//判断是否合法
	if (NULL == list)
	{
		return ILLEGAL;
	}

	//单链表方法
	(*list)->LkListInit = lkListInit;
	(*list)->LkListClear = lkListClear;
	(*list)->LkListCreate = lkListCreate;
	(*list)->LkListIsEmpty = lkListIsEmpty;
	(*list)->LkListDisplay = lkListDisplay;
	(*list)->LkListHeadInsert = lkListHeadInsert;
	(*list)->LkListTrailInsert = lkListTrailInsert;
	(*list)->LkListUpdateByOrder = lkListUpdateByOrder;
	(*list)->LkListDeleteByOrder = lkListDeleteByOrder;
	(*list)->LkListFindByOrder = lkListFindByOrder;
	(*list)->LkListFindByLkNodeMember = lkListFindByLkNodeMember;

	//循环单链表方法
	(*list)->CycleLkListInit = cycleLkListInit;
	(*list)->CycleLkListClear = cycleLkListClear;
	(*list)->CycleLkListCreate = cycleLkListCreate;
	(*list)->CycleLkListIsEmpty = cycleLkListIsEmpty;
	(*list)->CycleLkListDisplay = cycleLkListDisplay;
	(*list)->CycleLkListHeadInsert = cycleLkListHeadInsert;
	(*list)->CycleLkListTrailInsert = cycleLkListTrailInsert;
	(*list)->CycleLkListUpdateByOrder = cycleLkListUpdateByOrder;
	(*list)->CycleLkListDeleteByOrder = cycleLkListDeleteByOrder;
	(*list)->CycleLkListInsertByOrder = cycleLkListInsertByOrder;
	(*list)->CycleLkListFindByOrder = cycleLkListFindByOrder;
	(*list)->CycleLkListFindByLkNodeMember = cycleLkListFindByLkNodeMember;

	return OK;
}

