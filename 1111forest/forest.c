#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 100
int parent[MAX_SIZE];

int simpleFind(int i){
	for(;parent[i]>=0;i=parent[i]){
		
	}
	
	return i;
}

int collapsingFind(int i){
	int root,trail,lead;
	for(root=i;parent[root]>=0;root=parent[root]){
		
	}
	for(trail=i;trail!=root;trail=lead){
		lead=parent[trail];
		parent[trail]=root;
	}
	return root;
}

void weightedUnion(int i,int j){
	int temp=parent[i]+parent[j];
	
	if(parent[i]>parent[j]){
		parent[i]=parent[j];
		parent[j]=temp;
	}else{
		parent[j]=parent[i];
		parent[i]=temp;
	}
}

int main(void){
	int i,j,n,found;
	printf("Enter number of items (num<%d)",MAX_SIZE);
	scanf("%d",&n);
	
	for(i=0;i<n;i++) parent[i]=-1;
	printf("enter a pair of equvalent items(-1 -1 to quit)");
	scanf("%d%d",&i,&j);
	
	weightedUnion(i,j);
	
	while(i>=0){
		printf("enter a pair of equvalent items(-1 -1 to quit)");
		scanf("%d%d",&i,&j);
		weightedUnion(simpleFind(i),simpleFind(j));
	}
	
	for(i=0;i<n;i++){
		found=0;
		for(j=0;j<n;j++){
			if(simpleFind(j)==i){
				printf("%d ",j);
				found=1;
			}
		}
		if(found) printf("\n");
	}
	
	return 0;
}
