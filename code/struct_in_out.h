#include<stdio.h>
struct point{
	int x;
	int y;
}; 
void *getstruct(struct point p){
	scanf("%d",p.x);
	scanf("%d",p.y);
	printf("%d  %d",p.x,p.y);
}
void *outstruct(struct point p){
	printf("%d  %d",p.x,p.y);
}
