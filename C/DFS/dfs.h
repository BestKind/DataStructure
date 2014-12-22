/**************************************************************************
*                     设置文件不能被重复编译                            *
**************************************************************************/

#ifndef _DFS_H_
#define _DFS_H_

/**************************************************************************
*                                全局变量                                 *
**************************************************************************/

#define VERTEXNUM 5

//存放顶点的邻接表元素  
typedef struct edge{
        int vertex;
        struct edge* pnext;
}st_edge;

/**************************************************************************
*                              函数声明                                   *
**************************************************************************/

void CreateGraph(st_edge** pedge, int start, int end);
void DisplayGraph(st_edge** pedge);
void DelGraph(st_edge** pedge);
void DFS(st_edge** pedge, int* pvertexStatusArr);
void DFSTraverse(st_edge** pedge, int i, int* pvertexStatusArr);

#endif  // end DFS.h
