#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void strnins(char* ,char* ,int );
int nfind(char*,char*);

void main(){
	char a1[]="amobile";
	char a2[]="uto";
	strnins(a1,a2,1);
	printf("%s\n",a1);
}

void strnins(char* s,char*t,int i){
	char string[MAX_SIZE], *temp=string;
	
	if(i<0&& i>strlen(s)){
	fprintf(stderr,"position is out ouf bounds.\n"); 
	exit(1);	
	}
	
	if(!strlen(s)) strcpy(s,t); //s 가 빈 문자열일때 
	else if(strlen(t)){
		strncpy(temp,s,i);
		strcat(temp,t);
		strcat(temp,(s+i));
		strcpy(s,temp);
	}

}

int nfind(char* string,char* pat){
	int i,j,start=0;
	int lasts=strlen(string)-1;
	int lastp=strlen(pat)-1;
	int endmatch=lastp;
	
	for(i=0;endmatch<=lasts;endmatch++,start++){
		
		if(string[endmatch]==pat[lastp]){
			for(j=0,i=start;j<lastp && string[i]==pat[j];i++,j++);
			if(j==lastp) return start;
		}
	}
	return -1;
}

