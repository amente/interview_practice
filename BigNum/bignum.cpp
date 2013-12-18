#include "bignum.h"
#include "helpers.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

BigNum::BigNum(){
	numBytes = 0;	
	bytes = 0;
}	



BigNum::~BigNum(){
	delete[] bytes;	
}

BigNum::BigNum(const BigNum& other){
	
}


BigNum& BigNum::operator=(const char *newValue){			
	delete[] bytes; // Delete the old value	
	if(newValue[0]=='\0'){		
		numBytes = 0;
	}else{  
		//Count valid digits
		size_t i = 0;       
		while(newValue[i]!='\0' && newValue[i]>='0' && newValue[i]<='9'){	 						
			i++;			
		}			
		//Convert the newValue to binary and store 
		numBytes = BigNumHelpers::convert(newValue,i,&bytes);				
	}

	return *this;
}

std::ostream& operator<<(std::ostream& ostr, const BigNum& i){
    for(int j=0;j<i.numBytes;j++){
	ostr<<hex<<i.bytes[j];
    }	
    return ostr;	
}
