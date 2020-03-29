#include<stdio.h>
#include<stdlib.h>
#define ERROR 0

struct qnode{
	int date[100];
	int rear;
	int front;
};
typedef struct qnode *queue;
void addq(queue ptrq, int item){
	if((ptrq->rear+1)%100==ptrq->front){
		printf("队列满");
		return;
	}
	ptrq->rear=(ptrq->rear+1)%100;
	ptrq->date[ptrq->rear]=item;
}
int deleteq(queue ptrq){
	if(ptrq->front==ptrq->rear){
		printf("队列空");
		return ERROR;
	}else{
		ptrq->front=(ptrq->front+1)%100;
		return ptrq->date[ptrq->front];
	}
}
int main(){
	
}
