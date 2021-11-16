#include <stdio.h>
#include <stdlib.h>
#define SIZE 5


int front=0;
int Length=0;
int* MakeEmptyQueue(int size){
	int* NewCell=(int*)malloc(sizeof(int)*size);
	
	return NewCell;
}
int isEmptyQueue(){
	return Length==0;
}

int Dequeue(int* L){
	if(isEmptyQueue()){
		return;
	}
	int tmp=L[front];
	front=(front+1)%(SIZE);
	Length--;
	return tmp;
}
void Enqueue(int x,int*L){
	if(Length==SIZE){
		return;
	}
	Length++;
	L[(front+Length-1)%(SIZE)]=x;
}
int Front(int*L){
	if(isEmptyQueue()){
		return;
	}
	return L[front];
}


int main(void){
	int* queue=MakeEmptyQueue(SIZE);
	Enqueue(5,queue);
	Enqueue(15,queue);
	Enqueue(18,queue);
	Enqueue(13,queue);
	Enqueue(26,queue);
	
	
	Enqueue(100,queue); // Max size이므로 enqueue x  
	Enqueue(100,queue); // Max size이므로 enqueue x  
	printf("%d\n",Dequeue(queue)); //5
	printf("%d\n",Dequeue(queue)); //15 
	printf("%d\n",Dequeue(queue)); //18
	printf("%d\n",Dequeue(queue)); //13
	Enqueue(100,queue); // dequeue로 사이즈가 줄었음으로 enqueue 
	printf("%d\n",Dequeue(queue)); //26
	printf("%d\n",Dequeue(queue)); //100
	free(queue);
	return 0;
}
