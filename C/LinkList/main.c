/*****************************************************************************
 * 文件名称： main.c
 * 内容摘要： 单链表的测试main文件
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

#include <stdio.h>
#include "LkList.h"

// 一些函数声明
void menu();
void OutputElem(elemTypeLkL *peValue);
void InputElem(elemTypeLkL *peValue);
WORD EqualElem(elemTypeLkL *peSource, elemTypeLkL *peTarget);

int main(int argc, const char * argv[])
{
    T_LinkList *ptL = NULL;
    
    signed int iState;
    int iChoice;
    int Flag = 1;
    menu();
    
    
    while(Flag)
    {
        
        printf("\t请选择菜单号(0--10)：");
        scanf("%d", &iChoice);
        switch(iChoice)
        {
            case 0:
            {
                Flag=0;
                break;
            }
            case 1:
            {
                iState = ListInit(&ptL);
                if(OVERFLOW1 == iState)
                {
                    printf("\n空间溢出！创建单链表失败！");
                }
                if(OK == iState)
                {
                    printf("\n单链表已被初始化！");
                }
                break;
            }
            case 2:
            {
                int iSize;
                printf("请输入单链表结点的个数：");
                scanf("%d", &iSize);
                
                iState = ListHeadCreate(ptL, iSize, InputElem);
                if(OVERFLOW1 == iState)
                {
                    printf("\n空间溢出！创建单链表结点失败！");
                }
                if(OK == iState)
                {
                    printf("\n单链表创建成功！");
                }
                break;
            }
            case 3:
            {
                int iSize;
                printf("请输入单链表结点的个数：");
                scanf("%d", &iSize);
                
                iState = ListTailCreate(ptL, iSize, InputElem);
                if(OVERFLOW1 == iState)
                {
                    printf("\n空间溢出！创建单链表结点失败！");
                }
                if(OK == iState)
                {
                    printf("\n单链表创建成功！");
                }
                break;
            }
            case 4:
            {
                printf("\n该链表的长度为：%d\n",ListLength(ptL));
                break;
            }
            case 5:
            {
                int      iPosition;
                elemTypeLkL eValue;
                
                printf("\n请输入需要查找的位置:");
                scanf("%d", &iPosition);
                
                iState = ListOrderFind(ptL, iPosition, &eValue);
                
                if(ERROR == iState)
                {
                    printf("\n输入的位置不合法!");
                }
                if (OK == iState)
                {
                    printf("\n链表中第%d个位置上的值为:%d\n",iPosition, eValue);
                    
                }
                break;
            }
            case 6:
            {
                int     iPosition;
                elemTypeLkL eValue;
                T_ListNode *ptValuePoint = NULL;
                
                printf("\n请输入需要查找的值：");
                InputElem(&eValue);
                
                iState = ListValueFind(ptL, &eValue, &iPosition, &ptValuePoint, EqualElem);
                if (ERROR == iState)
                {
                    printf("所查找元素不存在！");
                }
                if (OK == iState)
                {
                    printf("\n链表中第%d个位置上的值为:%d\n",iPosition, eValue);

                }
                break;
            }
            case 7:
            {
                int      iPosition;
                elemTypeLkL eValue;
                
                printf("\n请输入需要更新元素的位置：");
                scanf("%d", &iPosition);

                printf("请输入需要更新的元素：");
                scanf("%d", &eValue);

                
                iState = ListUpdate(ptL, iPosition, &eValue);
                if (ERROR == iState)
                {
                    printf("输入位置不合法！");
                }
                if (OK == iState)
                {
                    printf("更新成功！");
                }
                
                break;
            }
            case 8:
            {
                int      iPosition;
                elemTypeLkL eValue;
                
                printf("请输入插入元素的位置：");
                scanf("%d", &iPosition);

                printf("请输入需要更新的元素");
                scanf("%d", &eValue);

                
                iState = ListInsert(ptL, iPosition, &eValue);
                if (OVERFLOW1 == iState)
                {
                    printf("空间溢出，申请结点失败！");
                }
                if (ERROR == iState)
                {
                    printf("输入位置不合法！");
                }
                if (OK == iState)
                {
                    printf("%d 已成功插入到单链表的第 %d 个位置！",eValue,iPosition+1);
                }
                
                break;
            }
            case 9:
            {
                int      iPosition;
                elemTypeLkL eValue;
                
                printf("请输入需要删除的位置：");
                scanf("%d", &iPosition);
                
                iState = ListDelete(ptL, iPosition, &eValue);
                if (ERROR == iState)
                {
                    printf("删除位置不合法！");
                }
                if (OK == iState)
                {
                    printf("值 %d 已成功删除！", eValue);
                }
                
                break;
            }
            case 10:
            {
                ListClear(ptL);
                printf("清除成功！");
                break;
            }
            case 11:
            {
                if(OK == ListEmpty(ptL))
                {
                    printf("\n链表为空！");
                }
                else
                {
                    printf("\n链表不为空！");
                }
                
                break;
            }
            case 12:
            {
                if(ERROR == ListDisplay(ptL, OutputElem))
                {
                    printf("\n链表为空！");
                }
                
                break;
            }
                
            default:
            {
                printf("选择功能序号不合法！请重新选择指定功能！");
                break;
            }
        }
    }
    return 0;
    
}
// 输出函数
void OutputElem(elemTypeLkL *peValue)
{
    printf("%d  ", *peValue);
    
}
// 输入函数
void InputElem(elemTypeLkL *peValue)
{
    scanf("%d", peValue);
}
// 比较函数
WORD EqualElem(elemTypeLkL *peSource, elemTypeLkL *peTarget)
{
    if (*peSource == *peTarget)
    {
        return(TRUE);
    }
    else
    {
        return(FALSE);
    }     

}
// 菜单选项
void menu()
{
    printf("\n");
    printf("\n***********************************************");
    printf("\n*              单 链 表 子 系 统              *");
    printf("\n***********************************************");
    printf("\n*          0----------返        回            *");
    printf("\n*          1----------初始化 链 表            *");
    printf("\n*          2----------头部插入建表            *");
    printf("\n*          3----------尾部插入建表            *");
    printf("\n*          4----------求   表   长            *");
    printf("\n*          5----------按序号 查 找            *");
    printf("\n*          6----------按 值  查 找            *");
    printf("\n*          7----------更        新            *");
    printf("\n*          8----------插        入            *");
    printf("\n*          9----------删        除            *");
    printf("\n*          10---------清        空           *");
    printf("\n*          11---------判        空           *");
    printf("\n*          12---------显        示           *");
    printf("\n*********************************************\n");
    
}

