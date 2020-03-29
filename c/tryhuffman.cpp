#include <stdio.h>
#include<stdlib.h>
#include"getweight.h"
#include<string.h>
#define max 1000000
typedef struct{
    int weight;
    int parent;
    int lchild;
    int rchild;
}treenode;
typedef treenode *pnode;
typedef char**huffmancode;
void stringcopy(char *s,int len,char *str){
    for(int i=0;i<len;i++){
        str[i]=s[i];
    }
}
void select(pnode ht,int k,int &s1,int &s2);
void arrcopy(int *b,int len,int *arr){
    for(int m=0;m<len;m++){
        arr[m]=b[m];
    }
}
void creathuffmantree(pnode ht,int *arr,int n){
    int M=2*n-1;
    if(n<=1){
        return;
    }
    int i;
    for(i=1;i<=n;i++){
        ht[i].weight=arr[i-1];
		ht[i].lchild = 0;
		ht[i].parent = 0;
		ht[i].rchild = 0;
    }
	for(; i <=M; i++){
		ht[i].weight = 0;
		ht[i].lchild = 0;
		ht[i].parent = 0;
		ht[i].rchild = 0;
	}
    for(i = n+1; i <= M; i++){
            int s1, s2;
            select(ht, i-1, s1, s2);
            ht[s1].parent = i;
            ht[s2].parent = i;
            ht[i].lchild = s1;
            ht[i].rchild = s2;
            ht[i].weight = ht[s1].weight + ht[s2].weight;
        }
}
void select(pnode ht,int k,int &s1,int &s2){
    int tmp=max;
    int tmpi=0;
    for(int i=1;i<=k;i++){
        if(!ht[i].parent){
            if(tmp>ht[i].weight){
                tmp=ht[i].weight;
                tmpi=i;
            }
        }
    }
    s1=tmpi;
    tmp=max;
    tmpi=0;
    for(int i=1;i<=k;i++){
        if((!ht[i].parent)&&(i!=s1)){
            if(tmp>ht[i].weight){
                tmp=ht[i].weight;
                tmpi=i;
            }
        }
    }
    s2=tmpi;
}
void printhuffmantree(pnode HT,char *str,int n){
    printf("开始打印哈夫曼树\n");
    int M=2*n-1;
	printf("data, weight, parent, lchild, rchild\n");
	for(int i = 1; i <= M; i++){
		if(i > n){
			printf("  -, %5d, %5d, %5d, %5d\n", HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
		}else{
			printf("  %c, %5d, %5d, %5d, %5d\n", str[i-1], HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
		}
	}
	printf("\n");
}
void encodinghuffmantree(pnode ht,huffmancode hc,int n){
    char tmp[n];
    tmp[n-1]='\0';
    int start,c,f;
    for(int i=1;i<=n;i++){
        start=n-1;
        c=i;
        f=ht[i].parent;
        while(f){
            if(ht[f].lchild==c){
                tmp[--start]='0';
            }else{
                tmp[--start]='1';
            }
            c=f;
            f=ht[f].parent;
        }
        hc[i]=(char*)malloc((n-start)*sizeof(char));
        strcpy(hc[i],&tmp[start]);
    }
}
void princode(huffmancode hc,char *str,int n){
    printf("\n");
	for(int i = 1; i <= n; i++){
		printf("%c:%s\n", str[i-1], hc[i]);
	}
	printf("\n");
}
void decodingHuffmanCode(pnode ht, char *str,char *test,int len,char *result,int n){
    int M=2*n-1;
    int p=M;
    int i=0;
    int j=0;
    while (i<len){
        if(test[i]=='0'){
            p=ht[p].lchild;
        }
        if(test[i]=='1'){
            p=ht[p].rchild;
        }
        if(p<=n){
            result[j]=str[p-1];
            j++;
            p=M;
        }
        i++;
    }
    result[j]='\0';
}

int main(){
    printf("开始编码哈夫曼树\n");
    char*a;
    a=(char*)malloc(100000*sizeof(char));
    int *b;
    b=(int*)malloc(1000000*sizeof(int));
    getweight(b,a); 
    int n;
    for(n=-1;b[n]!=0;n++);
    printf("共有%d个字符\n",n);
    char*str;
    str=(char*)malloc(n*sizeof(char));
    int *arr;
    arr=(int*)malloc(n*sizeof(int));
    stringcopy(a,n,str);
    arrcopy(b,n,arr);
    free(a);
    free(b);
    pnode ht;
    ht=(pnode)malloc((2*n)*sizeof(treenode));
    creathuffmantree(ht,arr,n);
    printhuffmantree(ht,str,n);
    huffmancode hc;
    hc=(char**)malloc((n+1)*sizeof(char*));
    encodinghuffmantree(ht,hc,n);
    princode(hc,str,n);
    printf("请输入要解码的密码\n");
    char*test;
    test=(char*)malloc(10000*sizeof(char));
    gets(test);
    int len;
    printf("编码%s对应的字符串是：\n", test);
    for(len=0;test[len]!=NULL;len++);
    char*code;
    code=(char*)malloc((len+1)*sizeof(char));
    for(int z=0;z<len;z++){
        code[z]=test[z];
    }
    char *result;
    result=(char*)malloc((30)*sizeof(char));
    decodingHuffmanCode(ht, str, code, len, result,n);
    printf("%s\n",result);
}
