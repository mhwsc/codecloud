#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"getweight.h"

typedef struct _node
{
	char val;
	int weight;
	struct _node *p;
	struct _node *l;
	struct _node *r;
		
}node; //树节点
 
typedef struct l_node
{
	node *ln;	
	struct l_node *prev;
	struct l_node *next;
}lnode;//链表节点
 
typedef struct 
{
	node *head;	
}huf_tree;//树头结点
 
typedef struct  
{
	lnode *head;	
}list;//链表头

int main(){
    huf_tree ht;
    list lst;
    int i=0;
    ht.head=(node*)malloc(sizeof(node));
    ht.head->p=NULL;
    ht.head->l=NULL;
    ht.head->r=NULL;
    lst.head=(lnode*)malloc(sizeof(lnode));
    lst.head->next=NULL;
    lst.head->prev=NULL;

    printf("star huffman \n");
    char *str;
    str=(char*)malloc(26*sizeof(char));
    int *arr;
    arr=(int*)malloc(50*sizeof(int));
    printf("please put in chars\n");
    getweight(arr,str);
    int n;
    for(n=0;arr[n]!='\0';n++){
        n=n+1;
    }
    for(i=0;i<n;i++){
        node*nd=(node*)malloc(sizeof(node));
        nd->val=str[i];
        nd->weight=arr[i];
        nd->p=NULL;
        nd->l=NULL;
        nd->r=NULL;
        add_list(&lst,nd);
    }
}