#include<stdio.h>
#include<string.h>

void main(){
	char str[100];
//	char *eg_string;
//	eg_string=str;
	char c;
	//p=str;
	gets(str);
	scanf("%c",&c);
	
	int i;
	for(i=0;i<100;i++){
		if(str[i]!=c){
			printf("%c",str[i]);
			str[i]=str[i+1];
		}
	
	}
	
} 
//#include<stdio.h>
//int main(){
//	char string[100],*p;
//	p=string;
//	int i,num=0,word=0,blank=0,abc=0,shuzi=0;
//	char c;
//	gets(string);
//	for(i=0;(c=string[i])!='\0';i++){
//		if(c==' '){
//			word=0;
//			blank++;
//		}
//		else if(word==0){
//			word=1;
//			num=num+1;
//		}
//		if(*p>='a'&&*p<='z'){
//			abc++;
//		}else if(*p>='0'&&*p<='9');
//		shuzi++;
//	}
//	printf("%d\n",num); 
//	printf("%d\n",abc); 
//	printf("%d\n",shuzi);
//	printf("%d\n",blank);  
//} 
