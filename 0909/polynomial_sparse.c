#include <stdio.h>
#define MAX_TERMS 100

typedef struct{
	int expon;
	int coef;
}polynomial;


polynomial terms[MAX_TERMS];

int current=0;
void print_polynomial(int start,int finish){
	int i;
	for(i=start;i<finish;i++){
		printf("%dx^%d + ",terms[i].coef,terms[i].expon);
	}
	printf("%d\n",terms[finish].coef);
	
}

void polynomial_add(int As, int Af, int Bs, int Bf, int* Cs, int* Cf){
	int i;
	*Cs=current;
	int length=As-Af > Bs-Bf ? As-Af:Bs-Bf;
	while(1){
		int tmp=terms[As].expon-terms[Bs].expon;
		
		if(tmp==0){
			terms[current].expon=terms[As].expon;
			terms[current].coef=terms[As].coef+terms[Bs].coef;
			As++; Bs++; current++;
		}else if(tmp>0){
			terms[current].expon=terms[As].expon;
			terms[current].coef=terms[As].coef;
			As++; current++;
		}else{
			terms[current].expon=terms[Bs].expon;
			terms[current].coef=terms[Bs].coef;
			Bs++; current++;
		}
		
		if(As>Af&&Bs>Bf){
			*Cf=--current;
			break;	
		} 
		
	}
	
}



int main(void){
	int As,Af,Bs,Bf,Cs,Cf; 
	
//	p1: x^4 + 10x^3 + 3x^2 + 1
	As=current;
	terms[current].expon=4; terms[current].coef=1;
	current++;
	terms[current].expon=3; terms[current].coef=10;
	current++;
	terms[current].expon=2; terms[current].coef=3;
	current++;
	terms[current].expon=0; terms[current].coef=1;
	Af=current++;
	
	Bs=current;
	terms[current].expon=2; terms[current].coef=3;
	current++;
	terms[current].expon=1; terms[current].coef=2;
	current++;
	terms[current].expon=0; terms[current].coef=4;
	Bf=current++;
	
	print_polynomial(As,Af);
	print_polynomial(Bs,Bf);
	polynomial_add(As,Af,Bs,Bf,&Cs,&Cf);
	print_polynomial(Cs,Cf);
	
	return 0;
}
