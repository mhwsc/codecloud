#include<stdio.h>
#include<stdlib.h>
#include"swap.h"

#define true     1
#define false    0
#define ok       1
#define error    0
#define ile     -1
#define low     -2

typedef struct bitnode{
	int date;
    bitnode*right;
	bitnode *left;
}btree,*ptree;
int qtravel(ptree &t){
	if(t){
		printf("%d",t->date);
		qtravel(t=t->left);
		qtravel(t=t->right);
	}
}
int tcreat(ptree t,int e){
	t=(ptree)malloc(sizeof(btree));
	//t->left=(ptree)malloc(sizeof(btree));
	t->left=NULL;
	//t->right=(ptree)malloc(sizeof(btree));
	 t->right=NULL;
	 t->date=e;
	if(t->date==e){
		printf("successful");
		return error;
	}else{
		printf("fail");
		return ok;
	}
}
int tpush(ptree t,int e){
	// if(!t){
	// 	printf("nomean");
	// }else{
	// 	printf("countinue");
	// }
	if(t->date){
		t->date=e;
	}else if(t->date>=e){
		ptree q;
		q=(ptree)malloc(sizeof(btree));
		t->left=q;
		q->date=e;
		printf("%d",q->date);
	}
	
}

int main(){
	ptree t;
	tcreat(t,1);
//	tpush(t,1);
	qtravel(t);
    return 0;
}

