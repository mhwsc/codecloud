#include<stdio.h>

int factor(int m){
	int i;
	int ret;
	int denominator=1;
	int member=1;
	for(i=1;i<=m;i++){
		member=i*member;
		denominator=m*denominator;
	}
	ret=member/denominator;
	
	return ret;
}
