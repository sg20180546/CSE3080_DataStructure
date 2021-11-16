#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef enum { not ,and ,or ,T, F
} logical;

struct node{
	struct node* left_child;
	logical data;
	short int value;
	struct node* right_child;
};
typedef struct node* tree_pointer;
void post_order_eval(tree_pointer node);

int main(void){
	
	return 0;
}

void post_order_eval(tree_pointer node){
	if(node){
		post_order_eval(node->left_child);
		post_order_eval(node->right_child);
		switch(node->data){
			case not:
				node->value= !node->right_child->value;
				break;
			case and:
				node->value= node->right_child->value && node->left_child->value;
				break;
			case or:
				node->value= node->right_child->value || node->left_child->value;
				break;
			case T:
				node->value=TRUE;
				break;
			case F:
				node->value=FALSE;
				break;
		}
	}
}
