/*
 ============================================================================
 Name        : calendar.c
 Author      : SATHISH A
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char month[50][50]={" ","January","February","March","April","May","June","July","August","September","October","November","December"};
int startingday (int year){

	int s1;
	int s2;
	int s3;
	int s4;
	s2=(year-1)/4;
	s3=(year-1)/100;
	s4=(year-1)/400;
	s1=(year+s2-s3+s4)%7;
	return s1;

}
void feb (int year){
	if(year%4==0||year%400==0||year%100==0){
		day[2]=29;
	}
	else{
		day[2]=28;
	}
}
void anotherfn2 (int year,int s1){
	int dayloop;
	int monthloop;
	for(monthloop=1;monthloop<=12;monthloop++){
	    printf("\n");
		printf("\n------------%s------------",month[monthloop]);
		printf("\n\nSUN  MON  TUE  WED  THU  FRI  SAT");
		printf("\n");
		for(dayloop=1;dayloop<=1+s1*5;dayloop++){
			printf(" ");
		}
		for(dayloop=1;dayloop<=day[monthloop];dayloop++){
			printf("%2d",dayloop);
			if((dayloop+s1)%7>0){
				printf("   ");
			}
			else{
				printf("\n");
			}
		}
		s1=(s1+day[monthloop])%7;

	}
}

int main(){

	int year,s1;


	setbuf(stdout,NULL);
	printf("ENTER A YEAR\t");
	scanf("%d",&year);
	s1=startingday(year);
	feb(year);
	anotherfn2(year,s1);
	return 0;
}


