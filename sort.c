#include <stdio.h>
#include <stdlib.h>

int * merge(int *a1,int len1,int *a2,int len2);
int * mergeSort(int *a,int len);

void quickSort(int *a,int len);
int partition(int *a,int len);
void swap(int *a,int i1,int i2);

//void findKthSmallest(int * a, int len,int k);
//void findMedian(int * a, int len);

// Test data for main
int size = 10;
int a[10] = {4,5,6,8,11,9,3,4,5,6};

//*******************Helpers ****************************************//
void swap(int *a,int i1,int i2){
	int tmp = a[i1];
	a[i1]= a[i2];
	a[i2] = tmp;
}
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

int partition(int *a,int lastIndex){
    //Move pivot to the end
	int pivotIndex = (lastIndex+1)/2;	
	int pivotValue = a[pivotIndex];
	printf("PivotIndex=%d PivotValue=%d\n",pivotIndex,pivotValue);
	swap(a,pivotIndex,lastIndex);
	int storeIndex = 0;
	for(int i =0;i<lastIndex;i++){
		if(a[i]<=pivotValue){
			swap(a,storeIndex,i);
			storeIndex++;
		}
	}
	swap(a,lastIndex,storeIndex);
	return storeIndex;
}


void quickSort(int *a,int len){     
	 
	if(len<=1){
		return;
	}
	int pivotIndex = partition(a,len-1);	
	int i=0;  
     while(i<len){    
     printf("%d,",a[i]);
     i++;
     }
    printf("\n");	 
	quickSort(a,pivotIndex);
    quickSort(&a[pivotIndex+1],len-(pivotIndex+1));        
}

//********************* Median and Order statistics ************************//
/*void findKthSmallest(int * a, int len,int k){
	if(len<=1){
		return;
	}
	int pivotIndex = (len+1)/2;	
	int pivotValue = a[pivotIndex];
	partition(
	



}*/

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
