#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define COMPARE(x,y) (x < y ? -1 :(x>y? 1: 0))
#define IS_FULL(x) !x
struct poly_node{
	float coef;
	int expon;
	struct poly_node* link;
};


typedef struct poly_node* poly_pointer;
poly_pointer avail =NULL;

poly_pointer get_node();
void ret_node(poly_pointer);
void cerase(poly_pointer*);
poly_pointer cpadd(poly_pointer,poly_pointer);
void attach(float,int,poly_pointer*);
void print_polynomial(poly_pointer);

int main(){
	poly_pointer a, a_rear,b,b_rear,d,c,e,f,g;
	a=get_node();
	printf("a pointer : %p\n",a);
	a->expon=-1;
	a->link=a;
	a_rear=a; 
	attach(3,14,&a_rear);
	attach(2,8,&a_rear);
	attach(1,0,&a_rear);
	
	b=get_node();
	printf("b pointer : %p\n",b);
	b->expon=-1;
	b->link=b;
	b_rear=b;
//	print_polynomial(b);
	attach(8,14,&b_rear);
	attach(-3,10,&b_rear);
	attach(10,6,&b_rear);
	
	d=cpadd(a,b);

//	print_polynomial(d);
	
	cerase(&a);
	cerase(&b);
	cerase(&d);

	a=get_node();
	b=get_node();
	d=get_node();
	c=get_node();
	e=get_node();
	f=get_node();
	g=get_node();
	return 0;
}

poly_pointer get_node(){
	poly_pointer node;
	if(avail){
		printf("if avail node=avail: %p\n",avail);
		node=avail;
		avail=avail->link;
	}else{
		node=(poly_pointer)malloc(sizeof(struct poly_node));
		if(IS_FULL(node)){
			fprintf(stderr,"memory full\n");
			exit(1);
		}
	}
}
void ret_node(poly_pointer ptr){
	ptr->link=avail;
	avail=ptr;
}

void cerase(poly_pointer *ptr){
	poly_pointer temp;
	printf("*ptr : %p\n",*ptr);
	printf("(*ptr)->link : %p\n",(*ptr)->link);
	printf("avail: %p\n\n",avail);
	if(*ptr){
		temp=(*ptr)->link;
		
		(*ptr)->link=avail;
		avail=temp;
		*ptr=NULL;
	}
}

poly_pointer cpadd(poly_pointer a,poly_pointer b){
	poly_pointer starta,d,lastd;
	int sum,done=FALSE;
	starta=a;
	a=a->link;
	b=b->link;
	d=get_node();
	d->expon=-1;
	lastd=d;
	printf("d pointer : %p\n",d);
	do{
		switch(COMPARE(a->expon,b->expon)){
			case -1:
				attach(b->coef,b->expon,&lastd);
				b=b->link;
				break;
			case 0:
				if(starta==a) done=TRUE;
				else{
					sum=a->coef+b->coef;
					if(sum){
						attach(sum,a->expon,&lastd);
						a=a->link;
						b=b->link;
					}
				}
				break;
			case 1:
				attach(a->coef,a->expon,&lastd);
				a=a->link;
				break;
		}
			
	}while(!done);
	lastd->link=d;
	return d;
}

void attach(float coefficient,int exponent,poly_pointer* ptr){
	poly_pointer temp;
	temp=(poly_pointer)malloc(sizeof(struct poly_node));
	
	if(IS_FULL(temp)){
		fprintf(stderr,"memory full\n");
		exit(1);
	}
	printf("attached reference : %p\n",temp);
	temp->coef=coefficient;
	temp->expon=exponent;
//	printf("attach ptr link: %p\n",(*ptr)->link);
	temp->link=(*ptr)->link;
	(*ptr)->link=temp;
	*ptr=temp;
}

void print_polynomial(poly_pointer a){
	poly_pointer temp=a->link;
	
	if(temp!=a){
		printf("%.1fx^%d",temp->coef,temp->expon);
		temp=temp->link;
	}
	while(temp!=a){
		if(temp->coef>=0.0) printf("+%.1fx^%d",temp->coef,temp->expon);
		else printf("%.1fx^%d",temp->coef,temp->expon);
		temp=temp->link;
	}
	printf("\n");
}
