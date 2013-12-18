#ifndef BIGNUM_H
#define BIGNUM_H

#include <iostream>
#include <cstddef>
#include <cstdint>
#include <string>

using namespace std;

class BigNum
{

//Stream operators

friend std::ostream& operator<<(std::ostream& ostr, const BigNum& i);

private:
	size_t numBytes;
	uint8_t *bytes;

public:
	// Class contructor and destructors
	BigNum(); // Constructor
	~BigNum(); // Destructor
	BigNum(const BigNum& other); // Copy constructor

                
	
	//Assignment operator =	
	BigNum& operator=(const char *newValue); // Assignment to string literal BigNum a = '123456'
        /*
	friend operator=(int& value); // Assignment to int BigNum a = 123
	friend operator=(long& value); // Assignment to long 
	friend operator=(long long& value); // Assignment to long long
      
	
        /*
	// Binary addition operator +
        friend BigNum operator+(const BigNum& i, const BigNum& other); // Add to BigNum
	friend BigNum operator+(const BigNum& i, const char& other); // Add to string literal
	friend BigNum operator+(const BigNum& i, int& other); // Add to integer
	friend BigNum operator+(const BigNum& i, long& other); // Add to long integer 
	friend BigNum operator+(const BigNUm& i, long long& other); // Add to long long integer	
        */        

};

#endif
