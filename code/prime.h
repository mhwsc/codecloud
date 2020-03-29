#include<stdio.h>

int number_prime(int p) {
	    int ip=1;
    int i;
    if (p<=1){
        ip=0;
    }else{
    for(i=2;i<p;i++){
        if(p%i==0){
            ip=0;
        }
    }
    }
    return ip;
}
int numbers_sum_prime(int m,int n){
    int sum=0;
    int a,b;
    int ip=1;
    if(m>=2){
        for(a=m;a<=n;a=a+1){
        	    int ip=1;
            for(b=2;b<a;b=b+1){
                if(a%b==0){
                    ip=0;
                    break;
                }
            }
        if (ip==1){
        sum=sum+a;
        }
    }
    }else{
        for(a=2;a<=n;a++){
        	    int ip=1;
            for(b=2;b<a;b++){
                if(a%b==0){
                    ip=0;
                    break;
                }
            }
        if (ip==1){
        sum=sum+a;
            }
    }
    }
    return sum;
}


