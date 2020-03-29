#include<stdio.h>
#include<stdlib.h>

#define listinitsize   100
#define listincrement  10
#define overflow   -2
#define ok   1

typedef struct{
	int *elem;
	int length;
	int listsize;
}sqlist;
//sqlist l;
typedef int status; 
status initlistsq(sqlist &l){
	l.elem=(int *)malloc(listinitsize*sizeof(int));
	if(!l.elem) exit(overflow);
	l.length=0;
	l.listsize=listinitsize;
	return ok;
} 
int main(){
	
}
