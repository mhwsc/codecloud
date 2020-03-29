#include<stdio.h>

typedef union{
	int i;
	int c[4];
} mahuan;
int main(){
	mahuan gzy;
	gzy.i=1234;
	printf("%p\n",gzy.i);
	int n;
	for(n=0;n<4;n++){
		printf("p=%p\n",gzy.c[n]);
		//printf("d=%d\n",gzy.c[n]);
		//printf("%02hhX",gzy.c[n]);
	}
} 
