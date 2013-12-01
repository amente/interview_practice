#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int * merge(int *a1,int len1,int *a2,int len2);
int * mergeSort(int *a,int len);

void quickSort(int *a,int len);
int partition(int *a,int len);
void swap(int *a,int i1,int i2);

void sudoPartition(int *a,int pivotIndex,int len);
void halfSort(int *a,int len);

int findKthSmallest(int * a, int len,int k);
int findMedian(int * a, int len);


//*******************Helpers ****************************************//
void swap(int *a,int i1,int i2){
	int tmp = a[i1];
	a[i1]= a[i2];
	a[i2] = tmp;
}
//**************************Merge Sort *******************************//
/**
* Merges two sorted arrays
* It runs in O(len1+len2)
* It allocates len1+len2 extra memory
*/
int * merge(int *a1,int len1,int *a2,int len2){
   int * merged;
   merged = (int *) malloc((len1+len2)*sizeof(int));
   assert(merged!=NULL);   
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
* An implementation of basic merge sort
* O(nlog(n)) performance all the time
* Takes n(log(n)) memory because of the merge allocation
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
	int pivotIndex = (lastIndex+1)/2; // Random would be better , but just pick middle always	
	int pivotValue = a[pivotIndex];	
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

//***************** Half Sort  ************************//
/**
* This is like quick sort parition, but it is passed the pivotIndex
*/
void sudoPartition(int *a,int pivotIndex, int len){    		
	int pivotValue = a[pivotIndex];	
	swap(a,pivotIndex,len-1);
	int storeIndex = 0;
	for(int i =0;i<len-1;i++){
		if(a[i]<=pivotValue){
			swap(a,storeIndex,i);
			storeIndex++;
		}
	}
	swap(a,len-1,storeIndex);	
}

/**
* This is an in place "near" merge sort, only two halfs of the array are sorted
*/
void halfSort(int *a,int len){
	if(len<=1){
		return;
	}
	int pivotIndex = (len+1)/2;		
	sudoPartition(a,pivotIndex,len);	 
	halfSort(a,pivotIndex);
    halfSort(&a[pivotIndex],len-pivotIndex);    
}

//********************* Median and Order statistics ************************//
int findKthSmallest(int * a, int len,int k){
	if(len<=1){
		return a[0];
	}
	int pivotIndex =partition(a,len-1);
	int pivotDist= pivotIndex+1;
	if(pivotDist ==k){
		return a[pivotIndex];
	}else if(k<pivotDist){
		return findKthSmallest(a,pivotIndex,k);
	}else{
		return findKthSmallest(&a[pivotIndex+1],len-(pivotIndex+1),k-pivotDist);
	}
}
int findMedian(int *a,int len){
	return findKthSmallest(a,len,len/2);
}


