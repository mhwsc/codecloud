#include<stdio.h>
#include<stdlib.h>
#define ERROR 0

struct node{
	int date;
	struct node*next;
};
struct qnode{
	struct node*rear;
	struct node*front;
};
typedef struct qnode*queue;
queue ptrq;
int deleteq(queue ptrq){
	struct node*frontcell;
	int frontelem;
	if(ptrq->front==NULL){
		printf("╤сап©у");
		return ERROR;
	}
	frontcell=ptrq->front;
	if(ptrq->front==ptrq->rear){
		ptrq->front=ptrq->rear=NULL;
	}else{
		ptrq->front=ptrq->front->next;
	}
	frontelem=frontcell->date;
	free(frontcell);
	return frontelem;
}
int main(){
	
}
