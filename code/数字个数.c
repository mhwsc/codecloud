#include <stdio.h>

int CountDigit( int number, int digit );

int main()
{
    int number, digit;

    scanf("%d %d", &number, &digit);
    printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
int CountDigit( int number, int digit ){
    if(number<0){
        number=-number;
    }
    int ret=0;
    int a;
    while(number>0){
        a=number%10;
        if(a==digit){
            ret=ret+1;
        }
        number=number/10;
    }
    
    return ret;
}
