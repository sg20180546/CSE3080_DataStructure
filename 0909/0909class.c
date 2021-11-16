#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1n

typedef struct{
	char name[10];
	int age;
	float salary;
} human;

int humans_equal(human person1, human person2){
	if(strcmp(person1.name,person2.name)){
		return FALSE;
	}
	if(person1.age!=person2.age) return FALSE;
	if(person1.salary!=person2.salary) return FALSE;
	return TRUE;
}


int main(void){
	human sungjin;
	sungjin.age=24;
	strcpy(sungjin.name,"sungjin");
	sungjin.salary=10;
	human onejung;
	
	
	onejung.age=24;
	strcpy(onejung.name,"sungjin");
	onejung.salary=10;
	
	if(humans_equal(sungjin,onejung)==TRUE){
		printf("true");
	}else{
		printf("False");
	}
	
	return 0;
}
