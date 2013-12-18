
all: testBigNum

testBigNum: testBigNum.o bignum.o helpers.o
	g++ testBigNum.o bignum.o helpers.o -o testBigNum -std=c++0x 

testBigNum.o:
	g++ -c testBigNum.cpp -std=c++0x 

bignum.o:
	g++ -c bignum.cpp -std=c++0x 

helpers.o:
	g++ -c helpers.cpp -std=c++0x 

clean:
	rm -rf *.o testBigNum 
