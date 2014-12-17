/*****************************************************************************
This file defines the structures, values, macros, and functions
used often.

@license ZPL (http://zpl.pub/v1)
Copyright (c) 2014  SmallLeg Team
******************************************************************************/

#ifndef _TYPES_H_
#define _TYPES_H_

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**************************************************************************
 *                          常量                                            *
 **************************************************************************/

typedef unsigned char       BYTE;
typedef signed   short  int WORD;
typedef signed   long   int DWORD;

/**************************************************************************
 *                          宏定义                                         *
 **************************************************************************/


#define ILLEGAL    5	// 不合法
#define OVERFLOW1 -5	// 溢出

#define OK         2	// 成功
#define ERROR     -2	// 错误

#define NOEXIST    3    // 不存在
#define ISEXIST   -3    // 已经存在

#define EQUAL     4		// 相等
#define UNEQUAL  -4		// 不等

#define TRUE      1
#define FALSE	  0

typedef enum bool
{
    false,
    true
}bool;

#ifdef  __cplusplus
}
#endif

#endif // end of _TYPES_H_