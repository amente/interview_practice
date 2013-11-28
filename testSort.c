#include "sort.c"

// Test data for main
int size = 10;
int a[10] = {4,5,6,8,11,9,3,4,5,6};

void main(void){   
   
   /*int * r = mergeSort(a,size);
   int i=0;  
   printf("Merge Sorted\n");
   while(i<size){    
     printf("%d,",r[i]);
     i++;
   }*/
   
   halfSort(a,size);  
   int i=0;  
   printf("Half Sorted\n");
   while(i<size){    
     printf("%d,",a[i]);
     i++;
   }
      
}