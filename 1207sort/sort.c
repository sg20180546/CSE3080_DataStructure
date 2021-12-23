#include <stdio.h>
#include <stdlib.h>
#define swap(a,b) {int tmp; tmp=a; a=b; b=tmp; }


//int buffer[1000];
void insert_sort(int* a,int n){
	int i,j,tmp;
	for(i=1;i<n;i++){
		tmp=a[i];
		j=i;
		while((j>0)&&(tmp<a[j-1])){
			a[j]=a[j-1];
			j--;
		}
		a[j]=tmp;
	}
}

void select_sort(int *a,int n){
	int i,j,cur;
	for(i=0;i<n-1;i++){
		cur=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[cur]){
				cur=j;
			}
		}
		
		swap(a[i],a[cur]);
	}
}

void merge_sort(int * a,int left,int right){
	int middle;
	if(left<right){
		middle=(left+right)/2;
		merge_sort(a,left,middle);
		merge_sort(a,middle+1,right);
		
		merge(a,left,middle,right);
	}
}

void merge(int*a,int left, int middle,int right){
	int i, i_left,i_right;
	int * buffer=malloc(sizeof(int)*(right-left+1));
	
	memcpy(buffer+left,a+left,sizeof(int)*(right-left+1));
	i_left=left;
	i_right=middle+1;
//	int middle=(i_right/2);
	i=left;
	while((i_left<=middle)&&(i_right<=right)){
		if(buffer[i_left]<buffer[i_right]) a[i++]=buffer[i_left++];
		else a[i++]=buffer[i_right++];
	}
	while(i_left<=middle) a[i++]=buffer[i_left++];
	while(i_right<=right) a[i++]=buffer[i_right++];
	free(buffer); 
}

void bubble_sort(int* a,int n){
	int i, j;
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
			}
		}
	}
}

void quick_sort(int* a,int left,int right)
{
	int pivot;
	if(right-left>0){
		pivot=partition(a,left,right);
		quick_sort(a,left,pivot-1);
		quick_sort(a,pivot+1,right);
	}
}

int partition(int* a,int left, int right){
	int i,t, pivot;
	pivot=left;
	for(i=left;i<right;i++){
		
		if(a[i]<a[right]){
			printf("if(%d<%d) pivot == %d, i==%d\n",a[i],a[right],pivot,i);
			swap(a[i],a[pivot]);
			pivot++;
			
		}
		
		for(t=0;t<right+1;t++){
			printf("%3d ",a[t],pivot);	
		}
		printf("\n");
	}
	
	swap(a[right],a[pivot]);
	return pivot;
}

//void heapsort(int* a,int n){
//	int i,j;
//	int temp;
//	for(i=n/2;i>0;i--){
//		adjust(a,i,n);
//	}
//	for(i=n-1;i>0;i--){
//		swap(a[1],a[i+1],temp);
//		adjust(a,1,i);
//	}
//}

//void adjust(int* a,int root,int n){
//	int child,rootkey;
//	int temp;
//	temp=a[root];
//	rootkey=a[root];
//}

int main(void){
	
	int a[]={8,154,47,1,69,11,234,43};
	size_t sizea=sizeof(a)/4;
	int i;
	
//	insert_sort(a,sizea);
//	select_sort(a,sizea);
	merge_sort(a,0,sizea-1);
//	quick_sort(a,0,sizea-1);
//	int d=partition(a,0,sizea-1);
//	printf("%d\n",a[d]);
	for(i=0;i<sizea;i++){
		printf("%3d ",a[i]);
	}
	
	
	return 0;
}
