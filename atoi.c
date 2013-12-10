#include <stdio.h>
#include <math.h>


char a[] = "-12345";


int atoi(char *s,int len){
   int converted = 0;
   int i;
   for(i=len-1;i>=0;i--){
     
      if(s[i]<48 || s[i]>57){
         if(i==0 && s[i]== 45){
            converted= -1*converted;
         }else{
            goto ERROR;
          }
       }else{      
      	 converted+=(s[i]-48)*(pow(10,len-i-1));  
        }
       printf("%d | %d | %d \n",i,s[i],converted);     
    } 
  return converted;
  ERROR:
     return 0x00;
}

/**
int main(void){
   
  printf("%d",atoi(a,6));
  return 0;
}*/


int isSubstr(char *str,char *find){
	if(*str=='\0' || *find=='\0'){
		return 0;
	}
	int i,j,foundNonMatch;	
	for(i=0;str[i]!='\0';i++){
		foundNonMatch = 0;
		for(j=0;find[j]!='\0';j++){
			if(str[i+j]!=find[j]){
				foundNonMatch =1;
				break;
			}
		}
		if(!foundNonMatch)
			return 1;			
	}
	return 0;
}

void swap(char *a1,char *a2){
	if(a1==a2)return;	
	char tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}


void reverseArray(char *begin,char *end){	
	while(begin<end){
		swap(begin,end);
		begin++;
		end--;
	}
}
// Rotate an array by k units to the left in place
void rotateArray(char *a,int len,int k){
	reverseArray(a,a+k-1);
	reverseArray(a+k,a+len-1);
	reverseArray(a,a+len-1);	
}







