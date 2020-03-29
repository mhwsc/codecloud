#include<stdio.h>
int max(int a[],int len){
	int maxid=0;
	int i;
	for(i=1;i<len;i++){
		if(a[maxid]<a[i]){
			maxid=i;
		}
	}
	return maxid;
}
