/******************************************************************************
 * 文件名称： LkList.c
 * 内容摘要： 实现单链表的创建、清空、初始化、查找、插入、删除等操作
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

#include "LkList.h"


/*****************************************************************************
 *                           局部函数原型                                    *
 *****************************************************************************/


/*****************************************************************************
 *                     函数实现--公有部分                                    *
 *****************************************************************************/

/*****************************************************************************
 * 功能描述： 初始化单链表
 *
 * @param   T_LinkList **ptL 指向单链表的指针
 *
 * @return  OK 表示成功，OVERFLOW1 表示溢出
 ******************************************************************************/

WORD ListInit(T_LinkList **ptL)
{
    // 给链表分配空间
    *ptL = (T_LinkList *) malloc (sizeof(T_LinkList));
    // 判断是否合法
    if (NULL == ptL)
    {
        return(OVERFLOW1);
    }
    // 初始化链表
    (*ptL)->ptHead = NULL;
    (*ptL)->ptCur  = NULL;
    (*ptL)->iNum   = 0;
    
    return(OK);
}

/*****************************************************************************
 * 功能描述： 清空单链表
 *
 * @param   T_LinkList *ptL 指向单链表的指针
 *
 * @return  OK 表示成功
 ******************************************************************************/

WORD ListClear(T_LinkList *ptL)
{
    T_ListNode *ptTemp;
    
    // 保存头结点
    ptL->ptCur = ptL->ptHead;
    // 断链清空单链表
    while (NULL != ptL->ptCur)
    {
        ptTemp     = ptL->ptCur;
        ptL->ptCur = ptL->ptCur->ptNext;
        free(ptTemp);
    }
    // 初始化链表
    ptL->ptHead = NULL;
    ptL->iNum   = 0;
    
    return(OK);
}

/*****************************************************************************
 * 功能描述： 头插法创建单链表
 *
 * @param   T_LinkList *ptL 指向单链表的指针
 * @param   int iInSize     单链表的初始长度
 * @param   void (*InputElem)(elemTypeLkL *) 输入数据的函数指针
 *
 * @return  OK 表示成功，OVERFLOW1表示溢出
 ******************************************************************************/

WORD ListHeadCreate(T_LinkList *ptL, int iInSize, void (*InputElem)(elemTypeLkL *))
{
    T_ListNode *ptListNodeTemp;
    elemTypeLkL eDatatmp;
    
    int i;
    for (i = 0; i < iInSize; i++)
    {
        printf("\n请输入第 %d 个值：",i+1);
        // 输入Elemtype类型的数据
        InputElem(&eDatatmp);
        // 给动态节点申请空间
        ptListNodeTemp = (T_ListNode *)malloc(sizeof(T_ListNode));
        // 判断是否申请成功
        if (NULL == ptListNodeTemp)
        {
            return(OVERFLOW1);
        }
        // 给该节点赋值
        ptListNodeTemp->eData  = eDatatmp;
        // 断链并插入节点
        ptListNodeTemp->ptNext = ptL->ptHead;
        ptL->ptHead = ptListNodeTemp;
        // 链表长度加一
        ptL->iNum++;
    }
    
    return (OK);
}

/*****************************************************************************
 * 功能描述： 尾插法建立单链表
 *
 * @param   T_LinkList *ptL 指向单链表的指针
 * @param   int iInSize     单链表的初始长度
 * @param   oid (*InputElem)(elemTypeLkL *) 输入数据的函数指针
 *
 * @return  OK 表示成功，OVERFLOW表示溢出
 ******************************************************************************/

WORD ListTailCreate(T_LinkList *ptL, int iInSize, void (*InputElem)(elemTypeLkL *))
{
    T_ListNode * ptListNodeTemp;
    elemTypeLkL eDataTemp;
    int i;
    
    ptL->ptCur = ptL->ptHead;
    for (i = 0; i < iInSize; i++)
    {
        printf("\n请输入第 %d 个值：", i+1);
        // 输入Elemtype类型的数据
        InputElem(&eDataTemp);
        // 给节点申请一个动态空间
        ptListNodeTemp = (T_ListNode *) malloc (sizeof(T_ListNode));
        // 判断申请节点是否成功
        if(NULL == ptListNodeTemp)
        {
            return(OVERFLOW);
        }
        // 初始化该节点
        ptListNodeTemp->eData  = eDataTemp;
        ptListNodeTemp->ptNext = NULL;
        // 第一个结点
        if (0 == i)
        {
            ptL->ptHead = ptListNodeTemp;
        }
        // 其他结点
        else
        {
            ptL->ptCur->ptNext = ptListNodeTemp;
        }
        
        ptL->ptCur = ptListNodeTemp;
        // 链表长度加一
        ptL->iNum++;
    }
    
    return(OK);
}

