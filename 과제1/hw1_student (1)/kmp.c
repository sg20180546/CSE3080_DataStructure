#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count=0;
char* pat;
int patLength;
char* str;
int strLength;
int* answer;
int* T;
void kmp();
void makeT();


int main(void){
	int i; int ch;
	FILE* pat_txt=fopen("pattern.txt","r");
	FILE* str_txt=fopen("string.txt","r");
	if(pat_txt==NULL||str_txt==NULL){
		char notfound[]="The string file does not exists";
//		fwrite(notfound,sizeof(char),strlen(notfound),res_txt);
		printf("string file not found\n");
		return 0;
	} 
	FILE* res_txt=fopen("result_kmp.txt","w");	
	fseek(pat_txt,0,SEEK_END);
	patLength=ftell(pat_txt)-1;
	fseek(pat_txt,0,SEEK_SET);
	pat=malloc(sizeof(char)*patLength);
	answer=malloc(sizeof(int)*patLength);
	T=malloc(sizeof(int)*patLength);
	for(i=0;i<patLength;i++){
		pat[i]=fgetc(pat_txt);
	}
	
	fseek(str_txt,0,SEEK_END);
	strLength=ftell(str_txt)-1;
	fseek(str_txt,0,SEEK_SET);
	str=malloc(sizeof(char)*strLength);
	for(i=0;i<strLength;i++) str[i]=fgetc(str_txt);
	
	fclose(str_txt);fclose(pat_txt);
	makeT();
	kmp();
	
	if(count==0){
		fprintf(res_txt,"no pattern in string");
		fclose(res_txt);
		return 0;
	}
	
	
	fprintf(res_txt,"%d\n",count);
	for(i=0;i<count;i++){
		fprintf(res_txt,"%d ",answer[i]);
	}
	fclose(res_txt);
	printf("Program complete. Result saved to result_kmp.txt\n");
	return 0;
}

void makeT(){
	int i,j;
	int patLength=strlen(pat);
	T[0]=-1;
	for(j=1;j<patLength;j++){
		i=T[j-1];
		while((pat[j]!=pat[i+1]) && (i>=0)  ){
			i=T[i];
		}
		if(pat[j]==pat[i+1]) T[j]=i+1;
		else T[j]=-1;
	}
}

void kmp(){
	int patLength=strlen(pat);
	int strLength=strlen(str);
	int i=0,j=0;
	int cur=i;
	while(i<strLength){
		if(str[i]==pat[j]){
			i++;j++;
			if(j==patLength){
				answer[count++]=i-patLength;
				i=i-patLength+1;
				j=0;
			}
		}else if(j==0){
			i++;
		}else{
			j=T[j-1]+1;
		}
	}
}
