#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int Length=0;
int* MakeEmptyStack(int size){
	int* NewCell=(int*)malloc(sizeof(int)*size);
	
	return NewCell;
}

int IsEmptyStack(){
	return Length==0;
}

int Top(int* L){
	if(IsEmptyStack()){
		return;
	}
	return L[Length-1];
}

int Pop(int* L){
	if(IsEmptyStack()){
		return;
	}
	int tmp=L[Length-1];
	Length--;
	return tmp;
}

void Push(int x,int* L){
	if(Length==9) return;
	Length++;
	L[Length-1]=x;
}


int main(void){
	int* Stack=MakeEmptyStack(SIZE);
	Push(5,Stack);
	Push(10,Stack);
	Push(16,Stack);
	printf("%d\n",Top(Stack));
	printf("%d\n",Pop(Stack));
	printf("%d\n",Pop(Stack));
	printf("%d\n",Pop(Stack));
	free(Stack)
	return 0;
}
