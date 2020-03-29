#include<stdio.h>
#include<stdlib.h>

#define true     1
#define false    0
#define ok       1
#define error    0
#define ile     -1
#define low     -2
typedef int status;

#define listcharge 100
#define listnow    10

typedef struct{
	int *room;
	int lenth;
	int listsize;
}slist;

status creatslist(slist &l){
	l.room=(int*)malloc(listcharge*sizeof(int));
	if(!l.room){
		printf("分配空间失败");
		exit(low);
	}
	l.lenth=0;
	l.listsize=listcharge;
	return ok;
}//建立一个空表 
status listsearch(slist &l,int i,int e){
    int *newroom;
	if(i<1||i>=l.lenth+1){
		printf("位置不合法");
		return error;
	}
	if(l.lenth>l.listsize){
		
		newroom=(status*)realloc(l.room,(l.listsize+listcharge)*sizeof(int));
	}
	if(!newroom){
		printf("重新分配失败");
		return error;
	}
	l.room=newroom;
	l.listsize=l.listsize+listnow;
	status* q;
	status* p;
	q=&(l.room[i-1]);
	for(p=&l.room[l.lenth-1];p>=q;--p){
		*(p+1)=*p;
	}
	*q=e;
	++l.lenth;
	return ok;
} 
status listdelete(slist &l,int i,status &e){
	if(i<1||i>l.lenth){
		printf("位置不合法");
		return error; 
	}
	int *p;
	p=&(l.room[i-1]);
	e=*p;
	int *q;
	q=&l.room[l.lenth-1];
	for(p=&l.room[i];*p<=*q;p++){
		*(p-1)=*(p);
	}
	--l.lenth;
	return ok;
}  
int slocation(slist &l,int e){
	int i=1;
	int*p;
	p=l.room;
	while(i<=l.lenth&&((*p++)!=e)){
		++i;
	}
	if(i<=l.lenth){
		return i;
	}else{
		printf("未找到");
		return error;
	}
}
int addtwo(slist a,slist  b,slist &c){
	int *rooma;
	int *roomb;
	rooma=a.room;
	roomb=b.room;
	c.listsize=c.lenth=a.lenth+b.lenth;
	c.room=(int*)malloc((a.lenth+b.lenth)*sizeof(int));
	if(!c.room){
		printf("分配失败");
		return error;
	}
	int i;
	for(i=0;i<=a.lenth-1;i++){
		c.room[i]=a.room[i];
	}
	int count;
	for(i=a.lenth,count=0;i<a.lenth+b.lenth-1;i++,count++){
		c.room[i]=b.room[count];
	}
	int ret;
	int *max;
	for(ret=0;ret<=a.lenth+b.lenth-1;ret++){
		int s;
		for(s=ret;s<=a.lenth+b.lenth-1;s++){
			if(c.room[s] >=c.room[ret]){
				int t;
				t=c.room[s];
				c.room[ret]=c.room[s];
				c.room[s]=t;
				}
		}
	}
}
int main(){
	
}
