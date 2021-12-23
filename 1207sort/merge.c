#include <stdlib.h>
#include <stdio.h>

//int d=0;
//int buffer[100];
void merge_sort(int*a,int left,int right){
	int middle=(left+right)/2;
	if(left<right){
 
		merge_sort(a,left,middle);  // 0~3까지 정렬 수행 
		merge_sort(a,middle+1,right); //4~7까지 정렬 수행 

		merge(a,left,middle,right); // 정렬된 0~3, 정렬된 4~7을 합치며 정렬 수행 
	}
}

void merge(int*a,int left,int middle,int right){
	int i,i_left,i_right;
	int * buffer=malloc(sizeof(int)*(right-left+1));
	memcpy(buffer+left,a+left,sizeof(int)*(right-left+1));
	i=left;
	printf("left : %d\n",i);
	i_left=left;
	i_right=middle+1;
	while((i_left<=middle)&&(i_right<=right)){
		if(buffer[i_left]<buffer[i_right]){
			a[i++]=buffer[i_left++];
		}else{
			a[i++]=buffer[i_right++];
		}
	}
	while(i_left<=middle) a[i++]=buffer[i_left++];
	while(i_right<=right) a[i++]=buffer[i_right++];
	free(buffer);
}

void main(){
	int a[]={433,1,55,44,3,77,567,103};
	size_t n=sizeof(a)/4;
	int i;
	merge_sort(a,0,n-1);
	for(i=0;i<n;i++) printf("%3d ",a[i]);
	
}
