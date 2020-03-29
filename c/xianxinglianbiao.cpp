#include<stdio.h>
#include<stdlib.h>
typedef struct lnode *list;
typedef struct lnode{
    int date;
    list next;
}node;
list makeempty(list p){
    p=(list)malloc(sizeof(node));
    p->next=NULL;
    p->date=NULL;
    return p;
}
int getlen(list p){
    int j=0;
    for(p;p!=NULL;p=p->next){
        j++;
    }
    return j;
}
list findx(list p,int x){
    int j=0;
    while(p!=NULL&&j<x){
        p=p->next;
        j++;
    }
    if(j==k){
        return p;
    }else{
        return NULL;
    }
}
list addonex(list p,int x,int date){
    p=findx(p,x-1);
    list s;
    s=(list)malloc(sizeof(node));
    s->next=p->next;
    s->date=date;
    p->next=s;
    return p;
}
list deletex(list p,int x,int s){
    list date=findx(list p,x-2);
    s=date->next->date;
    date->next=date->next->next;
    free(date->next);
    return p;

}
int main(){
    list ptrl;
    ptrl=makeempty(ptrl);
}