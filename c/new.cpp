/* 邻接表存储的图 - DFS */
 
void Visit( Vertex V )
{
    printf("正在访问顶点%d\n", V);
}
 
/* Visited[]为全局变量，已经初始化为false */
void DFS( LGraph Graph, Vertex V, void (*Visit)(Vertex) )
{   /* 以V为出发点对邻接表存储的图Graph进行DFS搜索 */
    PtrToAdjVNode W;
     
    Visit( V ); /* 访问第V个顶点 */
    Visited[V] = true; /* 标记V已访问 */
 
    for( W=Graph->G[V].FirstEdge; W; W=W->Next ) /* 对V的每个邻接点W->AdjV */
        if ( !Visited[W->AdjV] )    /* 若W->AdjV未被访问 */
            DFS( Graph, W->AdjV, Visit );    /* 则递归访问之 */
}
// #include<stdio.h>
// #include<stdlib.h>
// #define vertex int 
// #define max 10000
// #define weighttype int
// typedef struct enode *ptrtoenode;
// struct enode{
//     vertex v1,v2;
//     weighttype weight;
// };
// int main(){
//     int i=2;
//     int a[i];
// }





















bool visited[20];						//设置一个布尔数组
void BFS(ALGraph G,int i , int n)
{
	CirQueue Q;					//设置一个循环队列
	int j ,k;			
	InitQueue(&Q);				//初始化当前队列
	EdgeNode* p;					//设置一个结点指针P
	printf("v%d->",i);				//输出当前顶点
	EnQueue(&Q,i);				//将当前顶点放入循环队列
	visited[i] = true;				//设置当前顶点已经被访问
	while(!EmptyQueue(&Q))			//如果当前队列非空
	{
		k = DeQueue(&Q);					//从队列中取出某结点
		p = G[k].link;							//获取某结点的头结点
		while(p!=NULL)						//如果头节点非空
		{
			j = p ->adjvex;						//获取当前头节点的序号
			if(!visited[j])							//如果当前头节点没有被访问
			{
				printf("v%d->",j);				//输出当前节点
				visited[j] = true;				//设置当前节点已经被访问
				EnQueue(&Q,j);				//将当前访问节点放入循环队列
			}
			p = p->next;				 //P结点后移一格
		}
	}
	
}