#ifndef BIGINT_H_
#define BIGINT_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class BigInt
{
public:
    BigInt();
    BigInt(BigInt* bigInt);
    BigInt(const string &stringInt);
    BigInt(int integer);
    ~BigInt();
    BigInt & operator=(const string &stringInt);
    // BigInt & operator=(const BigInt &rightInt);
    BigInt & operator+(const BigInt &rightInt);
    BigInt & operator-(BigInt &rightInt);
    BigInt & operator*(BigInt &rightInt);
    BigInt & operator*(int rightInt);
    BigInt & operator/(int rightInt);
    BigInt & operator%(BigInt &rightInt);
    int toInt();

    friend ostream & operator<<(ostream &os, BigInt &bigInt);

private:
    // Store the least significant digit first, so that
    // adding and multiplying increase the size as
    // significant digits get larger
    // eg. 1234 --> [4][3][2][1]
    vector<short> digits;

    //private member functions
    bool lessThanTen();
    
    BigInt & longDivision(BigInt &num1, int num2, int &remainder);
    BigInt & longMultiplication(BigInt &num1, BigInt &num2);
    BigInt & karatsuba(BigInt &num1, BigInt &num2);
    BigInt & splitTopHalf(BigInt &num, int index);
    BigInt & splitBottomHalf(BigInt &num, int index);


    void removeLeadingZeros(BigInt &bigInt);
    
};

#endif