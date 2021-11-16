#include <stdio.h>
#define MAX_STACK_SIZE 10
#define INVALID_KEY -1
typedef struct{
	int key
} element;

int top=-1;
element stack[MAX_STACK_SIZE];

void push(element);
element pop();
void stackFull();
element stackEmpty();
void printStack();



void main(){
	int i;
	element e;
	
	for(i=0;i<5;i++){
		e.key=i;
		push(e);
		printf("key %d is insert in the stack\n",e.key);
	}
	for(i=0; i < 5; i++) {
    	e = pop();
    	printf("key %d deleted from the stack.\n", e.key);
  }
}



void push(element item){
	if(top>=MAX_STACK_SIZE-1) stackFull();
	stack[++top]=item;
}

element pop(){
	if(top==-1) return stackEmpty();
	return stack[top--];
}
void stackFull(){
	fprintf(stderr,"stack is Full, cannot add element\n");
	exit(-1);
}
element stackEmpty(){
	element e;
	e.key=INVALID_KEY;
	return e;
}
