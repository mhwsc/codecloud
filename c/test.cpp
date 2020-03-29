// <pre name="code" class="cpp">/*
// 1.	将提供的字符串（自定义字符串）进行排序，获取各个字符的权重；
// 2.  将字符及对应的权重放入树节点（node）中，用链表将各个节点有序的（按权重升序）链接；
// 3.  实现链表的增、删功能；
// 4.  遍历链表，将链表的前两个节点中权重相加，生成新节点，然后将新节点插入到有序链表中；
// 5.  直到链表中只剩一个节点时，将此节点赋给哈夫曼树头；
// 6.  利用创建的哈夫曼树得到编码； 用递归得到叶子节点，由叶子节点追溯到根节点，得到编码后反转顺序；
// */
 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXL 20 //自定义字符串的最大长度；
 
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
 
char arr[ MAXL ];//有效字符串数组；排重之后的数组，和权重数组一一对应；
int w_a[ MAXL ];//权重数组； 
 
void get_weight(char *ch,int c_long)//从排完序的字符串中得到有效字符和对应的权重；
{
	char a_s=ch[0];
	int i=0,j=0;
	while(i<c_long)
	{
		if(ch[i]==a_s)
		{			
			w_a[j]++;
			i++;	
		}	else{
			arr[j]=a_s;
			j++;
			a_s=ch[i];
		}		
	}
	arr[j]=a_s;	
}
 
int quick_part(char *s,int low,int hight)//对字符串进行快排，
{
	char f_s=s[low];
	int i,j;
	i=low; j=hight;
	while(i<j){
		while(i<j&&s[j]>=f_s) j--;
		if(i<j) s[i++]=s[j];
		while(i<j && s[i]<=f_s) i++;
		if(i<j) s[j]=s[i];
	}	
	s[i]=f_s;
	if((i-1)>low)
		quick_part(s,low,i-1);
	if((i+1)<hight)
		quick_part(s,i+1,hight);
}
 
void r_arr(char *p) //反转字符串
{
	int sz=strlen(p);
	int i=0;
	for(i;i<sz-i;i++)
	{
		char t;
		t=p[i];
		p[i]=p[sz-i-1];
		p[sz-i-1]=t;
	}	
}
 
void print_tree( node *n)//遍历哈夫曼树
{
		node *nd=n;
		if(nd!=NULL){
				
				print_tree(nd->r);
				print_tree(nd->l);
				node *sn=nd;
				if(nd->val != '\0'){
					printf("%c  ",nd->val);
					char p[10]={};
					int i=0;
					while(sn->p != NULL)
						{
	
							if(sn->p->l==sn){
								p[i]='0';
								i++;
							}
							if(sn->p->r==sn){
								p[i]='1';
								i++;	
							}
							sn=sn->p;
							
						}
						r_arr(p);
					printf("%s\n",p);
					
				}
		
		}
		
}
 
void del_list(list *lst,lnode *p)//删除链表里面的指定节点；
{
	lnode *lnd=lst->head->next;
	while(lnd!=NULL){
		if(lnd == p)
		{
				if(lnd->next == NULL){
					lst->head->next=NULL;
					 free(p);
				}else{
					lnd->prev->next=lnd->next;
					lnd->next->prev=lnd->prev;
					node *s=p->ln;
					free (p);
				}
				break;
		}
		lnd=lnd->next;
	}
}
 
void add_list(list *lst,node *nd)//向链表中添加节点；
{
	lnode *sn=lst->head;//申请一块链表节点，并使其指向链表头
	lnode *new_node=(lnode*)malloc(sizeof(lnode));//新申请一块链表空间
		new_node->prev=NULL;//初始化
		new_node->next=NULL;//初始化
		new_node->ln=nd;//树节点nd作为链表节点的上的树节点ln
		
	if(lst->head->next==NULL)//如果是光秃秃的head
		{
			lst->head->next=new_node;//将链表头节点指向新申请的链表节点newnode
			new_node->prev=lst->head;	//将newnode的pre指针指向链表头节点
			return ;
		}
 
	while(sn->next!=NULL)//如果存在链表子节点
	{
		if(sn->next->ln->weight > nd->weight)//如果链表上树节点的weight比新增树节点weight要大
		{
			new_node->prev = sn->next->prev;//
			new_node->next = sn->next;
			sn->next=new_node;
			new_node->next->prev=new_node;
			sn=sn->next;
			break;
		}else {	
			sn=sn->next;
		}
	}
	if(sn->next==NULL){
		sn->next=new_node;
		new_node->prev=sn;
	}
}
 
void print_list(list *lst)//打印链表；
{
	lnode *lnd=lst->head->next;
	while(lnd!=NULL)
		{
			printf("val= %c ,weight= %d \n",lnd->ln->val,lnd->ln->weight);	
			lnd=lnd->next;
		}	
}
 
void add_tree(huf_tree *hr, list *lst)//创建哈夫曼树
{
		node *hnd=hr->head;
		lnode *lnd=lst->head->next;
		//循环：每次将权重最小的两个节点合并成一个新节点，删除权重最小的这两个节点，并将新节点插入链表
		while(lnd!=NULL && lnd->next!=NULL)
		{
			node *n_node=(node*)malloc(sizeof(node));
			n_node->val='\0';
			n_node->weight = lnd->ln->weight + lnd->next->ln->weight;
			n_node->l=lnd->ln;
			n_node->r=lnd->next->ln;
			n_node->p=NULL;
			
			lnd->ln->p=n_node;
			lnd->next->ln->p=n_node;
			del_list(lst,lnd);
			del_list(lst,lnd->next);
			add_list(lst,n_node);
			//printf("=====================\n");
			//print_list(lst);
			lnd=lst->head->next;
		}
		if(lst->head->next != NULL)//链表中只剩下一个节点时，将此节点的数据赋给哈夫曼树的头结点；
		hr->head=lst->head->next->ln;
}
 
void de_tree(huf_tree *ht,char *dp)
{
	int sz=strlen(dp);
	int i=0;
	node *hn=ht->head;
	for(i=0;i<sz&&hn!=NULL;i++)
	{
		if(dp[i]=='0')hn=hn->l;
		if(dp[i]=='1')hn=hn->r;	
		if(hn->val!='\0'){
			printf("%c",hn->val);		
			hn=ht->head;
		}
	}
	printf("\n");
}
 
int main(int argv,char **argc)
{
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
	strcpy(arr,"jdlasjdlajhfhioe");	//自定义字符串数组
	quick_part(arr,0,15);//快排
	get_weight(arr,strlen(arr));//获取各个字符的权重；
	
	for(i=0;w_a[i]!=0;i++)//创建有序链表（以权重排序）
	{
		node *nd=(node*)malloc(sizeof(node));
		nd->val=arr[i];
		nd->weight=w_a[i];
		nd->p=NULL;
		nd->l=NULL;
		nd->r=NULL;
		add_list(	&lst,nd);
	}
	print_list(&lst);//打印链表
	add_tree(&ht,&lst);//创建哈夫曼树；
	print_tree(ht.head);//打印树，包括字符的编码，编码未保存，直接打印出来了；
	if(argv==2)
	de_tree(&ht,argc[1]);//解码
}