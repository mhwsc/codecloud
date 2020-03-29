#include<stdio.h>
#include<stdlib.h>

typedef struct snode *stack;
struct snode{
    int date[100];
	int top; 
};

void push(stack ptrs,int item){
	if(ptrs->top==9){
		printf("Õ»¶ÑÂú");return;
	}else{
		ptrs->date[++(ptrs->top)]=item;
		return;
	}
}
int pop(stack ptrs){
	if(ptrs->top==-1){
		printf("Õ»¶Ñ¿Õ")£»
		return ERROR; 
	}else{
		return(ptrs->date[(ptrs->top)--]); 
	}
}
