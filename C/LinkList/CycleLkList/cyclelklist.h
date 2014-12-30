#ifndef _CYCLELKLIST_H_
#define _CYCLELKLIST_H_

#include "type.h"
#include "common.h"

/**
* 循环单链表
* *head指向单向链表头结点的指针
* *current指向单向链表当前结点的指针
* length为单向链表的长度
*/
typedef struct CycleLkList
{
	LkNode *head;//指向循环单链表的头
	LkNode *current;//用来指向当前结点
	LkNode *trail;//用来指向循环链表的尾
	int length;//单链表的长度
}CycleLkList;

//循环单链表初始化
WORD cycleLkListInit(CycleLkList**);
//循环单链表清空
WORD cycleLkListClear(CycleLkList*);
//判断循环单链表是否为空
WORD cycleLkListIsEmpty(CycleLkList*);
//循环单链表创建第一个结点
WORD cycleLkListCreate(CycleLkList*, LkNode);
//循环单链表遍历
WORD cycleLkListDisplay(CycleLkList*);
//循环单链表头插法
WORD cycleLkListHeadInsert(CycleLkList*, LkNode);
//循环单链表尾插法
WORD cycleLkListTrailInsert(CycleLkList*, LkNode);
//按序号删除指定结点
WORD cycleLkListDeleteByOrder(CycleLkList*,const int);
//按序号更新指定结点
WORD cycleLkListUpdateByOrder(CycleLkList*,const int, LkNode);
//在指定结点序号后边插入一个结点
WORD cycleLkListInsertByOrder(CycleLkList*,const int, LkNode);
//按序号查找指定结点
WORD cycleLkListFindByOrder(CycleLkList*, const int, LkNode*);
//按结点中的成员是否相等找出所有结点
WORD cycleLkListFindByLkNodeMember(CycleLkList*, CycleLkList*, WORD (*LkNodeMemberInput)(LkNode*),WORD (*LkNodeMemberEqual)(LkNode*, LkNode*));

#endif