/*****************************************************************************
 * 功能描述： 遍历单链表
 *
 * @param   T_LinkList *ptL 指向单链表的指针
 * @param   void (*Visit)(elemTypeLkL *) 访问链表的函数指针
 *
 * @return  OK 表示成功，ERROR表示链表为空
 ******************************************************************************/

WORD ListDisplay(T_LinkList *ptL, void (*Visit)(elemTypeLkL *))
{
    int iCount = 0;
    // 判断单链表是否为空
    if(0 == ptL->iNum)
    {
        return(ERROR);
    }
    
    ptL->ptCur = ptL->ptHead;
    // 遍历该单链表
    while(NULL != ptL->ptCur)
    {
        iCount ++;
        printf("\n\n第 %d 个值为:", iCount);
        // 读取该单链表每个节点的值
        Visit(&ptL->ptCur->eData);
        // 移动单链表
        ptL->ptCur = ptL->ptCur->ptNext;
    }
    
    return(OK);
}

/*****************************************************************************
 * 功能描述： 求单链表长度
 *
 * @param   T_LinkList *ptL 指向单链表的指针
 *
 * @return  iLength 链表的长度
 ******************************************************************************/

WORD ListLength(T_LinkList *ptL)
{
    int iLength;
    iLength = ptL->iNum;
    return (iLength);
}

/*****************************************************************************
 * 功能描述： 判空单链表
 *
 * @param   T_LinkList *ptL 指向单链表的指针
 *
 * @return  OK 表示链表为空，ERROR表示链表不空
 ******************************************************************************/

WORD ListEmpty(T_LinkList *ptL)
{
    // 判断该单链表是否为空
    if(0 == ptL->iNum)
    {
        return (OK);
    }
    else
    {
        return (ERROR);
    }
}

/*****************************************************************************
 * 功能描述： 按序号查找单链表
 *
 * @param   T_LinkList *ptL 指向单链表的指针
 * @param   const int iInPosition 查找的位置
 * @param   elemTypeLkL *peOutValue 查找成功的值
 *
 * @return  OK 表示成功，ERROR表示查找位置不合法
 ******************************************************************************/

WORD ListOrderFind(T_LinkList *ptL, const int iInPosition, elemTypeLkL *peOutValue)
{
    int i;
    // 判断是否合法
    if ( iInPosition <1 || iInPosition >ptL->iNum)
    {
        return(ERROR);
    }
    
    ptL->ptCur = ptL->ptHead;
    // 按顺序查找目标位置
    for (i = iInPosition-1; i > 0 ; i--)
    {
        ptL->ptCur = ptL->ptCur->ptNext;
    }
    // 将查找到的值返回出去
    *peOutValue = ptL->ptCur->eData;
    
    return(OK);
}

/*****************************************************************************
 * 功能描述： 按查找内容单链表并返回查找到的位置
 *
 * @param   T_LinkList *ptL 指向单链表的指针
 * @param   elemTypeLkL *peInValue 要查找的值
 * @param   int *piOutPosition 找到的位置
 * @param   T_ListNode **peOutValuePoint 找到的节点
 * @param   WORD (*EqualElem)(elemTypeLkL *, elemTypeLkL *) 判断是否相等的函数指针
 *
 * @return  OK 表示成功，ERROR表示没找到
******************************************************************************/

WORD ListValueFind(T_LinkList *ptL,  elemTypeLkL *peInValue, int *piOutPosition, T_ListNode **peOutValuePoint, WORD (*EqualElem)(elemTypeLkL *, elemTypeLkL *))
{
    int iCount = 1;
    
    ptL->ptCur = ptL->ptHead;
    // 按单链表内容进行查找
    while (NULL != ptL->ptCur)
    {
        int flag;
        // 将输入的值和单链的值进行比较
        flag = EqualElem(peInValue, &ptL->ptCur->eData);
        // 找到后返回当前值和其所在的位置
        if ( TRUE == flag )
        {
            *piOutPosition      = iCount;
            *peOutValuePoint    = ptL->ptCur;
            return(OK);
        }
        
        iCount ++;
        // 移动单链表
        ptL->ptCur = ptL->ptCur->ptNext;
    }
    
    return(ERROR);
}

/*****************************************************************************
 * 功能描述： 更新单链表
 *
 * @param   T_LinkList *ptL 指向单链表的指针
 * @param   int iInPosition 更新元素的位置
 * @param   elemTypeLkL *peInValue 更新节点的值
 *
 * @return  OK 表示更新成功，ERROR表示位置不合法
 ******************************************************************************/

