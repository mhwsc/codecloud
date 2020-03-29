#include<stdio.h>
#include<stdlib.h>

typedef struct snode *stack;
struct snode{
	int date;
	struct snode *next;
};
stack creatstack(){
	stack s;
	s=(stack)malloc(sizeof(struct snode));
	s->next=NULL;
	return s;
}
int isempty(stack s){
	return(s->next==NULL);
}
void push(int item,stack s){
	struct snode *tmpcell;
	tmpcell=(struct snode*)malloc(sizeof(struct snode));
	tmpcell->date=item;
	tmpcell->next=s->next;
	s->next=tmpcell;
}
int pop(stack s){
	struct snode *firstcell;
	int topelwm;
	if(isempty(s)){
		printf("¶ÑÕ»¿Õ");
		return NULL;
	}else{
		firstcell=s->next;
		s->next=firstcell->next;
		topelwm=firstcell->date;
		free(firstcell);
		return topelwm;
	}
} 
int main(){
	return 0;
}
