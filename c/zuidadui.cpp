#include<stdio.h>
#include<stdlib.h>
typedef struct heapstruct *maxheap;
typedef struct heapstruct{
    int *date;
    int size;
    int capacity;
}heap;
#define maxsize 100
#define maxdate 10000
maxheap creatheap(maxheap h){
    h=(maxheap)malloc(sizeof(heap));
    h->date=(int*)malloc((maxsize+1)*sizeof(int));
    h->size=0;
    h->capacity=maxsize;
    h->date[0]=maxdate;
    return h;
}
maxheap insertx(maxheap h,int x){
    int i;
    h->size++;
    i=h->size;
    for(;h->date[i]<x;i=i/2){
        h->date[i]=h->date[i/2];
    }
    h->date[i]=x;
    return h;
}
int deletemax(maxheap h){
    int i,tmp,max,parent,child;
    max=h->date[1];
    tmp=h->date[h->size];
    h->size--;
    i=1;
    for(parent=1;parent*2<=h->size;parent=child){
        child=2*parent;
        if((child!=h->size)&&h->date[child+1]>h->date[child]){
            child++;
        }
        if(tmp>=h->date[child]){
            break;
        }else{
            h->date[parent]=h->date[child];
        }
    }
    h->date[parent]=tmp;
    return max;
}
int main(){
    maxheap h;
    h=creatheap(h);
    int x;
    insertx(h,x);
    deletemax(h);
    // printf("»á»á»á");
}