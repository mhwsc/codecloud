#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
typedef struct lnode *list;
typedef struct lnode{
	int date[maxsize];
	int last;
}node;
list makeLenpty(list p){
	p=(list)malloc(sizeof(node));
	p->last=-1;
	if(!p) {
		printf("error");
	}
		return p;
}
int findx(int x,list ptrl){
	int i=0;
	while(i<=ptrl->last&&ptrl->date[i]!=x){
		i++
	}
	if(i>ptrl->last){
		printf("not found");
		return -1;
	}else{
		return 0;
	}
}
int getin(int x,list ptrl,int i){
	if(i>ptrl->last||i<=0){
		printf("error");
		return -1;
	}else{
		int j;
		for(j=ptrl->last;j>=i;j--){
			ptrl->date[j+1]=ptrl->date[j];
		}
		ptrl->date[i-1]=x;
		ptrl->last++;
		return 0;
	}
}
int deletei(int i,list ptrl){
	int j;
	for(j=i;j<=ptrl->last;j++){
		ptrl->date[j]=ptrl->date[j+1];
	}
	ptrl->last--;
	return 0;
}
int main(){
	list ptrl;
	ptrl=makeLenpty(ptrl);
	printf("%d",ptrl->last);
}
