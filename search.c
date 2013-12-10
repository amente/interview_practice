#include <stdio.h>


int bsRecursive(int *a, int len,int key){
	if(len == 0) return 0;
	int mid = (len-1)/2+1; // edge case overflow
	if(a[mid]==key){
		return 1;
	}
	if(a[mid]>key){
		return bsRecursive(a,mid,key);
	}else{
		return bsRecursive(&a[mid+1],len-mid,key);
	}
}

int bsIterative(int *a, int len,int key){
	int low = 0,high = len-1;
	int mid;
	int midVal;
	while(low<=high){	    
		mid = low+(high-low)/2; // this could overflow
		midVal = a[mid];
		
		if(midVal<key){
			low = mid+1;
		}else if(midVal>key){
			high = mid-1;
		}else{
			return 1;
		}	
	}
	return 0;// Key not found
}




