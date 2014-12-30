#include <stdio.h>
#include "list.h"

void menu();

int main()
{
	int no;
	List *list;
	LkNode *lkNode;
	CycleLkList *cycleLkList,*outCycleLkList;

	list = (List *)malloc(sizeof(List));
	lkNode = (LkNode *)malloc(sizeof(LkNode));
	cycleLkList = (CycleLkList *)malloc(sizeof(CycleLkList));
	outCycleLkList = (CycleLkList *)malloc(sizeof(CycleLkList));

	menu();
	ListInit(&list);
	for (;;)
	{
		printf("\n请输入测试功能代号：");
		scanf("%d",&no);
		switch (no)
		{
		case 0:
			{
				printf("您选择退出\n");
				exit(0);
			}
		case 1:
			{
				printf("您选择初始化循环单链表，测试方法为：CycleLkListInit\n");
				list->CycleLkListInit(&cycleLkList);
				break;
			}
		case 2:
			{
				printf("您选择创建循环单链表第一个结点，测试方法为：CycleLkListCreate\n");
				LkNodeInput(lkNode);
				list->CycleLkListCreate(cycleLkList,*lkNode);
				break;
			}
		case 3:
			{
				printf("您选择头插法向循环单链表中插入一个结点，测试方法为：CycleLkListHeadInsert\n");
				LkNodeInput(lkNode);
				list->CycleLkListHeadInsert(cycleLkList,*lkNode);
				break;
			}
		case 4:
			{
				printf("您选择尾插法向循环单链表中插入一个结点，测试方法为：CycleLkListTrailInsert\n");
				LkNodeInput(lkNode);
				list->CycleLkListTrailInsert(cycleLkList,*lkNode);
				break;
			}
		case 5:
			{
				printf("您选择求循环单链表，测试属性为：length\n");
				printf("循环单链表的长度length = %d\n",cycleLkList->length);
				break;
			}
		case 6:
			{
				int order;
				printf("您选择查找循环单链表中指定序号的结点，测试方法为：CycleLkListFindByOrder\n");
				printf("请输入您要查找的序号：");
				scanf("%d",&order);
				if (ERROR == list->CycleLkListFindByOrder(cycleLkList,order,lkNode))
				{
					printf("指定序号超出范围，请重试\n");
				}
				else
				{
					LkNodeDisplay(lkNode);
				}

				break;
			}
		case 7:
			{
				printf("您选择按结点成员查找循环单链表中的所有结点，测试方法为：CycleLkListFindByLkNodeMember\n");
				list->CycleLkListInit(&outCycleLkList);
				if (FALSE == list->CycleLkListFindByLkNodeMember(cycleLkList,outCycleLkList,LkNodeMemberInput,LkNodeMemberEqual))
				{
					printf("未分配内存，请重试\n");
				}
				else
				{
					list->CycleLkListDisplay(outCycleLkList);
				}
				break;
			}
		case 8:
			{
				int order;
				LkNode *inLkNode;
				printf("您选择更新循环单链表指定序号的结点，测试方法为：CycleLkListUpdateByOrder\n");
				printf("请输入您要更新的序号：");
				scanf("%d",&order);
				if (order < 1 || order > cycleLkList->length)
				{
					printf("指定序号超出范围，请重试\n");
					break;
				}
				inLkNode = (LkNode *)malloc(sizeof(LkNode));
				if (NULL == inLkNode)
				{
					printf("未能给新结点分配空间\n");
				}
				LkNodeInput(inLkNode);
				list->CycleLkListUpdateByOrder(cycleLkList,order,*inLkNode);
				list->CycleLkListDisplay(cycleLkList);
				
				break;
			}
		case 9:
			{
				int order;
				LkNode *inLkNode;
				printf("您选择在指定序号后插入一个结点，测试方法为：CycleLkListInsertByOrder\n");
				printf("请输入您要更新的序号：");
				scanf("%d",&order);
				if (order < 1 || order > cycleLkList->length)
				{
					printf("指定序号超出范围，请重试\n");
					break;
				}
				inLkNode = (LkNode *)malloc(sizeof(LkNode));
				if (NULL == inLkNode)
				{
					printf("未能给新结点分配空间\n");
				}
				LkNodeInput(inLkNode);
				list->CycleLkListInsertByOrder(cycleLkList,order,*inLkNode);
				list->CycleLkListDisplay(cycleLkList);
				break;
			}
		case 10:
			{
				int order;
				printf("您选择删除循环单链表指定结点，测试方法为：CycleLkListDeleteByOrder\n");
				printf("请输入您要更新的序号：");
				scanf("%d",&order);
				if (order < 1 || order > cycleLkList->length)
				{
					printf("指定序号超出范围，请重试\n");
					break;
				}
				list->CycleLkListDeleteByOrder(cycleLkList,order);
				list->CycleLkListDisplay(cycleLkList);
				break;
			}
		case 11:
			{
				printf("您选择清空循环单链表，测试方法为：CycleLkListClear\n");
				list->CycleLkListClear(cycleLkList);
				break;
			}
		case 12:
			{
				printf("您选择判断循环链表是否为空，测试方法为：CycleLkListIsEmpty\n");
				if (TRUE != list->CycleLkListIsEmpty(cycleLkList))
				{
					printf("循环单链表不为空\n");
				}
				else
				{
					printf("循环单链表为空\n");
				}
				break;
			}
		case 13:
			{
				printf("您选择遍历循环链表，测试方法为：CycleLkListDisplay\n");
				list->CycleLkListDisplay(cycleLkList);
				break;
			}
		default:
			{
				printf("您选择默认——退出\n");
				exit(0);
			}
		}
	}
	return 0;
}

void menu()
{
	printf("***********************************************  ");
	printf("\n*          循 环 单 链 表 子 系 统            *");
	printf("\n***********************************************");
	printf("\n*     备注：头结点不为空循环单链表            *");
	printf("\n*     备注：以下方法都包含在List结构体中      *");
	printf("\n*     备注：先初始化List结构体—ListInit(默认)*");
	printf("\n*     备注：循环单链表先初始化、后创建、在插入*");
	printf("\n***********************************************");
	printf("\n*          0----------返        回            *");
	printf("\n*          1----------初   始   化            *");
	printf("\n*          2----------创        建            *");
	printf("\n*          3----------头   插   法            *");
	printf("\n*          4----------尾   插   法            *");
	printf("\n*          5----------求   表   长            *");
	printf("\n*          6----------按序号 查 找            *");
	printf("\n*          7----------按 值  查 找            *");
	printf("\n*          8----------更        新            *");
    printf("\n*          9----------插        入            *");
	printf("\n*         10----------删        除            *");
	printf("\n*         11----------清        空            *");
	printf("\n*         12----------判        空            *");
	printf("\n*         13----------显        示            *");
	printf("\n***********************************************");
}