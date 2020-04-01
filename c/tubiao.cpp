#include<stdio.h>
#include<stdlib.h>
#define vertex int 
#define max 10000
#define weighttype int
typedef struct enode *ptrtoenode;
struct enode{
    vertex v1,v2;
    weighttype weight;
};
typedef ptrtoenode edge;
typedef struct adjvnode*ptrtoadjvnode;
struct adjvnode{
    vertex adjv;
    weighttype weight;
    ptrtoadjvnode next;
};
typedef struct vnode{
    ptrtoadjvnode firstedge;
    int date;
}adjlist[max];//

typedef struct gnode *ptrtognode;
struct gnode{
    int nv,ne;
    adjlist g;
};//定义图的指针
typedef ptrtognode lgraph;

lgraph creategraph(int vertexnum){
    vertex v,m;
    lgraph graph;
    graph=(lgraph)malloc(sizeof(struct gnode));
    graph->ne=0;
    graph->nv=vertexnum;
    for(int v=0;v<graph->nv;v++){
        graph->g[v].firstedge=0;
    }
    return graph;
}
void insertedge(lgraph graph,edge e){
    ptrtoadjvnode newnode;
    newnode=(ptrtoadjvnode)malloc(sizeof(struct adjvnode));
    newnode->adjv=e->v2;
    newnode->next=graph->g[e->v1].firstedge->next;
    graph->g[e->v1].firstedge=newnode;
}
void visit(vertex v){
    printf("正在访问顶点%d\n",v);
}


int dfs(lgraph graph,vertex v){
    int visited[graph->nv];
   for(int i=0;i<graph->nv;i++){
       visited[i]=0;
    }
   ptrtoadjvnode w;
   visit(v);
   visited[v]=1;
   for(w=graph->g[v].firstedge;w;w=w->next)
}


int main(){

}