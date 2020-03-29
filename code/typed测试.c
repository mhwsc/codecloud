#include<stdio.h>

typedef struct ad{
	int c;
	int ch[2];
} mahuan;

int main(){
	mahuan d={1,{1,2}};
	printf("%d ",d.c);
	printf("%d ",d.ch[1]);
	printf("%d ",d.ch[0]);
	
} 
