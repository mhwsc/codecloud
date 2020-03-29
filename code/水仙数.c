#include <stdio.h>

int narcissistic( int number );
void PrintN( int m, int n );

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);

    return 0;
}

/* 你的代码将被嵌在这里 */
int narcissistic( int number ){
	int cnt=0;
	int num=number;
	int m=0;
	int i;
	int ip=0;
	int n=number;

	while(number>0){
		cnt=cnt+1;
		number=number/10;
	}
	int array[cnt];
	for(i=0;i<cnt;i++){
		array[i]=0;
	}
	for(i=0;i<cnt;i++){
		array[i]=num%10;
		num=num/10;
		m=array[i]*array[i]*array[i]+m;
	}
	if(m==n){
		ip=1;
	}
	return ip;
}
void PrintN( int m, int n ){
	int p;
	for(p=m+1;p<n;p++){
		if (narcissistic(p)==1){
			printf("%d\n",p);
		}
	}
}
