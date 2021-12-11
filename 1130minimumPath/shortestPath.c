#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICIES 100
#define INF 999999
#define TRUE 1
#define FALSE 0

int numVerticies;
int numEdges;
int cost[MAX_VERTICIES][MAX_VERTICIES];

int v;
int distance[MAX_VERTICIES];
// parent : 0으로 가기위해 ,최소cost로 거쳐가야할 node 
int parent[MAX_VERTICIES];
int path[MAX_VERTICIES];
int found[MAX_VERTICIES];

void createGraph();
int choose();
void shortestPath();

int main(){
	int i,j;
	int path_curr,path_count;
	
	createGraph();
	for(i=0;i<numVerticies;i++){
		distance[i]=INF;
		parent[i]=-1;
	}
	v=0;
	shortestPath();
	
	for(i=0;i<numVerticies;i++){
		
		if(distance[i]!=INF){
			printf("SRC : %d DST : %d LENGTH : %3d PATH: %d",v,i,distance[i],v);
			path_curr=i;
			path_count=0;
			
			
			while(parent[path_curr]>-1){
				path[path_count]=path_curr;
				path_count++;
				path_curr= parent[path_curr];
			}
//			반대로 출력 
			for(j=path_count-1;j>=0;j--){
				printf(" %d",path[j]);
			}
			
			printf("\n");
		}else{
			printf("SRC %d DST : %d LENGTH -- PATH -\n",v,i);
		}
	}
	for(i=0;i<numVerticies;i++){
		printf("%5d ",parent[i]);
	}
	
	return 0;
}
void createGraph(){
	int i,j;
	numVerticies=6;
	numEdges=11;
	for(i=0;i<numVerticies;i++){
		for(j=0;j<numVerticies;j++){
			cost[i][j]=INF;
		}
	}
	cost[0][1] = 50;
    cost[0][2] = 45;
    cost[0][3] = 10;
    cost[1][3] = 15;
    cost[1][2] = 10;
    cost[2][4] = 30;
    cost[3][0] = 20;
    cost[3][4] = 15;
    cost[4][1] = 20;
    cost[4][2] = 35;
    cost[5][4] = 3;
}

void shortestPath(){
	int i ,u,w,m;
//	0과 붙어있는 node 들 cost를 distance로 설정 
	for(i=0;i<numVerticies;i++){
		found[i]=FALSE;
		distance[i]=cost[v][i];
		if(distance[i]<INF){
			parent[i]=v;
		}
	}
	found[v]=TRUE;
	distance[v]=0;
//	printf("distance :");
//	for(m=0;m<numVerticies;m++){
//			printf("%7d ",distance[m]);
//	}printf("\n\n");
	for(i=0;i<numVerticies-2;i++){
		u=choose();
		printf("u : %3d\n",u);

		if(u==-1) break;
		found[u]=TRUE;
		for(w=0;w<numVerticies;w++){
			if(!found[w]&&(u!=w)){
				if(distance[u]+cost[u][w]<distance[w]){
					distance[w]=distance[u]+cost[u][w];
					parent[w]=u;
				}
			}
		}
		printf("distance :");
		for(m=0;m<numVerticies;m++){
			printf("%7d ",distance[m]);
		}printf("\n\n");
	}
}

int choose(){
	int i,min,minpos;
	min=INF;
	minpos=-1;
	 
	for(i=0;i<numVerticies;i++){
		printf("min :%6d , distance[%d]:%d\n",min,i,distance[i]);
		if(distance[i]<min && !found[i]){
			printf("->min :%6d = distance[%d]:%d\n",min,i,distance[i]);
			min=distance[i];
			minpos=i;
		}
	}
	return minpos;
}
