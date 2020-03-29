#include <stdio.h>
int getweight(int *arr,char *str)
{
    int cnt[128]={0};
    int i;
    int n=0;
    int len=0;
    gets(str);
    for(i = 0; str[i]!='\0'; ++i)
        cnt[str[i]]++;
    for(i=0;i<128; i ++){
        if(cnt[i]!=0){
            printf("%c:%d\n", i, cnt[i]);
            str[n]=i;
            arr[n]=cnt[i];
            n++;
        }         
    }
    return 0;
}