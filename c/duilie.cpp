#include<stdio.h>
#include<stdlib.h>
#include"swap.h"

#define true     1
#define false    0
#define ok       1
#define error    0
#define ile     -1
#define low     -2
//#define listcharge 100
//#define listnow    10
typedef struct qnode{
	int date;
	struct qnode *next;
}qnode,*qptr;
typedef struct{
	qptr front;
	qptr rear;
}lqueue;
int makequeue(lqueue &q){
	q.front=q.rear=(qptr)malloc(sizeof(qnode));
	if(!q.front){
		printf("空间分配失败");
		return error;
	}
	q.front->next=NULL;
	return ok;
}
int desqueue(lqueue &q){
	while(q.front){
		q.rear =q.front->next;
		free(q.front);
		q.front=q.rear;
	}
	return ok;
}
int addqueue(lqueue &q,int e){
	qptr p;
	p=(qptr)malloc(sizeof(qnode));
	p->date=e;
	p->next=NULL;
	q.rear->next=p;
	q.rear=p;
	return ok;
}
int delfront(lqueue &s,int &e){
	if(s.front==s.rear){
		printf("队列空");
		return error;
	}
	qptr p;
	p=s.front->next;
	e=p->date;
	s.front->next=p->next;
	if(s.rear==p){
		s.rear=s.front;
	}
	free(p);
	return ok;
}
int main(){
	
}
