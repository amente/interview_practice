#include <stdio.h>
#include "atoi.c"

#define SIZESTR(a,type) sizeof(a)/sizeof(type) - 1


int main(void){
	
	char a[] = "ABCDEFGH";
	printf("Original: %s\n",a);	
	printf("SIZE: %d\n",SIZESTR(a,char));
	rotateArray(a,SIZESTR(a,char),3);
	printf("Rotated Left by 3: %s\n",a);

	return 0;

}