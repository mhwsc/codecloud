#include<stdio.h>
#include<stdbool.h>

struct date{
	int day;
	int month;
	int year;
}; 
bool isLeap(struct date d);
int numbersofdays(struct date d);

int main(){
	struct date today,tomorrow;
	
	printf("请输入（日，月，年）（xxx，xxx，xxx）\n");
	scanf("%i %i %i",&today.day,&today.month,&today.year);
	if(today.day!=numbersofdays(today)){
		tomorrow.day=today.day+1;
		tomorrow.month=today.month;
		tomorrow.year=today.year;
	}else if(today.month==12){
		tomorrow.day=1;
		tomorrow.month=1;
		tomorrow.year=today.year+1;
	}else{
		tomorrow.day=1;
		tomorrow.month=today.month+1;
		tomorrow.year=today.year;
	}
	printf("tomorrow'date is %i-%i-%i. \n",tomorrow.day,tomorrow.month,tomorrow.year);
	return 0;
}


int numbersofdays(struct date d){
	int days;
	const int dayspermonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(d.month==2&&isLeap(d)){
		days=29;
	}else{
		days=dayspermonth[d.month-1];
	}
	return days;
}

bool isLeap(struct date d){
	bool leap=false;
	if(d.year%4==0&&d.year%100!=0||d.year%400==0){
		leap=true;
	}
	return leap;
}
