#include <stdio.h>
#include <stdlib.h>
#define IS_FULL(x) !x
struct node{
	char data;
	struct node* left_child,*right_child;
};

typedef struct node* tree_pointer;


tree_pointer create_tree_node(char);
void recursive_inorder(tree_pointer);
void iter_inorder(tree_pointer ptr);
tree_pointer copy(tree_pointer);
int equal(tree_pointer,tree_pointer);

int main(void){
	tree_pointer ptr,ptr1,ptr2,dest;
	
	ptr1=create_tree_node('A');
	ptr2=create_tree_node('B');
	ptr=create_tree_node('/');
	ptr->left_child=ptr1;
	ptr->right_child=ptr2;
	
	ptr1=ptr;
	ptr2=create_tree_node('C');
	ptr=create_tree_node('*');
	ptr->left_child=ptr1;
	ptr->right_child=ptr2;
	
	ptr1=ptr;
	ptr2=create_tree_node('D');
	ptr=create_tree_node('*');
	ptr->left_child=ptr1;
	ptr->right_child=ptr2;
	
	ptr1=ptr;
	ptr2=create_tree_node('E');
	ptr=create_tree_node('+');
	ptr->left_child=ptr1;
	ptr->right_child=ptr2;
	
	recursive_inorder(ptr);
	dest=copy(ptr);
	
	printf("\nequal : %d\n ",equal(ptr,dest));
	return 0;
}

tree_pointer create_tree_node(char data){
	tree_pointer ptr=malloc(sizeof(struct node));
	ptr->data=data;
	ptr->right_child=NULL;
	ptr->left_child=NULL;
	return ptr;
}

void recursive_inorder(tree_pointer ptr){
	if(ptr){
		recursive_inorder(ptr->left_child);
		printf("%c ",ptr->data);
		recursive_inorder(ptr->right_child);
	}
}
void iter_inorder(tree_pointer ptr){
	
	
}

tree_pointer copy(tree_pointer original){
	tree_pointer temp;
	if(original){
		temp=(tree_pointer)malloc(sizeof(struct node));
		if(IS_FULL(temp)){
			fprintf(stderr,"memory full\n");
			exit(1);
		}
		temp->left_child=copy(original->left_child);
		temp->right_child=copy(original->right_child);
		temp->data=original->data;
		return temp;
	}
	return NULL;
}

int equal(tree_pointer first,tree_pointer second ){
	return( (!first&&!second) || (first&&second&&
	(first->data==second->data) &&
	equal(first->left_child,second->left_child) &&
	equal(first->right_child,second->right_child) )
	);
}
