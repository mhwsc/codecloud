/* �ڽӱ�洢��ͼ - DFS */
 
void Visit( Vertex V )
{
    printf("���ڷ��ʶ���%d\n", V);
}
 
/* Visited[]Ϊȫ�ֱ������Ѿ���ʼ��Ϊfalse */
void DFS( LGraph Graph, Vertex V, void (*Visit)(Vertex) )
{   /* ��VΪ��������ڽӱ�洢��ͼGraph����DFS���� */
    PtrToAdjVNode W;
     
    Visit( V ); /* ���ʵ�V������ */
    Visited[V] = true; /* ���V�ѷ��� */
 
    for( W=Graph->G[V].FirstEdge; W; W=W->Next ) /* ��V��ÿ���ڽӵ�W->AdjV */
        if ( !Visited[W->AdjV] )    /* ��W->AdjVδ������ */
            DFS( Graph, W->AdjV, Visit );    /* ��ݹ����֮ */
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





















bool visited[20];						//����һ����������
void BFS(ALGraph G,int i , int n)
{
	CirQueue Q;					//����һ��ѭ������
	int j ,k;			
	InitQueue(&Q);				//��ʼ����ǰ����
	EdgeNode* p;					//����һ�����ָ��P
	printf("v%d->",i);				//�����ǰ����
	EnQueue(&Q,i);				//����ǰ�������ѭ������
	visited[i] = true;				//���õ�ǰ�����Ѿ�������
	while(!EmptyQueue(&Q))			//�����ǰ���зǿ�
	{
		k = DeQueue(&Q);					//�Ӷ�����ȡ��ĳ���
		p = G[k].link;							//��ȡĳ����ͷ���
		while(p!=NULL)						//���ͷ�ڵ�ǿ�
		{
			j = p ->adjvex;						//��ȡ��ǰͷ�ڵ�����
			if(!visited[j])							//�����ǰͷ�ڵ�û�б�����
			{
				printf("v%d->",j);				//�����ǰ�ڵ�
				visited[j] = true;				//���õ�ǰ�ڵ��Ѿ�������
				EnQueue(&Q,j);				//����ǰ���ʽڵ����ѭ������
			}
			p = p->next;				 //P������һ��
		}
	}
	
}