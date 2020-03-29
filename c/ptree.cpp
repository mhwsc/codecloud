#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tree{
    char date;
    struct tree *lchild;
    struct tree *rchild;
}btree,*ptree;

ptree creattree();
void preorder(ptree t);
void inorder(ptree t);
void postorder(ptree t);
int isEqual(ptree T1,ptree T2);
ptree findtree(ptree t1);
ptree insert(int x,ptree t);
ptree finmin(ptree t){
    if(t){
        while(t->rchild){
            t=t->rchild;
        }
    }
    return t;
}

int main(){

}
ptree creattree(){
    int ch;
    ptree t;
    scanf("%c",&ch);
    if(ch==NULL){
        t=NULL;
    }else{
        t=(ptree)malloc(sizeof(btree));
        t->date=ch;
        t->lchild=creattree();
        t->rchild=creattree();
    }
    return t;
}

void preorder(ptree t){
    if(t){
        printf("%d",t->date);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
void inorder(ptree t){
    if(t){
    inorder(t->lchild);
    printf("%d",t->date);
    inorder(t->rchild);        
    }
}
void postorder(ptree t){
    postorder(t->lchild);
    postorder(t->rchild);
    printf("%d",t->date);
}

int isEqual(ptree T1,ptree T2)
{
    if(T1 == NULL && T2 == NULL){
        printf("都为空，相等");
        return 1;//
    }
        
    if(!T1||!T2){
        printf("不相等");
        return 0;
    }
    if(T1->date == T2->date){
        return isEqual(T1->lchild,T2->lchild) && isEqual(T1->rchild,T2->rchild);
    } 
    else {
         return 0;
    }
       
}
ptree findtree(ptree t,int e){
    if(!t){
        return NULL;
    }
    if(t->date>e){
        return findtree(t=t->lchild,e);
    }else if(t->date<e){
        return findtree(t=t->rchild,e);
    }else{
        return t;
    }
}
ptree insert(int x,ptree t){
    if(!t){
        t=(ptree)malloc(sizeof(ptree));
        t->date=x;
        t->lchild=NULL;
        t->rchild=NULL;
        //return t;
    }else if(t->date>x){
        t->lchild=insert(x,t->lchild);
    }else if(t->date<x){
        t->rchild=insert(x,t->rchild);
    }
    return t;
}
ptree tdelete(int x,ptree t){
    ptree tmp;
    if(!t){
        printf("未找到要删除的");
    }else if(x<t->date){
        t->lchild=tdelete(x,t->lchild);
    }else if(x>t->date){
        t->rchild=tdelete(x,t->rchild);
    }else{
        if(t->lchild&&t->rchild){
            tmp=finmin(t->rchild);
            t->date=tmp->date;
            t->rchild=tdelete(t->date,t->rchild);
        }else{
            tmp=t;
            if(!t->lchild){
                t=t->rchild;
            }else if(!t->rchild){
                t=t->lchild;
            }
            free(tmp);
        }
    }
     return t;
}