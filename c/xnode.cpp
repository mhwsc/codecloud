#include<stdio.h>
#include<stdlib.h>
#include"swap.h"

#define true     1
#define false    0
#define ok       1
#define error    0
#define ile     -1
#define low     -2
#define max    100

typedef struct {
	int *base;
	int front;
	int rear;
}squeue;

int makeit(squeue &q){
	q.base=(int*)malloc(max*sizeof(int));
	if(!q.base){
		return error;
	}
	q.front=q.rear=0;
	return ok;
} 
int squeuelen(squeue &q){
	return (q.rear-q.front+max)%max;
}
int insqueue(squeue &q,int e){
	if((q.rear+1)%max==q.front){
		return error;
	}
	q.base[q.rear]=e;
	q.rear=q.rear+1;
	return ok;
}
int popsqueue(squeue &q,int &e){
	if(q.front=q.rear){
		return error;
	}
	e=q.base[q.front];
	q.front=q.front+1;
	return ok;
}
int main(){
	
}
