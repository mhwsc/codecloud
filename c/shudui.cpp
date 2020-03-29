#include<stdio.h>
#include<stdlib.h>

typedef struct hnode *heap;
struct hnode {
    int *date;
    int size;
    int capacity;
} treedui;
typedef heap maxheap;
typedef heap minheap;
#define maxdate 1000

maxheap creatheap(int maxsize){
    maxheap h=(maxheap)malloc(sizeof(treedui));
    h->date=(int*)malloc((maxsize+1)*sizeof(int));
    h->size=0;
    h->capacity=maxsize;
    h->date[0]=maxdate;

    return h;
}
bool isfull(maxheap h){
    return(h->size==h->capacity);
}
bool insert(maxheap h,int x){
    int i;
    if(isfull(h)){
        printf("堆满");
        return false;
    }
    i=++h->size;
    for(;h->date[i/2]<x;i/=2){
        h->date[i]=h->date[i/2];
    }
    h->date[i]=x;
    return true;
}
#define error -1

bool isempty(maxheap h){
    return(h->size==0);
}
int deletemax(maxheap h){
    int parent,child;
    int maxitem,x;
    if(isempty(h)){
        printf("堆空");
        return error;
    }
    maxitem=h->date[1];
    x=h->date[h->size--];
    for(parent=1;parent*2<=h->size;parent=child){
        child=2*parent;
        if((child!=h->size)&&h->date[child]<h->date[child+1]){
            child++;
        }
        if(x>h->date[child]){
            break;
        }else{
            h->date[parent]=h->date[child];
        }
    }      
     h->date[parent]=x;
     return maxitem;
}
int percdown(maxheap h,int p){
    int parent,child;
    int x,maxitem;
    x=h->date[p];
    for(parent=1;parent*2<=h->size;parent=child){
        child=2*parent;
        if((child!=h->size)&&(h->date[child]<h->date[child+1])){
            child++;
        }
        if(x>h->date[child]){
            break;
        }else{
            h->date[parent]=h->date[child];
        }
    }      
     h->date[parent]=x;
     return maxitem;
}
void buildheap(maxheap h){
    int i;
    for(i=h->size/2;i>0;i--){
        percdown(h,i);
    }
}
int main(){

}