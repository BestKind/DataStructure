/******************************************************************************
* 文件名称： dfsmain.c
* 内容摘要： 主函数主要用于测试
* 当前版本： V1.0
* 作 者：    KindIead
* 完成日期： 2014年12月22日
*
* 修改记录1：// 修改历史记录，包括修改日期、修改者及修改内容
* 修改日期：
* 版 本 号：
* 修 改 人：
* 修改内容：
* 修改记录2：
* @license ZPL (http://zpl.pub/v1)
* Copyright (c) 2014 SmallLeg Team
******************************************************************************/

#include <stdio.h>
#include "dfs.h"

int main(void){

		//动态创建存放边的指针数组   

        st_edge** pedge = (st_edge**)malloc(sizeof(st_edge*)*VERTEXNUM);
        int i;
        for(i=0;i<VERTEXNUM;i++){
                pedge[i] = NULL;
        }

		//存放顶点的遍历状态，0：未遍历，1：已遍历  

        int* pvertexStatusArr = (int*)malloc(sizeof(int)*VERTEXNUM);
        for(i=0;i<VERTEXNUM;i++){
                pvertexStatusArr[i] = 0;
        }

        printf("after init:\n");
        DisplayGraph(pedge);

		//创建图  

        CreateGraph(pedge,0,3);
        CreateGraph(pedge,0,4);
        CreateGraph(pedge,3,1);
        CreateGraph(pedge,3,2);
        CreateGraph(pedge,4,1);

        printf("after create:\n");
        DisplayGraph(pedge);

		//深度优先遍历 

        DFS(pedge, pvertexStatusArr);


		//释放邻接表占用的内存  
        DelGraph(pedge);
        pedge = NULL;

        free(pvertexStatusArr);
        pvertexStatusArr = NULL;



        return 0;
}