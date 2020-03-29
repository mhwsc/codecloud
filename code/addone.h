#include<stdio.h>
int *addone(int a[],int len){
	int i;
	for (i=0;i<=len;i++){
		a[i]=a[i]+1;
	}
	return a;
}
