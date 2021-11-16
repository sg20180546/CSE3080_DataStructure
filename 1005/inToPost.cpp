#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum{lparen,rparen, plus,minus,divide,mod,times,eos,operand
} precedence;
int top=-1;


static int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
static int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

precedence stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
void postfix();
precedence getToken(char*,int*);
void push(precedence);
precedence pop();
void stackFull();
precedence stackEmpty();
void printToken(precedence);

int main(){
//	sprintf(expr,"6*4-2");
	sprintf(expr,"6/2-((3+4)*7)*2");
	printf("infix : %s\n",expr);
	printf("postfix: ");
	postfix();
	return 0;
}

	

void postfix(){
	char symbol;
	precedence token;
	int n =0;
	top=0;
	stack[0]=eos;
	for(token=getToken(&symbol,&n); token!=eos; token=getToken(&symbol,&n)){
		// expr의 마지막은 operand이다 
		if(token==operand) printf("%c",symbol);
//		')' 를 만나면 lparen을 만날때까지 stack의 기호를 모두 빼준다 
		else if(token==rparen){
			while(stack[top]!=lparen){
//				printf("\nfirst\n");
				printToken(pop());	
			}
			// pop '(' 
			pop();
		}else{
//			not rparen,not operand
//			while operator
//			연산의 우선순위를 먼저 계산해서 뽑아낸후 
//			isp: 스택에 있는 token의 우선순위가 icp, 현재의 token 보다 클때
//			 6*4-2
//			minus를 넣으려고 봤더니, 우선순위가 더 높은 times가 있어서 times를 뽑아냈다 
			while( isp[ stack[top] ] >= icp[token] ){
//				printf("hello");
				printToken(pop());
			}
			
//			printf("\ntoken :%d \n",token);
//			token push
			push(token);
		}
	}
//	마지막 남은 opration , 왜냐하면 infix 방식에서는 마지막에 operand임 -> stack에 남은 operator을 빼야한다 
	while((token=pop())!=eos ){
		printToken(token);
	}
	printf("\n");
}

precedence getToken(char* symbol,int* n){
	*symbol=expr[(*n)++];
	switch(*symbol){
		case '(': return lparen;
		case ')': return rparen;
		case '+': return plus;
		case '-': return minus;
		case '%': return mod;
		case '*': return times;
		case '/': return divide;
		case '\0': return eos;
		default: return operand;
	}
}
void printToken(precedence token){
	switch(token){
		case lparen: printf("("); break;
		case rparen: printf(")"); break;
		case plus: printf("+"); break;
		case minus: printf("-"); break;
		case divide: printf("/"); break;
		case times: printf("*"); break;
		case mod: printf("%"); break;
	}
}

void push(precedence item){
	if(top>=MAX_STACK_SIZE) stackFull();
	stack[++top]=item;
}

precedence pop(){
	if(top==-1) return stackEmpty();
	return stack[top--];
}
void stackFull(){
	fprintf(stderr,"Stack is full");
	exit(-1);
}
precedence stackEmpty(){
	fprintf(stderr,"stack is empty");
	exit(-1);
}
