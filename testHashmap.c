#include <stdio.h>
#include "hashmap.c"






int main(void){

	HM *h = HM_HM();
	printf("Adding: %s\n","one");	
	h->put(h,"one",3,1);
	printf("Size: %d\n",h->size);
	printf("Adding: %s\n","two");
	h->put(h,"two",3,2);
	printf("Size: %d\n",h->size);
	
	printf("Get: %s Result: %d \n","two",h->get(h,"two",3));
	printf("Get: %s Result: %d \n","one",h->get(h,"one",3));
	
	
	
	
	return 0;
}