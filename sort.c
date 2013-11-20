#include <stdio.h>
#include <stdlib.h>

int * merge(int *a1,int len1,int *a2,int len2);
int * mergeSort(int *a,int len);

// Test data for main
int size = 10;
int a[10] = {4,5,6,8,9,2,3,4,5,6};

/**
* Merges two sorted arrays
*/
int * merge(int *a1,int len1,int *a2,int len2){
   int * merged;
   merged = (int *) malloc((len1+len2)*sizeof(int));
   if(merged == NULL){
     printf("Memory allocation failed\n");
     exit(0);
   }
   
   int i1 =0;
   int i2 =0;
   int i = 0;
   while(i1<len1 && i2<len2){
      // Pick the biggest from the two arrays until we finish either one of them
     if(a1[i1]<=a2[i2]){
        merged[i] = a1[i1];
        i1++;
        i++;
      }else{
	merged[i] = a2[i2];
        i2++;
        i++;
      }      
   }
  
    // Finish of the one that is not done yet
   while(i1<len1){
     merged[i] = a1[i1];
     i1++;
     i++;
   }

   while(i2<len2){
     merged[i] = a2[i2];
     i2++;
     i++;
   }   
   return merged;   
}

/**
* Merge sort
*/
int * mergeSort(int *a,int len){ 
     printf("Len:%d \n",len);    
     if(len <=1){
       return a;
     }     
     int middle = (len+1)/2;
     int * firstHalf = mergeSort(a,middle);
     int * secondHalf = mergeSort(&a[middle],len-middle);
     return merge(firstHalf,middle,secondHalf,len-middle);
}

void main(void){
   int * r;
   r = mergeSort(a,size); 
   int i=0;  
   while(i<size){    
     printf("%d,",r[i]);
     i++;
   }
}
