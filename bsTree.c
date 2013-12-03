#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Represents a Tree Node */
typedef struct _TreeNode{
	struct _TreeNode *parent;
	struct _TreeNode *left;
	struct _TreeNode *right;
	int value;
}TreeNode;

/* Represents a binary search tree */
typedef struct _BSTree{
	TreeNode *root;
	void (*add)(struct _BSTree *t,int value);
	void (*destroy)(struct _BSTree *t);
}BSTree;

// Prototypes
void BSTree_add(BSTree *t,int value);
void BSTree_destroy(BSTree *t);
void BSTree_insert(TreeNode **root,int value,TreeNode **parent);
void TreeNode_destroy(TreeNode **n);

// Creates a Binary Search Tree
BSTree *BSTree_BSTree(){
	BSTree *t = malloc(sizeof(BSTree));
	assert(t!=NULL);
	t->root = NULL;
	t->add = BSTree_add;
	t->destroy = BSTree_destroy;	
}

// Adds a value to the binary search tree
void BSTree_add(BSTree *t,int value){	
	assert(t!=NULL);	
	BSTree_insert(&(t->root),value,NULL);	
}

// Destroys the tree
void BSTree_destroy(BSTree *t){	
	if(t){
		TreeNode_destroy(&(t->root));
		free(t);		
	}
}

// Destroys a tree node and all its child nodes
void TreeNode_destroy(TreeNode **n){
	if(!(*n)) return;
	TreeNode_destroy(&((*n)->left));
	TreeNode_destroy(&((*n)->right));
	free(*n);
}

// Inserts a node to a tree starting from node n 
void  BSTree_insert(TreeNode **n,int value,TreeNode **parent){	
	if(*n==NULL){
		*n = malloc(sizeof(TreeNode));		
		assert((*n)!=NULL);
		(*n)->value = value;
		(*n)->parent = (parent!=NULL)?(*parent):NULL;
		return;
	}	
	((*n)->value >value)?BSTree_insert(&((*n)->left),value,n):BSTree_insert(&((*n)->right),value,n);
}

// Preorder traversal
void BSTree_preOrder(TreeNode **n, void (*callback)(int)){
	if((*n) == NULL) return;
	callback((*n)->value);
	BSTree_preOrder(&((*n)->left),callback);
	BSTree_preOrder(&((*n)->right),callback);
}

//Inorder traversal
void BSTree_inOrder(TreeNode **n, void (*callback)(int)){
	if((*n) == NULL) return;
	BSTree_inOrder(&((*n)->left),callback);
	callback((*n)->value);
	BSTree_inOrder(&((*n)->right),callback);
}

//Post order traversal
void BSTree_postOrder(TreeNode **n, void (*callback)(int)){
	if((*n) == NULL) return;
	BSTree_postOrder(&((*n)->left),callback);
	BSTree_postOrder(&((*n)->right),callback);
	callback((*n)->value);
}





