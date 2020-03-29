#include<stdio.h>
#include<stdlib.h>
typedef struct _treenode *bintree;
//typedef bintree position;
typedef struct _treenode{
    int date;
    bintree lchild;
    bintree rchild;
}treenode;
// bintree makeempty(bintree p){
//     p=(bintree)malloc(sizeof(treenode));
//     p->lchild=NULL;
//     p->rchild=NULL;
//     p->date=NULL;
//     return p;
// }
bintree finddate(bintree p,int x){
    if(!p) return NULL;
    if(x>p->date){
        return finddate(p->lchild,x);
    }else if(x<p->date){
        return finddate(p->rchild,x);
    }else{
        return p;
    }
    
}
bintree findmin(bintree p){
    if(!p){
        return NULL;
    }else if(!p->lchild){
        return p;
    }else{
        return findmin(p->lchild);
    }
}
bintree inserttree(bintree p,int x){
    if(!p){
        p=(bintree)malloc(sizeof(treenode));
        p->date=x;
        p->lchild=NULL;
        p->rchild=NULL;
    }else if(p->date>x){
        return inserttree(p->lchild,x);
    }else{
        return inserttree(p->rchild,x);
    }
    return p;
}
bintree deletetree(bintree p,int x){
    bintree tmp;
    if(p->date>x){
        deletetree(p->lchild,x);
    }else if(p->date<x){
        deletetree(p->rchild,x);
    }else {
        if(p->lchild&&p->rchild){
            tmp=findmin(p->rchild);
            p->date=tmp->date;
            p->rchild=deletetree(p->rchild,p->date);

        }else{
            tmp=p;
            if(!p->lchild){
                p=p->rchild;
            }else if(!p->rchild){
                p=p->lchild;
            }
            free(tmp);
        }
        
    }
     return p;
}
// bintree getmin(bintree p,bintree ret){
//     if(!p) return NULL;
//     int min;
// }
int main(){
    bintree tree;
    //tree=makeempty(tree);
    int x;
    bintree y;
    y=finddate(tree,x);
    // getmin(tree);
    inserttree(tree,x);
    int z;
    deletetree(tree,z);
}