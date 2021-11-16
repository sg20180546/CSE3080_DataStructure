#include <stdio.h>
#include <stdlib.h>

#define MAX_STACKS 10
#define INVALID_KEY -1
typedef struct{
	int key;
} element;
element* stacks[2];

int top[2]={-1,-1};
int capacity[2]={1,1};
int num_copy=0;

void push(int , element);
element pop(int);
void stackFull(int);
element stackEmpty();
void printStack(int);

int main(void){
	int i, num_items=100;
	stacks[0]=(element*)malloc(sizeof(element)*capacity[0]);
	stacks[1]=(element*)malloc(sizeof(element)*capacity[1]);
	
	for(i=0;i<num_items;i++){
		element e;
		e.key=i;
		push(0,e);
		push(1,e);
	}
	printf("number of items inserted: %d\n", num_items * 2);
  	printf("number of memory copies: %d\n", num_copy);
//  	printStack(0);
}


void push(int stackIdx,element item){
	if(top[stackIdx]>=capacity[stackIdx]-1) stackFull(stackIdx);
	stacks[stackIdx][++top[stackIdx]]=item;
}
element pop(int stackIdx){
	if(top[stackIdx]==-1) return stackEmpty();
	return stacks[stackIdx][top[stackIdx]--];
}

void stackFull(int stackIdx){
	element * temp=stacks[stackIdx];
	capacity[stackIdx]++;
	printf("capacity : %d\n",capacity[stackIdx]);
	stacks[stackIdx]=(element*)realloc(stacks[stackIdx],sizeof(element)*capacity[stackIdx]);
	if(temp!=stacks[stackIdx]){
		printf("MEMORY COPY %p -> %p\n", temp, stacks[stackIdx]);
		num_copy++;
	}
}

element stackEmpty(){
	element e;
	e.key=INVALID_KEY;
	return e;
}

void printStack(int stackIdx){
	int i;
  	printf("stacks[%d] - address: %p, capacity: %d\n", stackIdx, stacks[stackIdx], capacity[stackIdx]);
    for(i=0; i<=top[stackIdx]; i++) {
    printf("%d ", stacks[stackIdx][i].key);
 	 }
 	 printf("\n");
}
