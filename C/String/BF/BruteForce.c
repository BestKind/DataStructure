/******************************************************************************
 * 文件名称： BruteForce.c
 * 内容摘要： 串的模式匹配BF算法
 * 当前版本： V1.0
 * 作    者： liao
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

int BFindex(SString S, SString T, int iPos)
{
	int i = iPos, j = 1;

	if (iPos <1 ||  iPos > S[0] ) exit(0);

	while(i<=S[0] && j<=T[0])
	{
		if(S[i] == T[j])
		{
			// 相等则往后比较
			++i; ++j;
		}
		else{
			// 不相等则从主串的第二个字符起再重新和子串进行比较
			i = i -j + 2;
			j = 1;
		}
	}
	if(j > T[0]) return i - T[0]; // 若j大于子串的长度，说明找到，返回位置

	return FALSE;
}
