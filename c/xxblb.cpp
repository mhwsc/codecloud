#include<stdio.h>
#include<stdlib.h>
#include"swap.h"

#define true     1
#define false    0
#define ok       1
#define error    0
#define ile     -1
#define low     -2
#define listcharge 100
#define listnow    10

typedef struct lnode{
	int date;
	struct lnode *next;
}lnode,*llist;

int getnode(llist l,int i,int &e){
	llist p;
	p=l->next;
	int j=1;
	while(p&&j<i){
		p=p->next;
		j++;
	}
	if(!p||j>i){
		return error;
	}
	e=p->date;
	return ok;
}//输出第i个节点 
//llist lcopy(llist a ,&lnode b){
//	llist p;
//	p=a;
//	int j=0;
//	while(p){
//		p=p->next;
//		j++;
//	}
//	b=(llist)malloc(j*sizeof(lnode));
//	for(b=b->next;a->next!=NULL;b=b->next){
//		a=a->next;
//		b->date=a->date;
//	}
//	return b;
//}
////	llist temp=l;
////	llist camp;
////	if(l){
////		llist cnode=new lnode;
////		cnode->date=temp->date;
////		cnode->next=NULL;
////		temp=temp->next;
////		b=cnode;
////		
////	}
//
////llist lcopy(llist l,llist cl)
////{
////	
////	llist temp=l;//临时指针，取l的值
////	
////	llist ctemp;
////	
////	if(l)
////	{	//先记录头节点位置
////		node *cnode=new node;//临时节点，接受temp的值
////		cnode->data=temp->data;
////                cnode->next=NULL;
////		temp=temp->next;
////		
////		cl=cnode;
////		cout<<"copy"<<cl->data;
////		ctemp=cl;
////		
////        while(temp)
////		{
////		
////			node *cnode=new node;//临时节点，接受temp的值
////			cnode->data=temp->data;
////                        cnode->next=NULL;
////			temp=temp->next;
////		
////			//将临时节点插入到链表；
////			ctemp->next=cnode;
////			ctemp=cnode;
////			cout<<"插入成功";
////		}
//// 
////	}
////	else
////		cl=NULL;
////	
////	return cl;
////}
////llist lcopy(llist head,llist p){
////	llist temp=head;
////	llist camp; 
////	for (p = head->next; p != NULL; p = p->next) {
////		//printf("%d ", p->date);
////	}
////}
int adde(llist l,int i,int e){
	llist p;
	p=l;
	int j=0;
	while(p&&j<(i-1)){
		p=p->next;
		j++;
	}
	if(!p||j>i){
		return error;
	}
	llist s;
	s=(llist)malloc(sizeof(lnode));
	s->date=e;
	s->next=p->next;
	p->next=s;
	return ok;
}//插入元素 
int ldelete(llist l,int i,int e){
	llist p;
	p=l;
	int j=0;
	while(p->next&&j<i-1){
		p=p->next;
		j++;
	}
	if(!p->next||j>i-1){
		return error;
	}
	llist q;
	q=p;
	p->next=q->next;
	e=q->date;
	free(q);
	return ok;
}
llist creatl(llist &l,int n){
	l=(llist)malloc(sizeof(lnode));
	l->next=NULL;
	int i;
	for(i=n;i>0;i--){
		llist p;
		p=(llist)malloc(sizeof(lnode));
		scanf("%d",&p->date);
		p->next=l->next;
		l->next=p;
	}
}
llist lcreattwo(llist &l,llist &m,int n){
	l=(llist)malloc(sizeof(lnode));
	m=(llist)malloc(sizeof(lnode));
	l->next=NULL;
	m->next=NULL;
	int i;
	for(i=n;i>0;i--){
		llist p;
		llist q;
		p=(llist)malloc(sizeof(lnode));
		q=(llist)malloc(sizeof(lnode));
		scanf("%d",&p->date);
		q->date=p->date;
		p->next=l->next;
		q->next=m->next;
		l->next=p;
		m->next=q;
	}
//	int j;
//	for(j=n;j>0;j--){
//		llist q;
//		q=(llist)malloc(sizeof(lnode));
//		scanf("%d",&q->date);
//		q->next=m->next;
//		m->next=q;
//	}
}
void gettwo(llist a, llist b) {
    //a=lcopy(m,a);
    //llist b=lcopy(n,n);
	llist p;
	for (p = a->next; p->next != NULL; p = p->next);//找到a的最后一个指针
	p->next = b->next;//让它指向b
	free(b);
	for (p = a->next; p != NULL; p = p->next) { 
		for (llist q = p->next; q != NULL; q = q->next) { //
			if (p->date < q->date) {
				swap(&p->date, &q->date);
			}
		}
	}
}
//llist gettwo(llist m,llist n,llist c) {
//	llist a=lcopy(m,a);
//	llist b=lcopy(n,b);
//	llist p;
//	for (p = a->next; p->next != NULL; p = p->next);//找到a的最后一个指针
//	p->next = b->next;//让它指向b
//	free(b);
//	for (p = a->next; p != NULL; p = p->next) { 
//		for (llist q = p->next; q != NULL; q = q->next) { //
//			if (p->date > q->date) {
//				swap(&p->date, &q->date);
//			}
//		}
//	}
////	c=lcopy(a,c);
////	free(a);
//}
//llist gettwo(llist &a,llist &b,llist &c){
////	c=(llist)malloc()
//llist p=a->next;
//llist q=b;
//	int i=0;
//	while(a->next){
//		a=a->next;
//		i++;
//	}
//	int j=0;
//	while(b->next){
//		b=b->next;
//		j++;
//	}
//	printf("a中链表节点数%d b中链表节点数%d",i,j);
////	c=(llist)malloc((i+j)*sizeof(lnode));
//	for (c=a->next; c->next!=NULL; c = c->next);
////    for(int h=0;i<=i-1;i++){
////    	c=a->next;
////    	c->date=a->date;
////    	c->next=a->next->next;
////	}
////	c->next=b->next; 
////	for(c=b->next;c->next!=NULL;c=c->next);
////	{
////		llist q;
////		for(q=c->next;q->next!=NULL;q=q->next){
////			if(q->date>c->date){
////				swap(&q->date,&c->date);
////			}
////		}
////	}
//}
void lprint(llist head) {
	llist p;
	for (p = head->next; p != NULL; p = p->next) {
		printf("%d ", p->date);
	}
	printf("\n");
}
int main(){
	llist m;
	llist p;
	lcreattwo(p,m,3);
	lprint(p);
    lprint(m);
//	lcopy(p,m);
//	llist q=creatl(q,3);
//	llist n=lcopy(p,n);
	
//	lprint(q);
////	llist m;
//    gettwo(m,n);
////	lprint(two);
	
//	lprint(n);
//	lprint(q);
//	lprint(m);
}
