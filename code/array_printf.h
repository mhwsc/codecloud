#include<stdio.h>

int *array_printf(int a[],int len){
	int i;
	for(i=0;i<len;i++){
		printf("%d  ",a[i]);
	}
	return 0;
}
