#include<stdio.h>
#include<stdlib.h>
//#define maxsize 100; 

typedef struct lnode *list;
struct lnode{
	int a[100];
	int last;
}; 
struct lnode l;
list ptrl;
list makeempty(){
	list ptrl;
	ptrl=(list)malloc(sizeof(struct lnode));
	ptrl->last=-1;
	return ptrl;
}
int find(int x,list ptrl){
	int i=0;
	int ret;
	while(i<=ptrl->last&&ptrl->a[i]!=x){
		i++;
	}
	if(i>ptrl->last){
		ret= -1;
	}else {
		ret=i;
	}
	return ret;
}
void insert(int x,int i,list ptrl){
	int j;
	if(ptrl->last==100-1){
		printf("����");
		return; 
	}
	if(i<1||i>ptrl->last+2){
		printf("λ�ò��Ϸ�");
		return; 
	}
	for(j=ptrl->last;j>i-1;j--){
		ptrl->a[j+1]=ptrl->a[j];
	}
	ptrl->a[i-1]=x;
	ptrl->last++;
}
void listdelete(int i,list ptrl){
	int j;
	if(i<1||i>ptrl->last+1){
		printf("������");
		return; 
	}
	for(j=i;j<=ptrl->last;j++){
		ptrl->a[j-1]=ptrl->a[j];
	}
	ptrl->last--;
	return;
}
