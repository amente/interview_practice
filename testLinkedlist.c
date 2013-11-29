#include <stdio.h>
#include "linkedlist.c"



void main(void){    
	LinkedList *l=LL_linkedList();	
	int i;
	for(i=0;i<10;i++){
	    printf("Appending to the Back %d\n",i);
		LL_appendBack(l,i);
	}
    
	for(i=0;i<10;i++){
	    printf("Appending to the Front %d\n",i);
		LL_appendFront(l,i);
	}
	
	printf("Length: %d\n",LL_length(l));
	printf("Head: %d\n",l->head->value);
	printf("Tail: %d\n",l->tail->value);
	printf("Remove: %d\n",5);
	LL_remove(l,5);
	printf("Length: %d\n",LL_length(l));
	printf("Remove Head: %d\n",l->head->value);
	LL_remove(l,l->head->value);
	printf("Length: %d\n",LL_length(l));
	printf("Remove Tail: %d\n",l->tail->value);
	LL_remove(l,l->tail->value);
	printf("Length: %d\n",LL_length(l));
	LL_destroy(l);	
}