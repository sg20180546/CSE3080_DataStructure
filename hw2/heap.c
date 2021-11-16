#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_HEAP_SIZE 1000000
#define IS_FULL(x) !x
#define HEAP_EMPTY(n) (!n)
#define HEAP_FULL(n) (n==MAX_HEAP_SIZE-1)

int max_state=0,min_state=0;
int max_heap0[MAX_HEAP_SIZE];
int max_heap1[MAX_HEAP_SIZE];
int min_heap[MAX_HEAP_SIZE];
int max_n=0;
int min_n=0;

void insert_max_heap(int);
void insert_min_heap(int);
int delete_max_heap();
int delete_min_heap();
int main(int argc,char **argv){
    FILE* fp=fopen(argv[1],"r");
    char operator[10];
    int operand,n;
    if(fp==NULL){
        printf("input file does not exists.\n");
        return 0;
    }


    // if(IS_FULL(*heap)){
    //     fprintf(stderr,"memory full\n");
    //     exit(1);
    // }
    
    while(!feof(fp)){
        fscanf(fp,"%s",operator);
        if(!strcmp(operator,"DESCEND")){
            int* max_heap;
            if(max_state==0){
                memcpy(max_heap1,max_heap0,sizeof(int)*max_n)
            }else{
                memcpy(max_heap0,max_heap1,sizeof(int)*max_n)
            }
            // max heap
            // before delete, duplicate all data;
            while(){
                // delete
            }
            if(max_state==0){
                max_state=1
            }else{
                max_state=0
            }
            printf("%s\n",operator);
            
        }else if(!strcmp(operator,"ASCEND")){
            // min heap
            // printf("%s\n",operator);
        }else{
            fscanf(fp,"%d",&operand);
            // printf("%d\n",operand);
            insert_max_heap(operand);
        }
        
    }
    
    return 0;
}

void insert_max_heap(int key){
    int i;
    int* max_heap;
    if(max_state==0){
        max_heap=max_heap0;
    }else{
        max_heap=max_heap1;
    }
    
    if(HEAP_FULL(max_n)){
        fprintf(stderr,"max heap is full\n");
        exit(1);
    }
    i=++(max_n);
    while(i!=1&&(key>max_heap[i/2])){
        max_heap[i]=max_heap[i/2];
        i/=2;
    }
    max_heap[i]=key;
}

int delete_max_heap(){
    int* max_heap;
    if(max_state==0){
        max_heap=max_heap0;
    }else{
        max_heap=max_heap1;
    }

    int parent,child;
    int item,temp;
    if(HEAP_EMPTY(max_n)){
        fprintf(stderr,"max heap empty\n");
        exit(1);
    }
    item=max_heap[1];
    temp=max_heap[max_n--];
    parent=1;
    child=2;
    while(child<=max_n){
        if(child<max_n&&max_heap[child]<max_heap[child+1]) child++;
        if(temp>=heap[child]) break;
        max_heap[parent]=max_heap[child];
        parent=child;
        child*=2;
    }
    max_heap[parent]=temp;
    return item;
}

// max heap을 2개 두고 0 or 1의 state를 만들자.