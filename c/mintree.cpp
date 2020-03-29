#include<stdio.h>
#include<stdlib.h>
typedef struct hnode *heap;
struct hnode{
    int *date;
    int size;
    int capacity;
}treedui;
typedef heap minheap;
#define mindate 100

minheap creatinon(int maxsize){
    minheap h=(heap)malloc(sizeof(treedui));
    h->date=(int *)malloc((maxsize+1)*sizeof(int));
    h->size=0;
    h->capacity=maxsize;
    h->date[0]=mindate;

    return h;
}
bool isfull(minheap h){
    return(h->capacity==h->size);
}
bool insert(minheap h,int x){
    int i;
    if(isfull(h)){
        printf("full now");
        return false;
    }
    i=++h->size;
    for(;h->date[i/2]<x;i=i/2){
        h->date[i]=h->date[i/2];
    }
    h->date[i]=x;
    return true;
}
#define error -1
bool isempty(minheap h){
    return(h->size==0);
}
int deletemin(minheap h){
    int parent,child;
    int minitem,x;
    if(isempty(h)){
        return error;
    }
    minitem=h->date[1];
    x=h->date[h->size];
    h->size--;
    for(parent=1;parent*2<=h->size;parent=child){
        child=2*parent;
        if((child!=h->size)&&h->date[child]<h->date[child+1]){
            child++;
        }
        if(x<h->date[child]){
            break;
        }else{
            h->date[parent]=h->date[child];
        }
    }
    h->date[parent]=x;
    return minitem;
}
int percdown(minheap h,int p){
    int parent,child;
    int x,minitem;
    x=h->date[p]; 
        for(parent=1;parent*2<=h->size;parent=child){
            child=2*parent;
            if((child!=h->size)&&(h->date[child]>h->date[child+1])){
                child++;
            }
            if(x<h->date[child]){
                break;
            }else{
                h->date[parent]=h->date[child];
            }
        }
            h->date[parent]=x;
            return minitem;        
    }
void buildheap(minheap h){
    int i;
    for(i=h->size;i>0;i--){
        percdown(h,i);
    }
}
int main(){
	
}
