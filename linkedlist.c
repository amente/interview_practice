#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



/* Representation of a LL Node */
struct Node{
	struct Node *next;
	int value;
};


void LL_destroy(void *self);
void LL_appendBack(void *self,int value);
void LL_appendFront(void *self,int value);
int LL_remove(void *self,int value);
int LL_removeHead(void *self);

/* Representation of a LL */
typedef struct {
	struct Node *head;	
	struct Node *tail;
	int length;
	void (*destroy)(void *self);	
	void (*appendBack) (void *self,int value);
	void (*appendFront) (void *self,int value);
	int (*remove) (void *self,int value);
	int (*removeHead) (void *self);
}LL;


/* Creates a new LL */
LL *LL_LL(){    
	LL *l = malloc(sizeof(LL));	
    	assert(l!=NULL);
	l->head = NULL;
	l->tail = NULL;
	l->length =0;
	l->destroy = LL_destroy;
	l->appendBack = LL_appendBack;
	l->appendFront = LL_appendFront;
	l->remove = LL_remove;
	l->removeHead = LL_removeHead;
	return l;
}

/* Destroys a LL */
void LL_destroy(void *self){	
    LL *l = self;
	struct Node *cur = l->head;
	while(cur!=NULL){
		struct Node *next = cur->next;		
		free(cur);
		cur = next;
	}
	free(l);	
}

/* Appends a new Node to the end of the LL */
void LL_appendBack(void *self,int value){
    LL *l = self;	
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));
	assert(new!=NULL);
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

/* Appends a new Node to the front of the LL */
void LL_appendFront(void *self,int value){	
	LL *l = self;
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));
	assert(new!=NULL);
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


/* Returns the length of the LL*/
int LL_length(LL *l){	
	return l->length;	
}

/* Removes the first occurence of a value from a LL */
int LL_remove(void *self,int value){
	LL *l = self;
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

int LL_removeHead(void *self){
	// Safely assume LL_remove removes the first occurence
	LL *l = self;
	int value = l->head->value;
	LL_remove(l,value);
	return value;
}

/** OH OH.. not sure if this is plausible.. have to scroll to find middle **/
void LL_mergeSort(LL *l){
		
}

/* Merges two sorted linked lists*/
LL *LL_merge(LL *l1, LL *l2){
	// If either or both are empty return the other
	if(l1->length==0 || l2->length==0){
		return (l1->length==0)?l2:l1;
	}
	
	LL *l;	
	struct Node *cur1 = l1->head;
	struct Node *cur2 = l2->head;
	// Pick head to start with
	if(cur1->value<=cur2->value){
	    l = l1;
		cur1 = cur1->next;
	}else{
		l = l2;
		cur2 = cur2->next;
	}	
	// Set the length
	l->length = l1->length+l2->length;
	//This is the current Node of the merge	
	struct Node *cur =l->head;	
	//This picks the next Node to merge
	struct Node *next;
	while(cur1!=NULL && cur2!=NULL){
		if(cur1->value<=cur2->value){
			next = cur1;
			cur1 = cur1->next;
		}else{
			next = cur2;
			cur2 = cur2->next;
		}
				
		if(cur->next == next){
			cur = cur->next;
		}else{
			cur->next = next;
		}
		cur = cur->next;
	}
	//Connect to the unfinished node, ! beauty !
	cur->next = (cur1==NULL)?cur2:cur1;		
	return l;
}













