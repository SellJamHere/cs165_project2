#include "BigInt.h"

const int ASCII_0 = 48;



BigInt::BigInt()
{

}

BigInt::BigInt(string &stringInt)
{
    int size = stringInt.size();

    for (int i = size - 1, j = 0; i >= 0; i--, j++)
    {
        this->digits.push_back(stringInt[i] - ASCII_0);
    }
}

BigInt::~BigInt()
{

}

BigInt & BigInt::operator=(string &stringInt)
{
    this->digits.clear();
    int size = stringInt.size();

    for (int i = size - 1, j = 0; i >= 0; i--, j++)
    {
        this->digits.push_back(stringInt[i] - ASCII_0);
    }

    return *this;
}

BigInt & BigInt::operator+(BigInt &leftInt)
{
    return *this;
}

BigInt & BigInt::operator-(BigInt &leftInt)
{
    return *this;
}

BigInt & BigInt::operator*(BigInt &leftInt)
{
    return *this;
}

BigInt & BigInt::operator/(BigInt &leftInt)
{
    return *this;
}

BigInt & BigInt::operator%(BigInt &leftInt)
{

}

ostream& operator<<(ostream &os, BigInt &bigInt)
{
    int integerSize = bigInt.digits.size();
    for (int i = integerSize - 1; i >= 0; i--)
    {
        cout << bigInt.digits[i];
    }
    return os;
}