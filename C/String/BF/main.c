/*****************************************************************************
 * 文件名称： main.c
 * 内容摘要： BF算法测试main文件
 * 当前版本： V1.0
 * 作    者：liao
 * 完成日期： 2014年12月21日
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

#include "BruteForce.h"

int main(int argc, const char * argv[])
{
	SString S = {13,'a','b','a','b','c','a','b','c','a','c','b','a','b'};
    SString T = {5,'a','b','c','a','c'};  
    int iPos;  
    iPos = BFindex( S,  T, 1);
	printf("%d\n",iPos);
	if(FALSE == iPos)
	{
		printf("没有找到！");
	}
	else
	{
		printf("子串T在主串S中第%d位置之后的位置",iPos);
	}

	return 0; 
}