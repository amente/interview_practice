#include <stdio.h>

char a[] = "Hello World This is me";

void reverse(char *a,int len);
void reverseStrWords(char *s);

void reverseStrWords(char *s){   
   int charCount=0;
   int i = 0;
   while(s[i]!='\0'){  
      charCount++;    
      if(s[i]==32){                
         reverse(&s[i+1-charCount],charCount-1);
         charCount=0;
       }      
      i++;      
    }    
   
    if(charCount>0){       
      reverse(&s[i-charCount],charCount);
    }  
}
void reverse(char *a,int len){
   int mid = (len+1)/2;
   int begin = 0;
   int end = len-1;
   while(end>=mid && begin<=mid){      
      char temp = a[end];
      a[end] = a[begin];
      a[begin] = temp;
      end--;
      begin++;
    }
}

void main(void){
  reverseStrWords(a);
  printf("%s\n",a);  
}
