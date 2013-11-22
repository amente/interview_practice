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

void main(void){
   
  printf("%d",atoi(a,6));

}
