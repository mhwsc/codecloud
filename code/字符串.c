#include<stdio.h>
#include<string.h>

int main(){
//	char s[]="hrjcxnsjndjcjkd";
//	printf("%c",s[1]);
char s[]="dhchbah" ;
char t[]="dhchbh" ;
printf("s=%s\nt=%s\n",s,t);
printf("*s=%p\n*t=%p\n",*s,*t);
printf("s=%p\nt=%p\n",s,t);
printf("strlen=%lu\n",strlen(s));
printf("sizeof=%lu\n",sizeof(s));
if(strcmp(s,t)==0){
	printf("ojbk");
}else{
	printf("hhh");
}
} 
