#ifndef _DOUBLELIST_H_
#define _DOUBLELIST_H_

#include "common.h"

/**************************************************************************
 *                            数据结构体                                   *
 **************************************************************************/

//结点结构体
typedef struct D_Node
{
	elemType iData;
	struct D_Node *pNext;
	struct D_Node *pPrev;
}List_Node;


//链表结构体
typedef struct D_LIST
{
	elemType iCount;            //表中元素个数
    struct D_Node *pHead;      //头结点
	struct D_Node *pCur;      //当前节点
}List_t;


/**************************************************************************
 *                        全局函数原型                                     *
 **************************************************************************/

//初始化
WORD DoubleListInit(List_t *pDL);

//头插法
WORD DoubleListHead(List_t *pDL, int iInSize, void (*InputElem)(elemType *), WORD (*EqualElem)(elemType *, elemType *));

//尾插法
WORD DoubleListLast(List_t *pDL, int iInSize, void (*InputElem)(elemType *), WORD (*EqualElem)(elemType *, elemType *));

//删除
WORD DoubleListDelete(List_t *pDL, int iPosition, elemType *peOutValue);

//随机插入值
WORD DoubleListInsert(List_t *pDL, int iPosition, elemType *peInValue, WORD (*EqualElem)(elemType *, elemType *));

//查找某个值
WORD DoubleListValueFind(List_t *pDL, elemType *peInValue, int *piOutPosition, WORD (*EqualElem)(elemType *, elemType *));

//求链表的长度
WORD DoubleListLength(List_t *pDL);

//判断链表是否为空
WORD DoubleListEmpty(List_t *pDL);

//清空链表
WORD DoubleListClear(List_t *pDL);

//遍历链表
WORD DoubleListDisplay(List_t *pDL, void(*OutPut)(elemType *));
 
#endif