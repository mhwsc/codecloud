#include<stdio.h>

int pyramid(int n){
    int i,j,t,s;
    for(i=1;i<n+1;i++){
        for(j=n-i;j>=1;j--){
            printf(" ");
        }
        for(t=1;t<=i;t++){
            printf("%d",i);
            printf(" ");
        }
        for(s=n-i;s>=1;s--){
            printf(" ");
        }

        if(i!=n){        
        printf("\n");
		}

    }
}
int main()
{    
    int n;

    scanf("%d", &n);
    pyramid(n);

    return 0;
}

