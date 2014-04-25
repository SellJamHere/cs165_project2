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
    BigInt(const string &stringInt);
    ~BigInt();
    BigInt & operator=(const string &stringInt);
    // BigInt & operator=(const BigInt &rightInt);
    BigInt & operator+(const BigInt &rightInt);
    BigInt & operator-(BigInt &rightInt);
    BigInt & operator*(BigInt &rightInt);
    BigInt & operator/(BigInt &rightInt);
    BigInt & operator%(BigInt &rightInt);

    friend ostream & operator<<(ostream &os, BigInt &bigInt);

private:
    // Store the least significant digit first, so that
    // adding and multiplying increase the size as
    // significant digits get larger
    // eg. 1234 --> [4][3][2][1]
    vector<short> digits;
};

#endif