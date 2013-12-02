#include <stdio.h>
#include <stdlib.h>
#include "bsTree.c"


void printInt(int n){
	printf("%d\n",n);
};

int main(void){
	
	srand(100);
	
	BSTree * t=  BSTree_BSTree();
	int i;
	int num;
	printf("Populating Tree \n");
	for(i=0;i<10;i++){
		num = rand()%10+1;		
		t->add(t,num);	
		printf("Added: %d \n",num);
	}

	//printf("Root is: \n",t->root->value);
	
	printf("Pre Order Traversal \n");
	BSTree_preOrder(&(t->root),&printInt);
	
	printf("In Order Traversal \n");
	BSTree_inOrder(&(t->root),&printInt);
		
	printf("Post Order Traversal \n");
	BSTree_postOrder(&(t->root),&printInt);
	
	return 0;
}