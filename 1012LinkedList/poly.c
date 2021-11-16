#include <stdio.h>
#include <stdlib.h>

#define COMPARE(x,y) (x < y ?  -1 : (x >y ? 1 : 0) )
#define IS_FULL(x) !x

struct poly_node{
	float coef;
	int expon;
	struct poly_node * link;
};

typedef struct poly_node* poly_pointer;
poly_pointer a, a_rear, b, b_rear, d;

poly_pointer padd(poly_pointer ,poly_pointer );
void attach(float, int, poly_pointer*);

void print_polynomial(poly_pointer);

void erase(poly_pointer *);
void eerase(poly_pointer);

int main(void){
	
	a=(poly_pointer)malloc(sizeof(struct poly_node));
//	print_polynomial(a);
	a->coef=3;
	a->expon=14;
	a_rear=a;
	attach(2,8,&a_rear);
	attach(1,0,&a_rear);
	
	b=(poly_pointer)malloc(sizeof(struct poly_node));
	b->coef=8;
	b->expon=14;
	b_rear=b;
	attach(-3,10,&b_rear);
	attach(10,6,&b_rear);
	
	d=padd(a,b);
	print_polynomial(d);
	

	eerase(a);
	eerase(b);
	eerase(d);
	return 0;
}

poly_pointer padd(poly_pointer a,poly_pointer b){
	poly_pointer front,rear,temp;
	float sum;
	rear= (poly_pointer)malloc(sizeof(struct poly_node));
	if(IS_FULL(rear)){
		fprintf(stderr,"The memory is full\n");
		exit(1);
	}
	front=rear;
	
	while(a&&b){
		switch(COMPARE(a->expon,b->expon)){
			case -1:
				attach(b->coef,b->expon,&rear);
				b=b->link;
				break;
			case 0:
				sum= a->coef + b->coef;
				if(sum) attach(sum,a->expon,&rear);
				a=a->link;
				b=b->link;
				break;
			case 1:
				attach(a->coef,a->expon,&rear);
				a=a->link;
				break;
		}
	}
	
	for(;a;a=a->link) attach(a->coef,a->expon,&rear);
	for(;b;b=b->link) attach(b->coef,b->expon,&rear);
	rear->link=NULL;
	

	temp=front;
//	print_polynomial(front);
	front=front->link;
	free(temp);
	return front;
}

void attach(float coefficient,int exponent,poly_pointer *ptr){
	poly_pointer temp;
	temp=(poly_pointer)malloc(sizeof(struct poly_node));
	if(IS_FULL(temp)){
		fprintf(stderr,"The memory is full\n");
		exit(1);
	}
	temp->coef=coefficient;
	temp->expon=exponent;
	temp->link=NULL; 
	(*ptr)->link=temp;
	*ptr=temp;
}


void print_polynomial(poly_pointer a){
	poly_pointer temp=a;
	if(temp){
		printf("%.1fx^%d",temp->coef,temp->expon);
	}
	temp=temp->link;
	while(temp){
		if(temp->coef>=0.0) printf("+%.1fx^%d",temp->coef,temp->expon);
		else printf("%.1fx^%d",temp->coef,temp->expon);
		
		temp=temp->link;
	}
	printf("\n");
}

void erase(poly_pointer *ptr){
	poly_pointer temp;
	while(*ptr){
		temp=*ptr;
		*ptr=(*ptr)->link;
		free(temp);
	}
}

void eerase(poly_pointer ptr){
	poly_pointer temp;
	while(ptr){
		temp=ptr;
		ptr=ptr->link;
		free(temp);
	}
}
