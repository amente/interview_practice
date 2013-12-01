#include <stdio.h>
#include "linkedlist.c"



int main(void){    
	/**
	LL *l=LL_LL();	
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
	**/
	
	//*/
	LL *l1 = LL_LL();
	LL *l2 = LL_LL();
	int i;
	printf("L1: ");
	for(i=0;i<10;i+=2){
	    printf("%d,",i);
		LL_appendBack(l1,i);
	}
	printf("\n");
	printf("L2: ");
	for(i=1;i<20;i+=2){
	    printf("%d,",i);
		LL_appendBack(l2,i);
	}
	printf("\n");	
	LL * l = LL_merge(l1,l2);
	printf("L: ");
	struct Node *cur = l->head;
	while(cur!=NULL){
	    printf("%d,",cur->value);
		cur = cur->next;
	}

	return 0;	
}

