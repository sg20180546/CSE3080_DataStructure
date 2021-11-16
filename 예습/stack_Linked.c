#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	int Info;
	struct _Node* Next;
}Node;

Node* top; // 시작점 

Node* makeEmptyStack(){
	return top;
}

int isEmptyStack(Node* L){ 
	return L==top; // L은 node의 bottom 
}

int Top(Node*L){
	if(isEmptyStack(L)) return;
	return (*top).Info;
}
int Pop(Node* L){
	if(isEmptyStack(L)) return;
	
	int tmp=Top(L);
	Node* temp=top;
	top=(*top).Next;
	free(temp);
	return tmp;
}


void Push(int x,Node* L){
	Node* NewCell=(Node*)malloc(sizeof(Node));
	(*NewCell).Info=x;
	(*NewCell).Next=top;
	top=NewCell;
}

void merge_sort(int *a,n){
	
	
	
}



int main(void){	
	Node* Stack=makeEmptyStack(); // NewStack==top 
	Push(43,Stack);
	Push(22,Stack);
	Push(3,Stack);
	Push(99,Stack);
	printf("%d\n",Top(Stack));
	printf("%d\n",Pop(Stack));
	printf("%d\n",Pop(Stack));
	Push(155,Stack);
	printf("%d\n",Pop(Stack));
	printf("%d\n",Pop(Stack));
	printf("%d\n",Pop(Stack));	
	return 0;
}
