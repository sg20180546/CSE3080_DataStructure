#include <stdio.h>


int factorial_tail(int n,int total){
	if(n==1) return total;
	else return factorial(n-1,total*n);
	
} 

int factorial(int n){
	if(n==1) return 1;
	else return factorial(n-1)*n;
}


int main(void){
	printf("%d",factorial_tail(5,1));
	
	return 0;
}
