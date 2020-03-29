#include<stdio.h>
#include<stdlib.h>
typedef struct tree *ptree;
typedef struct tree{
    int date;
    ptree left;
    ptree right;
    int flag;
}btree;

ptree newnode(int v){
    ptree t=(ptree)malloc(sizeof(btree));
    t->date=v;
    t->left=t->right=NULL;
    t->flag=0;
    return t;
}
ptree insert(ptree t,int v){
    if(!t){
        t=newnode(v);
    }else{
        if(v>t->date){
            t->right=insert(t->right,t);
        }else{
            t->left=insert(t->left,v);
        }
    }
    return t;
}
ptree maketree(ubr n){
    tree t;
    int i,v;
    scanf("%d",&v);
    t=newnode(v);
    for(i=1;i<n;i++){
        scanf("%d",&v);
        t=insert(t,v);
    }
    return t;
}
int tcheck(ptree t,int v){
    if(t->flag){
        if(v<t->date){
            return tcheck(t->left,v);
        }else if (v>t->date){
            return tcheck(t->right,v);
        }else{
            return 0;
        }
    }else{
        if(v==t->date){
            t->flag=1;
            return 1;
        }else{
            return 0;
        }
    }
}
int judge(ptree t,int n){
    int i,v,flag=0;
    scanf("%d",&v);
    if(v!=t->date){
        flag=1;
    }else{
        t->date=1;
    }
    for(i=1;i<n;i++){
        scanf("%d",&v);
        if((!flag)&&(!tcheck)){
            flag=1;
        }
        if(flag){
            return 0;
        }else{
            return 1;
        }
    }
}
//
void reset(ptree t){
    if(t->left){
        reset(t->left);
    }
    if(t->right){
        reset(t->right);
    }
    t->flag=0;
}
void freetree(ptree t){
    if(t->left){
        freetree(t->left);
    }
    if(t->right){
        freetree(ptree);
    }
    free(t);
}

int main(){
    int n,l,i;
    ptree t;
    scanf("%d",n);
    while(n){
        scanf("%d",l);
        t=maketree(n);
        for(i=0;i<n;i++){

        }
    }
}