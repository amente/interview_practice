#include <stdio.h>
#include <stdlib.h>

int * merge(int *a1,int len1,int *a2,int len2);
int * mergeSort(int *a,int len);

void quickSort(int *a,int len);
void partition(int *a, int pivotIndex,int len);


// Test data for main
int size = 10;
int a[10] = {4,5,6,8,9,2,3,4,5,6};

//**************************Merge Sort*******************************//
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
     if(len <=1){
       return a;
     }     
     int middle = (len+1)/2;
     int * firstHalf = mergeSort(a,middle);
     int * secondHalf = mergeSort(&a[middle],len-middle);
     return merge(firstHalf,middle,secondHalf,len-middle);
}

//****************************Quick Sort **********************************//

void partition(int *a,int pivotIndex, int len){
    int i = 0;
	int pivotValue = a[pivotIndex];
	int less=0;
	while(i<len){
	  if(a[i]<=pivotValue){
			less++;
	    }	
	   i++;
	}	
	int tmp = a[less-1];
	a[less-1] = a[pivotIndex];
	a[pivotIndex] = tmp;	
    
	int greater = len-less;
	i= 0;
	int offset =0;
	while(i<len && greater>0){
		if(a[i]>pivotValue){
			int tmp = a[i];
			a[i]= a[less+offset];
			a[less+offset] = tmp;
			greater--;
			offset++;
			i--;
		}
        i++;		
	}	
	
}


void quickSort(int *a,int len){     
	 
	if(len<=1){
		return;
	}
	int pivotIndex = (len+1)/2;	
	printf("PivotIndex=%d PivotValue=%d\n",pivotIndex,a[pivotIndex]);
	partition(a,pivotIndex,len);	
	int i=0;  
     while(i<len){    
     printf("%d,",a[i]);
     i++;
     }
    printf("\n");	 
	quickSort(a,pivotIndex);
    quickSort(&a[pivotIndex],len-pivotIndex);        
}

void main(void){   
   quickSort(a,size);
   int i=0;  
   printf("Half Sorted\n");
   while(i<size){    
     printf("%d,",a[i]);
     i++;
   }
   
   /**
   printf("\nFull Sorted\n");
   
   int * r;
   r = merge(a,size-2,&a[(sise-2],2); 
   i=0;  
   while(i<size){    
     printf("%d,",r[i]);
     i++;
   }*/
   
}
