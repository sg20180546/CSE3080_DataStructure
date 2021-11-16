#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct _ArrayGraph{
	int maxVertexCnt;
	int curVertexCnt;
	int graphType;
	int** ppAdjEdge;
	int* pVertex;
} ArrayGraph;

ArrayGraph* createAG(int max);
ArrayGraph* createADG(int max);
void deleteAG(ArrayGraph* pGraph);
int isEmpty(ArrayGraph* pGraph);
int addVertexAG(ArrayGraph* pGraph, int newVertex);
int addEdgeAG(ArrayGraph* pGraph,int fromVertex, int toVertex);
int addEdgeWeightAG(ArrayGraph* pGraph, int fromVertex, int toVertex,int weight);

int removeVertexAG(ArrayGraph* pGraph, int Vertex);
int removeEdgeAG(ArrayGraph* pGraph,int fromVertex, int toVertex);
void displayAG(ArrayGraph* pGraph);

#define USED 1
#define NOT_USED 0
#define SUCCESS 1
#define FAIL 0

#define GRAPH_UNDIRECTED 1
#define GRAPH_DIRECTED 2


