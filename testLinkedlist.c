#include <stdio.h>
#include "linkedlist.c"



void main(void){    
	LinkedList *l=linkedList();	
    add(l,10);
	add(l,20);
	printf("%d\n",l->head->value);
	printf("%d\n",l->head->next->value);
	free(l);
}