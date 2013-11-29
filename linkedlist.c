#include <stdio.h>
#include <stdlib.h>

/* Representation of a LinkedList Node */
struct Node{
	struct Node *next;
	int value;
};

/* Representation of a LinkedList */
typedef struct {
	struct Node *head;	
	struct Node *tail;
	int length;
}LinkedList;


/* Creates a new LinkedList */
LinkedList *LL_linkedList(){    
	LinkedList *l = malloc(sizeof(LinkedList));	
    if(!l){exit(0);} //ERROR
	l->head = NULL;
	l->tail = NULL;
	l->length =0;
	return l;
}

/* Destroys a LinkedList */
void LL_destroy(LinkedList *l){	
	struct Node *cur = l->head;
	while(cur!=NULL){
		struct Node *next = cur->next;		
		free(cur);
		cur = next;
	}
	free(l);	
}

/* Appends a new Node to the end of the LinkedList */
void LL_appendBack(LinkedList *l,int value){	
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));
	if(!new){exit(0);} //ERROR
	new->next = NULL;
	new->value = value;	
	if(l->length==0){
		//Empty, head is also new
		l->head = new;		
	}else{
		l->tail->next = new;		
	}
	l->tail = new;	
	l->length++;	
}

/* Appends a new Node to the front of the LinkedList */
void LL_appendFront(LinkedList *l,int value){	
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));
	if(!new){exit(0);} //ERROR
	new->next = NULL;
	new->value = value;	
	if(l->length==0){	
		//Empty tail is also new
		l->tail = new;
	}else{
		new->next = l->head->next;		
	}
	l->head = new;
	l->length++;
}


/* Returns the length of the LinkedList*/
int LL_length(LinkedList *l){	
	return l->length;	
}

/* Removes the first occurence of a value from a LinkedList */
int LL_remove(LinkedList *l,int value){
	struct Node *cur = l->head;
	struct Node *prev = NULL;
	while(cur!=NULL){	
		if(cur->value==value){
			if(l->head==cur){
				//Removing head
				l->head=cur->next;				
			}else if(l->tail==cur){
				//Removing tailoh 				
				l->tail=prev;	
				prev->next = NULL;				
			}else{
				//Removing normal Node
				prev->next = cur->next;						
			}
			l->length--;
			free(cur);
			return 1;
		}else{
			prev = cur;
			cur = cur->next;
		}		
	}
	return 0;
}














