#include<stdio.h>

void min_max(int a[],int len,int *min,int *max){
	int i;
	printf("minmax sizeof(a)=%lu\n",sizeof(a));
	*min=*max=a[0];
	for(i=1;i<len;i++){
		if(a[i]>*max){
			*max=a[i];
		}if(a[i]<*min){
			*min=a[i];
		} 
	}
}
