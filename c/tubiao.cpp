#include<stdio.h>
#include<stdlib.h>
#define vertex int 
#define max 10000
typedef struct gnode *ptrtognode;
struct gnode{
    int nv;
    int ne;
    adjlist g;
};
//����ͼ

typedef ptrtognode lgraph;
typedef struct vnode{
    ptrtoadjvnode firstedge;
    int date;
}adjlist[max];
//ͼ�еĽڵ�

typedef struct adjvnode *ptrtoadjvnode;
struct adjvnode{
    vertex adjv;//��ָ��Ľڵ�
    int weight;
    ptrtoadjvnode next;
};
//��

typedef struct enode *ptrtoenode;
struct enode{
    vertex v1,v2;
    weighttype weight;
};
//����ߵ��м���ʱ����

typedef ptrtoenode edge;
lgraph creategraph(int vertexnum){
    vertex v,m;
    lgraph graph;
    graph=(lgraph)malloc(sizeof(struct gnode));
    graph->ne=0;
    graph->nv=vertexnum;
    for(int v=0;v<graph->nv;v++){
        graph->g[v].firstedge=0;
    }
}
void insertedge(lgraph graph,edge e){
    ptrtoadjvnode newnode;
    newnode=(ptrtoadjvnode)malloc(sizeof(struct adjvmode));
    newnode->adjv=e->v2;
    newnode->next=graph->g[e->v1].firstedge->next;
    graph->g[e->v1].firstedge=newnode;
}