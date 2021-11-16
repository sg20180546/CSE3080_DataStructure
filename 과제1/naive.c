#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count=0;
char* pat;
int patLength;
char* str;
int strLength;
int* answer;
void naive();
int main(void){
	int i; int ch;
	FILE* pat_txt=fopen("pattern.txt","r");
	FILE* str_txt=fopen("string.txt","r");
	FILE* res_txt=fopen("result_naive.txt","w");
	if(pat_txt==NULL||str_txt==NULL){
		char notfound[]="The string file does not exists";
		fwrite(notfound,sizeof(char),strlen(notfound),res_txt);
//		fclose(str_txt);fclose(pat_txt);fclose(res_txt);
		return 0;
	} 
	
	fseek(pat_txt,0,SEEK_END);
//	if window
	patLength=ftell(pat_txt);
//	if gcc
//	patLength=ftell(pat_txt)-1;
	printf("%d\n",patLength);
	fseek(pat_txt,0,SEEK_SET);
	pat=malloc(sizeof(char)*patLength);
	answer=malloc(sizeof(int)*patLength);
	for(i=0;i<patLength;i++){
		pat[i]=fgetc(pat_txt);
	}
	
	fseek(str_txt,0,SEEK_END);
	strLength=ftell(str_txt);
	fseek(str_txt,0,SEEK_SET);
	str=malloc(sizeof(char)*strLength);
	for(i=0;i<strLength;i++) str[i]=fgetc(str_txt);
	
	fclose(str_txt);fclose(pat_txt);
	naive();
	
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
	return 0;
}
void naive(){
	int patLength=strlen(pat);
	int strLength=strlen(str);
	int i,j;
	for(i=0;i<strLength;i++){
		int cur=i;
		for(j=0;j<patLength;j++){
			if(pat[j]!=str[cur]) break;
			else{
//				printf("%d ",cur,j);
				cur++;
			} 
			if((cur-i) == patLength){
				answer[count++]=i;
				break;
			}
		}
	}
}
