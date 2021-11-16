#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 100
#define HEAP_FULL(n) (n==MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)


typedef struct{
	int key;
}element;

element heap[MAX_ELEMENTS];
int n=0;
// 저장할 원소 key 모음 
int randnum[]={42,68,35,1,70,25,79,59,63,65};

void insert_max_heap(element,int*);
element delete_max_heap(int*);

int main(void){
	int i,rn;
	element item;
	printf("INSETING: ");
	for(i=0;i<10;i++){
		rn=rand()%100+1;
		printf("%3d ",randnum[i]);
		item.key=rn;
		insert_max_heap(item,&n);
	}
	printf("\n\n");
	for(i=1;i<11;i++){
		printf("%3d ",heap[i]);
	}
	
	printf("\n\nDeleting: ");
	for(i=0;i<10;i++){
		item=delete_max_heap(&n);
		printf("%3d ",item.key);
	}

//	printf("\n\n");
//	for(i=1;i<10;i++){
//		printf("%3d ",heap[i]);
//	}
	return 0;
}

void insert_max_heap(element item,int* n){
	int i;
	if(HEAP_FULL(*n)){
		fprintf(stderr,"heap is full\n");
		exit(1);
	}
	i=++(*n);
	while(i!=1 && (item.key>heap[i/2].key)){
		heap[i]=heap[i/2];
		i/=2;
	}
	heap[i]=item;
}
element delete_max_heap(int *n){
	int parent,child;
	element item,temp;
	if(HEAP_EMPTY(*n)){
		fprintf(stderr,"heap is empty\n");
		exit(1);
	}
	item=heap[1];
	temp=heap[(*n)--];
	parent=1;
	child=2;
	while(child<=*n){
//		오른쪽 자식이 있고 더 크면 오른쪽 자식으로 
// 		등호가 빠진 이유 : =가 있으면, 오른쪽 자식이 없어도 성립  
		if((child<*n)&& (heap[child].key < heap[child+1].key)) child++;
//		temp key가 child보다 크면 max tree이므로 break 
		if(temp.key>=heap[child].key) break;
		
		heap[parent]=heap[child];
		parent=child;
		child*=2;
	}
	heap[parent]=temp;
	return item;
}
