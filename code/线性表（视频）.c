#include<stdio.h>
#include<stdlib.h>
//#define maxsize 100; 

typedef struct lnode *list;
struct lnode{
	int a[100];
	int last;
}; 
struct lnode l;
list ptrl;
list makeempty(){
	list ptrl;
	ptrl=(list)malloc(sizeof(struct lnode));
	ptrl->last=-1;
	return ptrl;
}
int find(int x,list ptrl){
	int i=0;
	int ret;
	while(i<=ptrl->last&&ptrl->a[i]!=x){
		i++;
	}
	if(i>ptrl->last){
		ret= -1;
	}else {
		ret=i;
	}
	return ret;
}
void insert(int x,int i,list ptrl){
	int j;
	if(ptrl->last==100-1){
		printf("����");
		return; 
	}
	if(i<1||i>ptrl->last+2){
		printf("λ�ò��Ϸ�");
		return; 
	}
	for(j=ptrl->last;j>i-1;j--){
		ptrl->a[j+1]=ptrl->a[j];
	}
	ptrl->a[i-1]=x;
	ptrl->last++;
}
void delete(int i,list ptrl){
	int j;
	if(i<1||i>ptrl->last+1){
		printf("������");
		return; 
	}
	for(j=i;j<=ptrl->last;j++){
		ptrl->a[j-1]=ptrl->a[j];
	}
	ptrl->last--;
	return;
}
int main(){
	
}
//typedef int Position;
//typedef struct LNode *List;
//struct LNode {
//    ElementType Data[MAXSIZE];
//    Position Last;
//};
//List PtrL;
// 
//
// 
///* ��ʼ�� */
//List MakeEmpty()
//{
//    List L;
// 
//    L = (List)malloc(sizeof(struct LNode));
//    L->Last = -1;
// 
//    return L;
//}
// 
///* ���� */
//#define ERROR -1
// 
//Position Find( List L, ElementType X )
//{
//    Position i = 0;
// 
//    while( i <= L->Last && L->Data[i]!= X )
//        i++;
//    if ( i > L->Last )  return ERROR; /* ���û�ҵ������ش�����Ϣ */
//    else  return i;  /* �ҵ��󷵻ص��Ǵ洢λ�� */
//}
// 
///* ���� */
///*ע��:�ڲ���λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P�Ǵ洢�±�λ�ã���0��ʼ�������߲�1*/
//bool Insert( List L, ElementType X, Position P ) 
//{ /* ��L��ָ��λ��Pǰ����һ����Ԫ��X */
//    Position i;
// 
//    if ( L->Last == MAXSIZE-1) {
//        /* ��ռ����������ܲ��� */
//        printf("����"); 
//        return false; 
//    }  
//    if ( P<0 || P>L->Last+1 ) { /* ������λ�õĺϷ��� */
//        printf("λ�ò��Ϸ�");
//        return false; 
//    } 
//    for( i=L->Last; i>=P; i-- )
//        L->Data[i+1] = L->Data[i]; /* ��λ��P���Ժ��Ԫ��˳������ƶ� */
//    L->Data[P] = X;  /* ��Ԫ�ز��� */
//    L->Last++;       /* Last��ָ�����Ԫ�� */
//    return true; 
//} 
// 
///* ɾ�� */
///*ע��:��ɾ��λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P�Ǵ洢�±�λ�ã���0��ʼ�������߲�1*/
//bool Delete( List L, Position P )
//{ /* ��L��ɾ��ָ��λ��P��Ԫ�� */
//    Position i;
// 
//    if( P<0 || P>L->Last ) { /* ���ձ�ɾ��λ�õĺϷ��� */
//        printf("λ��%d������Ԫ��", P ); 
//        return false; 
//    }
//    for( i=P+1; i<=L->Last; i++ )
//        L->Data[i-1] = L->Data[i]; /* ��λ��P+1���Ժ��Ԫ��˳����ǰ�ƶ� */
//    L->Last--; /* Last��ָ�����Ԫ�� */
//    return true;   
//}
////#include<stdio.h>
////typedef struct LNode*List;
////struct LNode{
////	int Data[20];
////	int Last;
////}; 
////struct LNode L;
////List PtrL;
//////#include<time.h>
//////void printN(int N);
////
//////void printN(int N){
//////	if(N){
//////		printN(N-1);
//////		printf("%d",N);
//////	}
//////}
////int main(){
////} 
