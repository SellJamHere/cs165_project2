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
    BigInt(BigInt *bigInt);
    BigInt(const BigInt *bigInt);
    BigInt(const string &stringInt);
    BigInt(int integer);
    ~BigInt();

    const BigInt& operator=(const string &stringInt);

    //Overload arithmetic operators
    BigInt operator+(const BigInt &rightInt) const;
    BigInt operator+=(const BigInt &rightInt);
    BigInt operator+=(int rightInt);
    BigInt operator++(int);
    BigInt operator-(const BigInt &rightInt) const;
    BigInt operator-=(const BigInt &rightInt);
    BigInt operator--(int);
    BigInt operator*(const BigInt &rightInt) const;
    BigInt operator*(int rightInt) const;
    BigInt operator/(const BigInt &rightInt) const;
    BigInt operator/(int rightInt) const;
    BigInt operator%(const BigInt &rightInt) const;

    //Overload relational operators
    bool operator==(const BigInt &rightInt) const;
    bool operator>(const BigInt &rightInt) const;
    bool operator<(const BigInt &rightInt) const;

    friend ostream & operator<<(ostream &os, const BigInt &bigInt);

    bool isOdd();
    int toInt() const;


private:
    // Store the least significant digit first, so that
    // adding and multiplying increase the size as
    // significant digits get larger
    // eg. 1234 --> [4][3][2][1]
    vector<short> digits;

    //private member functions
    BigInt add(const BigInt &rightInt, const BigInt &leftInt) const;
    BigInt subtract(const BigInt &leftInt, const BigInt &rightInt) const;
    BigInt multiplicationByAddition(const BigInt &leftInt, const BigInt &rightInt) const;
    BigInt longMultiplication(const BigInt &num1, const BigInt &num2) const;
    BigInt karatsuba(const BigInt &num1, const BigInt &num2) const;
    BigInt divideBySubtraction(const BigInt &numerator, const BigInt &denominator, BigInt &remainder) const;
    BigInt longDivision(const BigInt &num1, int num2, int &remainder) const;

    //Helper functions
    BigInt splitTopHalf(const BigInt &num, int index) const;
    BigInt splitBottomHalf(const BigInt &num, int index) const;
    bool lessThanTen() const;
    void removeLeadingZeros(BigInt &bigInt) const;
    
    
};

BigInt bigPow(const BigInt &base, const BigInt &exponent);
BigInt gcd(BigInt num1, BigInt num2);
int J(BigInt x, BigInt y);
int Steven(BigInt b, BigInt N);

#endif