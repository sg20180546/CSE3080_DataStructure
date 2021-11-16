#include <stdio.h>
#define SIZE 5
int tmp[SIZE];

void mergeSort(int* arr, int left, int right) {
     
    if (left == right) return;
    int mid;
    mid = (left + right) / 2;
    mergeSort(arr, left, mid); 
    mergeSort(arr, mid + 1, right); 
    merge(arr, left, right); 
     
}

void merge(int arr[], int left, int right) {
    int L, R, k, a;
    int mid = (left + right) / 2;
    L = left;
    R = mid + 1;
    k = left;
 
    while (L <= mid && R <= right)
        tmp[k++] = arr[L] <= arr[R] ? arr[L++] : arr[R++];
 
    if (L>mid) 
        for (a = R; a <= right; a++)
            tmp[k++] = arr[a];
    else
        for (a = L; a <= mid; a++)
            tmp[k++] = arr[a];
     
    for (a = left; a <= right; a++) 
        arr[a] = tmp[a];
     
}
int main(void){
	
	
	
	
	
	return 0;
}
