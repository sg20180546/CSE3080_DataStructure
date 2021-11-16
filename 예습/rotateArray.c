#include <stdio.h>
 

  
/* Function to left rotate arr[] of size n by d */
void leftRotate(int arr[], int d, int n)
{
  
    if (d == 0)
        return;
    // in case the rotating factor is
    // greater than array length
    d = d % n;
  	// 1 2 3 4 5 6 7
    reverseArray(arr, 0, d - 1); // 2 1 3 4 5 6 7
    reverseArray(arr, d, n - 1); // 2 1 7 6 5 4 3
    reverseArray(arr, 0, n - 1); // 3 4 5 6 7 1 2
}
  

/*Function to reverse arr[] from index start to end*/
void reverseArray(int arr[], int start, int end)
{
    int temp;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
 
 
 
 
 int main(void){
 	int T,N,D,i,j;
 	scanf("%d",&T);
 	for(i=0;i<T;i++){
 		scanf("%d %d",&N,&D);
 		int arr[N];
 		for(j=0;j<N;j++){
 			scanf("%d",&arr[j]);
		}
		leftRotate(arr,D,N);
		for(j=0;j<N;j++){
 			printf("%d ",arr[j]);
		} 
 		printf("\n");
	 }
 	
 	
 	return 0;
 }
