#include "helpers.h"
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cmath>

using namespace std;
/* Divides an ascii represented decimal integer by two
 * Assumes the chars are between '0' and '9' 
*/
void BigNumHelpers::divideByTwo(char *str,size_t n){
	char prev = '0';
	char cur = *str;	
	while(n>0){	
   		*str = (((prev-'0')%2)?'5':'0')+ (cur-'0')/2;	
		str++;
		prev = cur;
		cur = *str;
		n--;	
	}
}

/*
* Converts an ascii represented decimal integer to binary
* Assumes the chars are between '0' and '9' 
* The converted value is allocated on heap and returned to result
* Returns the number of allocate chars
*/
size_t BigNumHelpers::convert(const char *str, size_t n,uint8_t **result){
	char *copy = (char *)calloc(n,sizeof(char)); // Allocate space for a working copy
	memcpy(copy,str,n);
	size_t numChars =(size_t)ceil(ceil(n*3.32)/8); // Number of chars required to store n*3.32 bit required to store a decimal
	uint8_t *a = (uint8_t *)calloc(numChars,sizeof(uint8_t)); // Allocate the result
	assert(a!=0);	
	size_t bitLevel = numChars-1;	
	uint8_t bitMask = 0x01; 
	while(bitLevel>=0){	
		if((copy[n-1]-'0')%2){
			a[bitLevel]= a[bitLevel]|bitMask; // Set the bit to 1
		}else{
			a[bitLevel] = a[bitLevel]&(~bitMask); // Set the bit to 0
		}	
		BigNumHelpers::divideByTwo(copy,n); // Divide the number by two in place		
		bitMask<<=1;	
		if(bitMask==0){	
			bitMask=0x01;
			bitLevel--;
		}	
	}
        free(copy);
	*result = a;
	return numChars;
}

