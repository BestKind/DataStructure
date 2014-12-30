/*****************************************************************************
 * 文件名称：  lklist.h
 * 内容摘要：  链表的创建、清空、初始化、查找、插入、删除等函数说明
 * 当前版本： V1.0
 * 作    者：liao
 * 完成日期： 2014年12月17日
 *
 * 修改记录1：// 修改历史记录，包括修改日期、修改者及修改内容
 * 修改日期：
 * 版 本 号：
 * 修 改 人：
 * 修改内容：
 * 修改记录2：…
 * @license ZPL (http://zpl.pub/v1)
 * Copyright (c) 2014  SmallLeg Team
 ******************************************************************************/

#include "Common.h"

#ifndef  _LKLIST_H_
#define  _LKLIST_H_



/*****************************************************************************
 *                        常量                                               *
 *****************************************************************************/

/*****************************************************************************
 *                          宏定义                                           *
 *****************************************************************************/

/*****************************************************************************
 *                            数据类型                                       *
 *****************************************************************************/

typedef int elemTypeLkL;
// 链表结点结构体
typedef struct ListNode
{
    elemTypeLkL        eData;				//数据域，存放的类型为整形
    struct ListNode  *ptNext;			   //指针域，指向node类型的指针
}T_ListNode;							  //为了方便，定义lklist来代替指向node的指针

// 链表结构体
typedef struct LinkList
{
    T_ListNode *ptHead;
    T_ListNode *ptCur;
    int         iNum;
}T_LinkList;

/*****************************************************************************
 *                             类声明                                        *
 *****************************************************************************/



/*****************************************************************************
 *                           链表操作函数定义                                *
 *****************************************************************************/

// 初始化单链表,OK:成功,OVERFLOW1:溢出
WORD ListInit(T_LinkList **ptL);

// 清空单链表,OK:成功
WORD ListClear(T_LinkList *ptL);

// 头插法创建单链表,OK:成功,OVERFLOW1:溢出
WORD ListHeadCreate(T_LinkList *ptL,int iInSize, void (*Input)(elemTypeLkL *));

// 尾插法创建单链表,OK:成功,OVERFLOW1:溢出
WORD ListTailCreate(T_LinkList *ptL,int iInSize, void (*Input)(elemTypeLkL *));

// 遍历单链表,OK:成功,ERROR:链表为空
WORD ListDisplay(T_LinkList *ptL, void (*Visit)(elemTypeLkL *));

// 求单链表长度,返回链表的长度
WORD ListLength(T_LinkList *ptL);

// 判空单链表,OK:链表为空,ERROR:链表不空
WORD ListEmpty(T_LinkList *ptL);

// 按序号查找单链表,OK:找到,ERROR:位置不合法
WORD ListOrderFind(T_LinkList *ptL, const int iInPosition, elemTypeLkL *peOutValue);

// 按值查找单链表,OK:找到,ERROR:没找到
WORD ListValueFind(T_LinkList *ptL, elemTypeLkL *peInValue, int *piOutPosition, T_ListNode **ptOutValuePoint, WORD (*EqualElem)(elemTypeLkL *, elemTypeLkL *));

// 更新单链表,OK:成功,ERROR:位置不合法
WORD ListUpdate(T_LinkList *ptL, int iInPosition, elemTypeLkL *peInValue);

// 插入单链表,OK:成功,ERROR:位置不合法,OVERFLOW1:溢出
WORD ListInsert(T_LinkList *ptL, int iInPosition, elemTypeLkL *peInValue);

// 删除单链表,OK:成功,ERROR:位置不合法
WORD ListDelete(T_LinkList *ptL, int iInPosition, elemTypeLkL *peOutValue);


#endif /* defined(__LKLIST__) */
