//============================================================================//
// ex011: sparse representation of a matrix                                   //
//============================================================================//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time.h>

#define MAX_TERMS 101

#define MAX_COLS 10


typedef struct {
  int row;
  int col;
  int value;
} term;

void printMatrix(term*);
void transpose(term*, term*);
void fast_transpose(term*, term*);
void main() {
    clock_t start_time, end_time;
  term a[MAX_TERMS], b[MAX_TERMS];
  
  a[0].row = 6; a[0].col = 6; a[0].value = 8;  // # of rows, # or cols, # of terms
  a[1].row = 0; a[1].col = 0; a[1].value = 15;
  a[2].row = 0; a[2].col = 3; a[2].value = 22;
  a[3].row = 0; a[3].col = 5; a[3].value = 15;
  a[4].row = 1; a[4].col = 1; a[4].value = 11;
  a[5].row = 1; a[5].col = 2; a[5].value = 3;
  a[6].row = 2; a[6].col = 3; a[6].value = 6;
  a[7].row = 4; a[7].col = 0; a[7].value = 91;
  a[8].row = 5; a[8].col = 2; a[8].value = 28;

  b[0].row = 0; b[0].col = 0; b[0].value = 0;
start_time=clock();
  printMatrix(a);
//  transpose(a, b);
  fast_transpose(a,b);
  printMatrix(b);
  end_time=clock();
  
  printf("time elapsed: %.3f seconds\n", (double)(end_time-start_time)/CLOCKS_PER_SEC);
}

void printMatrix(term *m) {
  int iter = 1, i, j;
  int rows = m[0].row;
  int cols = m[0].col;
  int num_terms = m[0].value;

  for(i=0; i<rows; i++) {
    for(j=0; j<cols; j++) {
      if(iter <= num_terms && m[iter].row == i && m[iter].col == j) {
        printf("%3d ", m[iter].value);
        iter++;
      } else {
        printf("%3d ", 0);
      }
    }
    printf("\n");
  } 
  printf("\n");

}

void transpose(term *a, term *b) {

	int n,i,j,currentb;
	n=a[0].value;
	b[0].row=a[0].col;
	b[0].col=a[0].row;
	b[0].value=n;
	
	if(n>0){
		currentb=1;
		for(i=0; i<a[0].col; i++){ //a[0].col === b의 행 갯수  
			for(j=1;j<=n;j++) 
			
			if(a[j].col==i){ //a 모든 원소를 검사하는데 해당 원소의 열이 i일때, i는 b의 행(전치됨으로 행과 열이 변경) 
				b[currentb].row=a[j].col;
				b[currentb].col=a[j].row;
				b[currentb].value=a[j].value;
				currentb++;
			}
		}
	}
}

void fast_transpose(term *a, term *b) {
	int row_terms[MAX_COLS],starting_pos[MAX_COLS];
	
	int i,j;
	int num_cols=a[0].col;
	int num_terms=a[0].value;
	
	b[0].row=num_cols; 
	b[0].col=a[0].row;
	b[0].value=num_terms;
	
	if(num_terms>0){
//		make row terms
		for(i=0;i<num_cols;i++) row_terms[i]=0;
		for(i=1;i<=num_terms;i++) row_terms[ a[i].col ]++; 
//		make start pos
		starting_pos[0]=1;
		for(i=1;i<num_cols;i++) starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
// start
		for(i=1;i<=num_terms;i++){
			printf("\nj: %d , b[j].row: %d\n",j,b[j].row);
			printf("b[j].col : %d\n",b[j].col);
			printf("b[j].value : %d\n",b[j].value);
			j=starting_pos[ a[i].col ]++;
			b[j].row=a[i].col;
			b[j].col=a[i].row;
			b[j].value=a[i].value;
//			if(j==8&&){
//				printf("\n when 91 starting_pos : "); 
//				for(i=0;i<num_cols;i++){
//						printf("%d ",starting_pos[i]);
//				} 
//			}
		}
	}
	printf("complete starting_pos : "); 
	for(i=0;i<num_cols;i++){
		printf("%d ",starting_pos[i]);
	} 
	printf("\n\n");
	}

