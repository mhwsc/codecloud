#include<stdio.h>
#include<stdlib.h>

typedef struct gnode *glist;
struct gnode{
	int tag;
	union{
		int date;
		glist sublist;
	}uregion;
	glist next;
}; 
