/******************************************************************************
* 文件名称： dfs.c
* 内容摘要： 实现图的创建、显示、释放存储空间、深度优先遍历等操作
* 当前版本： V1.0
* 作 者：KindIead
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
#include <malloc.h>
#include "dfs.h"

/*****************************************************************************
* 函数实现--公有部分 *
*****************************************************************************/



/*****************************************************************************
* 函数名称：CreateGraph(st_edge** pedge, int start, int end)
* 功能描述：创建图
*
* @param： st_edge** pedge 指向图结点的指针, start 起始结点, end 末尾结点
*
* @return：无
******************************************************************************/

void CreateGraph(st_edge** pedge, int start, int end){
        st_edge* pnewedge = (st_edge*)malloc(sizeof(st_edge));
        pnewedge->vertex = end;
        pnewedge->pnext = NULL;
        pedge = pedge + start;
        while(*pedge != NULL){
                pedge = &((*pedge)->pnext);
        }
        *pedge = pnewedge;
}

/*****************************************************************************
* 函数名称：DisplayGraph(st_edge** pedge)
* 功能描述：遍历图的存储顺序
*
* @param： st_edge** pedge 指向图结点的指针
*
* @return：无
******************************************************************************/

void DisplayGraph(st_edge** pedge){
        int i;
        st_edge* p;
        for(i=0;i<VERTEXNUM;i++){
                printf("%d:",i);
                p = *(pedge+i);
                while(p != NULL){
                        printf("%d ",p->vertex);
                        p = p->pnext;
                }
                printf("\n");
        }
}

/*****************************************************************************
* 函数名称：DelGraph(st_edge** pedge)
* 功能描述：释放邻接表占用的内存 
*
* @param： st_edge** pedge 指向图结点的指针
*
* @return：无
******************************************************************************/

void DelGraph(st_edge** pedge){
        int i;
        st_edge* p;
        st_edge* pdel;
        for(i=0;i<VERTEXNUM;i++){
                p = *(pedge+i);
                while(p != NULL){
                        pdel = p;
                        p = p->pnext;
                        free(pdel);
                }
                pedge[i] = NULL;
        }
        free(pedge);
}

/*****************************************************************************
* 函数名称：DFS(st_edge** pedge, int* pvertexStatusArr)
* 功能描述：深度优先遍历  
*
* @param： st_edge** pedge 指向图结点的指针,int* pvertexStatusArr 
*
* @return：无
******************************************************************************/

void DFS(st_edge** pedge, int* pvertexStatusArr){
        printf("start DFS graph:\n");
        int i;
        for(i=0;i<VERTEXNUM;i++){
			 DFSTraverse(pedge, i, pvertexStatusArr);
        }
        printf("\n");
}

/*****************************************************************************
* 函数名称：DFSTraverse(st_edge** pedge, int i, int* pvertexStatusArr)
* 功能描述：深度优先遍历结点遍历递归  
*
* @param： st_edge** pedge 指向图结点的指针,int i 第几个结点, int* pvertexStatusArr 
*
* @return：无
******************************************************************************/

void DFSTraverse(st_edge** pedge, int i, int* pvertexStatusArr){
        if(pvertexStatusArr[i] == 1){
                return;
        }
        printf("%d ",i);
        pvertexStatusArr[i] = 1;
        st_edge* p = *(pedge+i);
        while(p != NULL){
			 DFSTraverse(pedge, p->vertex, pvertexStatusArr);
                p = p->pnext;
        }
}