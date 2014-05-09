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
    
    //Functions to find the prime
    bool BumbleBee(); //Works! Uses Fermat's theorem

private:
    // Store the least significant digit first, so that
    // adding and multiplying increase the size as
    // significant digits get larger
    // eg. 1234 --> [4][3][2][1]
    vector<short> digits;

    //private member functions
    bool lessThanTen() const;
    int* digitsToArray() const;
    void arrayToDigits(int *digits, int size);
    BigInt shiftLeft(int digits) const;
    BigInt shiftRight(int digits) const;
    int toInt() const;

    //Helper friend functions
    friend void removeLeadingZeros(BigInt &bigInt);
    friend BigInt randomize(BigInt N);

    //Helper arithmetic functions
    friend BigInt add(const BigInt &rightInt, const BigInt &leftInt);
    friend BigInt subtract(const BigInt &leftInt, const BigInt &rightInt);

    friend BigInt multiplicationByAddition(const BigInt &leftInt, const BigInt &rightInt);
    friend BigInt longMultiplication(const BigInt &num1, const BigInt &num2);
    friend void karatsubaArrayWrapper(const BigInt &int1, const BigInt &int2, BigInt &int3);

    friend BigInt divideBySubtraction(const BigInt &numerator, const BigInt &denominator, BigInt &remainder);
    friend BigInt divideFast(const BigInt &N, const BigInt &D, BigInt &remainder);
    friend BigInt longDivision(const BigInt &num1, int num2, int &remainder);

    friend BigInt bigPow(const BigInt &base, const BigInt &exponent);
    friend BigInt fastPow(const BigInt &base, const BigInt &exponent, const BigInt N);

    friend BigInt Eric(const BigInt &a, const BigInt &i, const BigInt &N);
    friend BigInt nextPrime(const BigInt &N);


    //unused methods
    friend BigInt gcd(BigInt num1, BigInt num2); //euclid's
    friend int J(BigInt x, BigInt y); //jacobi symbol
    friend int Steven(BigInt b, BigInt N); //congruence
    friend bool MillerLite(BigInt N, int k);
    bool optimusPrime();
};



#endif