#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 100
#define MAX_PATTERN_SIZE 100

int nfind(char*,char*);
int pmatch(char*,char*);

int pmatch(char*, char*);
void fail(char*);

int failure[MAX_PATTERN_SIZE];
char string[MAX_STRING_SIZE];
char pat[MAX_PATTERN_SIZE];

void main(){
//	char c[]="aaaaaaaabaa";
//	char p[]="aba";
//	
//	int index=nfind(c,p);
//	printf("index: %d\n",index);
	
	
	
	int rv, i;
	strcpy(string, "ABABABBBBAABAABAABABAAABAdd");
//	strcpy(pat, "ABAABABAAABA");
strcpy(pat, "aaaaaaaaaaa");
  	fail(pat);
  	for(i=0; i<strlen(pat); i++) {
    printf("%d ", failure[i]);
  	}
  	printf("\n"); 
  	rv = pmatch(string, pat);
  	printf("rv: %d\n", rv);
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
int pmatch(char* string,char* pat){
	int i=0,j=0,k=0;
	int lens=strlen(string);
	int lenp=strlen(pat);
	printf("string length: %d pat length: %d\n",lens,lenp);
	while(i<lens&&j<lenp)
	{	
	k++;
		if(string[i]==pat[j]){ i++; j++;
		 printf("same : i(%d) j(%d)\n",i,j);
		}
		else if(j==0){
			i++;
//			k--;
			printf("differ at j=0\n");	
		} 
		else{
			j = failure[j-1]+1;
			printf("differ i(%d) j(%d)\n\n",i,j);	
		} 
//		printf("%d ",i);
	}
	printf("last k: %d\n",k);
	return ( (j==lenp) ? (i-lenp) : -1 );
}
void fail(char* pat){
	int i,j,n=strlen(pat);
	failure[0]=-1;	
	for(j=1;j<n;j++){		
		i=failure[j-1];
		
		while( (pat[j]!=pat[i+1]) && (i>=0) ){
			i=failure[i]; //init i=-1 because fisrt pattern always -1

		}	
		if(pat[j]==pat[i+1]) failure[j]=i+1;		
		else failure[j]=-1;
	}
}
