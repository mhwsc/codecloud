#include<stdio.h>
#include<stdlib.h>

 struct dstack{
 	int date[100];
 	int top1;
 	int top2;
};
 void push(struct dstack *ptrs,int item,int tag){
 	if(ptrs->top2-ptrs->top1==1){
 		printf("��ջ��");
 		return;
	 }
	 if(tag==1){
	 	ptrs->date[++(ptrs->top1)]=item;
	 }else{
	 	ptrs->date[--(ptrs->top2)]=item;
	 }
 }
 int pop(struct dstack *ptrs,int tag){
 	if(tag==1){
 		if(ptrs->top1==-1){
 			printf("��ջ1��");
 			return NULL;
		 }else{
		 	return ptrs->date[(ptrs->top1)--];
		 }
	 }else{
	 	if(ptrs->top2==100){
	 		printf("��ջ2��");
			 return NULL; 
		 }else{
		 	return ptrs->date[(ptrs->top2)++];
		 }
	 }
 }
