#include<stdio.h>
#include<stdlib.h>
#define maxvertexnume 100
typedef int vertex;
typedef int weighttype;
typedef struct gnode *ptrtognode;
struct gnode{
    int nv;//顶点数
    int ne;//边数
    int g[maxvertexnume][maxvertexnume];//边的值
    int date[maxvertexnume];
};
typedef ptrtognode mgraph;


typedef struct enode *ptrtoenode;
struct enode{
    vertex v1,v2;
    weighttype weight;
};
typedef ptrtoenode edge;

mgraph creategraph(int vertexnum){
    mgraph graph;
    graph=(mgraph)malloc(sizeof(struct gnode));
    graph->nv=vertexnum;
    graph->ne=0;
    vertex v,w;
    for(v=0;v<graph->nv;v++){
        for(w=0;w<graph->ne;w++){
            graph->g[v][w]=0;
        }
    }
    return graph;
}
void insertedge(mgraph graph,edge e){
    graph->g[e->v1][e->v2]=e->weight;
    //还有双向
    graph->g[e->v2][e->v1]=e->weight;
}
mgraph buildgraph(){
    mgraph graph;
    vertex nv,ne;
    
    scanf("%d",&nv);
    graph=creategraph(nv);
    scanf("%d",&graph->ne);
    if(graph->ne!=0){
        edge e;
        e=(edge)malloc(sizeof(struct enode));
        for(int i=0;i<graph->ne;i++){
            scanf("%d %d %d",&e->v1,&e->v2,e->weight);
            insertedge(graph,e);
        }
    }
    for(vertex v;v<graph->nv;v++){
        scanf("%d",&(graph->date[v]));
    }
    return graph;
}
//void build