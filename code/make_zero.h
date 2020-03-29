#include<stdio.h>
int *make_zero(int a[],int len){
	int i=0;
	for(i=0;i<len;i++){
		a[i]=0;
	}
	return a;
}
