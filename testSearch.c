#include <stdio.h>
#include "search.c"

#define SIZE(a,type)  sizeof(a)/sizeof(type)


int main(void){

	int a[] = {1,4,8};
	int len = SIZE(a,int);
	
	
	printf("Binary Search 5 - Recusive %d : Iterative %d\n",bsRecursive(a,len,5),bsIterative(a,len,5));
	



	return 0;
}