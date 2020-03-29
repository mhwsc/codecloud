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
#define addment 10

typedef struct{
    int *base;
	int *top;
	int stacksize;
}stack;
int makestack(stack &s){
	s.base=(int*)malloc(sizeof(int));
	if(!s.base){
		printf("·ÖÅä¿Õ¼äÊ§°Ü");
		return error;
	}
	s.top=s.base;
	s.stacksize=max;
	return ok;
}
int gettop(stack s,int &e){
	if(s.top==s.base){
		return error;
	}
	e=*(s.top-1);
	return ok;
}
int push(stack &s,int e){
	if(s.top-s.base>=s.stacksize){
		s.base=(int*)realloc(s.base,(s.stacksize+addment)*sizeof(int));
		if(!s.base){
			return error;
		}
		s.top=s.base+s.stacksize;
		s.stacksize=s.stacksize+addment;
	}
//	*s.top++=e;
	{
	    s.top++;
		*(s.top-1)=e;
	}
	return ok;
}
int poptop(stack &s,int &e){
	if(s.base==s.top){
		printf("Õ»¶Ñ¿Õ"); 
		return error;
	}
//	e=*--s.top;
//	
//	
	e=*(s.top-1);
	*(s.top-1)=*(s.top);
	s.top=s.top-1;
	printf("%d\n",e);
}

void sprint(stack &s){
	while(s.base!=s.top){
		printf("%d\t",*(s.base));
		s.base++;
	}
		
	printf("\n");
	
}
int main(){
	stack s;
	makestack(s);
	int i;
	int a;
	for(i=0;i<=5;i++){	

		scanf("%d",&a);
		push(s,a);
		
	}
	int e;
	poptop(s,e);	
	sprint(s);
}

