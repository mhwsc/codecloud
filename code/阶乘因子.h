#include<stdio.h>

double cos(double m,double e){
	int i;
	double ret;
	double denominator=1;
	double member=1;
	double result=1;
	int ip=0;
	
	if(m<0){
		m=-m;
	} 
	while(ip!=1){
		for(i=1;i>0;i++){
			member=i*member;//µÃµ½½×³Ë 
			denominator=m*denominator;
			ret=denominator/member;
			if(i%2==0){
				if(i%4==0){
					result=result+ret;
				}else{
					result=result-ret;
				}	
			}
			if(ret<=e){
				ip=1; 
				break;
			}
		}
		if(ip==1){
			break;
		}
	}
	return result;
}