WORD ListUpdate(T_LinkList *ptL, int iInPosition, elemTypeLkL *peInValue)
{
    int iCount = 0;
    // 判断查找位置是否合法
    if ((iInPosition < 1) || (iInPosition > ptL->iNum))
    {
        return(ERROR);
    }
    
    ptL->ptCur = ptL->ptHead;
    // 按位置查找到要修改的单链表并对其进行修改
    while (NULL != ptL->ptCur)
    {
        iCount ++;
        
        if (iCount == iInPosition)
        {
            // 修改单链表
            ptL->ptCur->eData = *peInValue;
            return(OK);
        }
        ptL->ptCur = ptL->ptCur->ptNext;
    }
    
    return(OK);
}

/*****************************************************************************
 * 功能描述： 插入元素到单链表指定位置之后
 *
 * @param   T_LinkList *ptL 指向单链表的指针
 * @param   int iInPosition 插入位置
 * @param   elemTypeLkL *peInValue 输入插入节点的值
 *
 * @return  OK 表示更新成功，ERROR表示位置不合法，OVERFLOW1表示空间溢出
 ******************************************************************************/

WORD ListInsert(T_LinkList *ptL, int iInPosition, elemTypeLkL *peInValue)
{
    T_ListNode * ptListNodeTmp;
    int iCount = 0;
    
    // 判断插入的位置是否合法
    if ((iInPosition < 0) || (iInPosition > ptL->iNum))
    {
        return(ERROR);
    }
    
    // 给待插入的节点申请一个动态空间
    ptListNodeTmp = (T_ListNode *) malloc (sizeof(T_ListNode));
    // 判断是否申请成功
    if (NULL == ptListNodeTmp)
    {
        return(OVERFLOW1);
    }
    // 初始化待插入节点
    ptListNodeTmp->eData  = *peInValue;
    ptListNodeTmp->ptNext = NULL;
    // 待插入的节点插入的位置为第0个节点的位置
    if (0 == iInPosition)
    {
        ptListNodeTmp->ptNext = ptL->ptHead;
        ptL->ptHead = ptListNodeTmp;
        
        ptL->iNum ++;
        return(OK);
    }
    
    ptL->ptCur = ptL->ptHead;
    // 其它节点的位置
    while (NULL != ptL->ptCur)
    {
        iCount ++;
        // 找到该位置并插入到该位置
        if (iCount == iInPosition)
        {
            ptListNodeTmp->ptNext = ptL->ptCur->ptNext;
            ptL->ptCur->ptNext = ptListNodeTmp;
            
            ptL->iNum ++;
            return(OK);
        }
        ptL->ptCur = ptL->ptCur->ptNext;
    }
    return(OK);
}

/*****************************************************************************
 * 功能描述： 删除元素在单链表指定位置
 *
 * @param   T_LinkList *ptL 指向单链表的指针
 * @param   int iInPosition 删除位置
 * @param   elemTypeLkL *peOutValue 输出删除的节点的值
 *
 * @return  OK 表示更新成功，ERROR表示位置不合法
******************************************************************************/

WORD ListDelete(T_LinkList *ptL, int iInPosition, elemTypeLkL *peOutValue)
{
    int i;
    
    // 检查删除位置是否合法
    if ((iInPosition < 1) || (iInPosition > ptL->iNum))
    {
        return(ERROR);
    }
    
    // 删除结点为第一个结点
    if (1 == iInPosition)
    {
        ptL->ptCur  = ptL->ptHead;
        ptL->ptHead = ptL->ptHead->ptNext;
        ptL->iNum --;
        
        *peOutValue = ptL->ptCur->eData;
        free(ptL->ptCur);
    }
    // 删除结点为其他合法结点
    else
    {
        T_ListNode *ptTemp;
        
        ptL->ptCur = ptL->ptHead;
        for (i = iInPosition-1; i > 0; i--)
        {
            ptL->ptCur = ptL->ptCur->ptNext;
        }
        // 断链并删除节点
        ptTemp = ptL->ptCur->ptNext;
        ptL->ptCur->ptNext = ptTemp->ptNext;
        // 链表长度减一
        ptL->iNum --;
        // 返回删除节点的值 
        *peOutValue = ptTemp->eData;
        free(ptTemp);
    }
    
    return(OK);      // 只要位置合法，一定能找到  
}

/*****************************************************************************
 *                     函数实现--局部部分                                    *
*****************************************************************************/


