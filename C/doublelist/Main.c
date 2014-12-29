#include "doublelist.h"

void menu();
void inputElement(elemType *peValue);
void outputElement(elemType *peValue);
WORD EqualElem(elemType *peSource, elemType *peTarget);

int main()
{
	List_t  DL;
	int iChoice;
	int iFlag = 1;
	//int iSize;
	int iState;

	DoubleListInit(&DL);

	while(iFlag)
    {
        menu();
        printf("\t请选择菜单号(0--6)：");
		fflush(stdin);
        scanf("%d",&iChoice);
        
        switch(iChoice)
        {
        case 0:
            {
                iFlag = 0;
			}
			break;
		case 1:
			{
				elemType Pvalue;
				Pvalue = DoubleListDisplay(&DL,outputElement);
				if (ILLEGAL == Pvalue)
				{
					printf("非法的双链表\n");
				}
				else if (ERROR == Pvalue)
				{
					printf("双链表为空\n");
				}
			}
			break;
        case 2:
            {
				elemType eSize;
				printf("\n想入表中的元素个数: ");
				inputElement(&eSize);

				iState = DoubleListHead(&DL, eSize, inputElement, EqualElem);


				if (TRUE == iState)
				{
					printf("\n插值成功！");
				}
				else if (ERROR == iState)
				{
					printf("输入插入表中元素个数有误！\n");
				}
				else
				{
					printf("无法插入！");
				}
			}
			break;
        case 3:
            {
				int iPostion = 0;
				elemType eOutValue;

				printf("\n请输入要删除第几位：");
				scanf("%d", &iPostion);

				iState = DoubleListDelete(&DL, iPostion, &eOutValue);

				if (TRUE == iState)
				{
					printf("删除成功！");
				}
				else if (ILLEGAL == iState)
				{
					printf("非法的链表!");
				}
				else if (FALSE == iState)
				{
					printf("链表为空!");
				}
				else
				{
					printf("要删除的位置出错！");
				}
			}
			break;
        case 4:
            {
				elemType eSize;
				printf("\n想入表中的元素个数: ");
				inputElement(&eSize);
				
				iState = DoubleListLast(&DL, eSize, inputElement, EqualElem);
				
				if (TRUE == iState)
				{
					printf("插值成功！");
				}
				else if (ERROR == iState)
				{
					printf("输入插入表中元素个数有误！\n");
				}
				else
				{
					printf("无法插入！");
				}
			}
			break;
		case 5:
			{
			    iState = DoubleListEmpty(&DL);

				if (TRUE == iState)
				{
					printf("空表，没有任何值！");
				}
				else
				{
					printf("表不为空，可读取数据");
				}
			}
			break;
		case 6:
			{
				elemType pOutValue;
				pOutValue = DoubleListLength(&DL);
				
				printf("表中元素个数: %d\n", pOutValue);
			}
			break;
		case 7:
			{
				int iPostion = 0;
				elemType eInValue;
				
				printf("\n请输入要插入到第几位：");
				scanf("%d", &iPostion);

				printf("\n想插入表中的元素: ");
				inputElement(&eInValue);

				iState = DoubleListInsert(&DL, iPostion, &eInValue, EqualElem);

				if (TRUE == iState)
				{
					printf("插入成功！");
				}
				else if (ILLEGAL == iState)
				{
					printf("非法的链表!");
				}
				else if (ERROR == iState)
				{
					printf("要插入的位置出错！");
				}
				else if (EXIST == iState)
				{
					printf("表中已有该元素");
				}
				else
				{
					printf("申请内存空间不成功");
				}
			}
			break;
		case 8:
			{
				int iOutPostion = 0;
				elemType eInValue = 0;

				printf("请输入要查找的元素值: ");
				inputElement(&eInValue);

				iState = DoubleListValueFind(&DL, &eInValue, &iOutPostion, EqualElem);

				if (EXIST == iState)
				{
					printf("元素%d在表中的第%d位!\n", eInValue, iOutPostion);
				}
				else if (NOEXIST == iState)
				{
					printf("表中没有元素: %d\n", eInValue);
				}
				else
				{
					printf("非法的链表!");
				}
			}
			break;
		default:
			{
				printf("输入序号错误！");
				break;
			}
        }
    }
	return 0;
}

void menu()
{
	printf("\n");
	printf("****************************************************\n");
	printf("\n*             双   链   表   系   统               *");
	printf("\n****************************************************");
	printf("\n*            0----------返      回                 *");
	printf("\n*            1----------遍      历                 *");
	printf("\n*                                                  *");
	printf("\n*            2----------头  插  法                 *");
	printf("\n*            3----------删      除                 *");
	printf("\n*            4----------尾  插  法                 *");
	printf("\n*                                                  *");
	printf("\n*            5----------判断表为空                 *");
	printf("\n*            6----------获取表中元素个数           *");
	printf("\n*            7----------插 入 元 素                *");
	printf("\n*            8----------查 找 元 素                *");
	printf("\n****************************************************");
	printf("\n");
	
}

void inputElement(elemType *peValue)
{
	scanf("%d", peValue);
}

void outputElement(elemType *peValue)
{
	printf("%d ", *peValue);
}

WORD EqualElem(elemType *peSource, elemType *peTarget)
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