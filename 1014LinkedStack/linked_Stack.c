#include <stdio.h>
#include <stdlib.h>

#define MAX_STACKS 10
#define IS_FULL(x) !x
#define IS_EMPTY(x) !x

typedef struct {
	int key;
}element;

struct stack{
	element item;
	struct stack* link;
};

typedef struct stack* stack_pointer;

stack_pointer top[MAX_STACKS];

void add(stack_pointer*,element);
element delete(stack_pointer*);
void printStack(stack_pointer);

void main(){
	int i;
	for(i=0;i<10;i++){
		element e;
		e.key=i+1;
		add(&top[0],e);
		printStack(top[0]);
	}
	
	for(i=0;i<10;i++){
		element e;
		e=delete(&top[0]);
		printStack(top[0]);
	}
	
	
}

void add(stack_pointer *top,element item){
	stack_pointer temp=(stack_pointer)malloc(sizeof(struct stack));
	if(IS_FULL(temp)){
		fprintf(stderr,"stack is full\n");
		exit(1);
	}
	temp->item=item;
	temp->link=*top;
	*top=temp;
}

element delete(stack_pointer *top){
	stack_pointer temp=*top;
	element item;
	if(IS_EMPTY(temp)){
		fprintf(stderr,"Stack is empty\n");
		exit(1);
	}
	item=temp->item;
	*top=temp->link;
	free(temp);
	return item;
}
void printStack(stack_pointer top){
	stack_pointer temp=top;
	while(temp){
		printf("%2d ",temp->item.key);
		temp=temp->link;
	}
	printf("\n");
}
