#include <stdio.h>
#define INF 99999999
#define MAX_VERTICES 10000
#define TRUE 1
#define FALSE 0

int numVertices;
int cost[MAX_VERTICES][MAX_VERTICES];
int distance[MAX_VERTICES][MAX_VERTICES];

void createGraph() {

    int i, j;

    numVertices = 4;

    for(i=0; i<numVertices; i++) {
        for(j=0; j<numVertices; j++) {
            if(i==j) cost[i][j] = 0;
            else cost[i][j] = INF;
        }
    }

    cost[0][1] = 3;
    cost[0][3] = 7;
    cost[1][0] = 8;
    cost[1][2] = 2;
    cost[2][0] = 5;
    cost[2][3] = 1;
    cost[3][0] = 2;
}


void floydWarshall(){
	int i,j,k;
	
	for(i=0;i<numVertices;i++){
		for(j=0;j<numVertices;j++){
			distance[i][j]=cost[i][j];
		}
	}
	
	for(i=0;i<numVertices;i++){
		for(j=0;j<numVertices;j++){
			for(k=0;k<numVertices;k++){
				if(j==k) continue;
				if(distance[j][k]>distance[j][i]+cost[i][k]){
					distance[j][k]=distance[j][i]+cost[i][k];
				}
			}
		}
	printf("A%d\n", i);
    printf("      0  1  2  3\n");
    
    
    for(j=0;j<numVertices;j++){
    	printf("[%2d] ",j);
    	for(k=0;k<numVertices;k++){
    		if(distance[j][k]==INF) printf(" - ");
    		else printf("%3d",distance[j][k]);
		}
		printf("\n");
	}
	printf("\n");
	}
	

	
}

void main(){
	createGraph();
	floydWarshall();
}
