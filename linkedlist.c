#include <stdio.h>
#include <stdlib.h>

/* Representation of a LinkedList Node */
struct Node{
	struct Node * next;
	int value;
};

/* Representation of a LinkedList */
typedef struct {
	struct Node * head;	
}LinkedList;




/* Creates a new LinkedList */
LinkedList * linkedList(){    
	LinkedList * l = malloc(sizeof(LinkedList));	
	l->head = NULL;
	return l;
}

/* Destroys a LinkedList */
void destroy(LinkedList *l){
	struct Node * cur = l->head;
	while(cur!=NULL){
		struct Node * next = cur->next;
		free(cur);
		cur = next;
	}
	free(l);
}

/* Appends a new Node to the end of the LinkedList */
void add(LinkedList * l,int value){ 
	struct Node * cur = l->head;
	if(cur==NULL){
	  l->head = (struct Node *)malloc(sizeof(struct Node));
	  l->head->value = value;
	}else{	
		while(cur->next!=NULL){
			cur = cur->next;
		}
		struct Node * new = (struct Node *)malloc(sizeof(struct Node));
		new->next = NULL;
		new->value = value;	
		cur->next = new;
	}	
}



