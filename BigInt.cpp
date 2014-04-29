#include "BigInt.h"

#define NUMBER_BASE 10

const int ASCII_0 = 48;

BigInt::BigInt()
{

}

BigInt::BigInt(BigInt* bigInt)
{
    digits = bigInt->digits;
}

BigInt::BigInt(const string &stringInt)
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

BigInt & BigInt::operator=(const string &stringInt)
{
    this->digits.clear();
    int size = stringInt.size();

    for (int i = size - 1, j = 0; i >= 0; i--, j++)
    {
        this->digits.push_back(stringInt[i] - ASCII_0);
    }

    return *this;
}

// BigInt & BigInt::operator=(const BigInt &rightInt)
// {
//     this->digits.clear();
//     int size = rightInt.digits.size();

//     for (int i = 0; i < size; i++)
//     {
//         this->digits.push_back(rightInt.digits[i]);
//     }

//     return *this;
// }

BigInt & BigInt::operator+(const BigInt &rightInt)
{
    //find largest digit size
    BigInt *greater;
    BigInt lesser;
    if (this->digits.size() > rightInt.digits.size())
    {
        greater = this;
        lesser = rightInt;
    } 
    else
    {
        greater = new BigInt(rightInt);
        lesser = *this;
    }
    
    BigInt *temp = new BigInt(greater);
    // cout << "Temp: "<< *temp << endl;
    //add digits together up to the size of the smallest
    // cout << "Beginning loop:" << endl;
    
    int carry = 0;
    for (int i = 0; i < lesser.digits.size(); i++)
    {
        temp->digits[i] = ((greater->digits[i] + lesser.digits[i] + carry) % NUMBER_BASE);
        carry = (greater->digits[i] + lesser.digits[i] + carry) / NUMBER_BASE;
    }
    if(carry != 0)
        temp->digits.push_back(carry);
    
    cout << "End loop" << endl;

    return *temp;
}

BigInt & BigInt::operator-(BigInt &rightInt)
{
    return *this;
}

bool BigInt::lessThanTen()
{
    return digits.size() < 2;
}

BigInt & BigInt::karatsuba(BigInt &int1, BigInt &int2)
{
    //Base case: for small numbers
    if (int1.lessThanTen() || int2.lessThanTen())
        return int1*int2;
    int m = max(int1.digits.size(), int2.digits.size());
    int m2 = m/2;
    
    
    
        
    return int1;
}

BigInt & BigInt::operator*(BigInt &rightInt)
{
    
    
    
    
    return *this;
}

BigInt & BigInt::operator/(BigInt &rightInt)
{
    return *this;
}

BigInt & BigInt::operator%(BigInt &rightInt)
{
    return *this;
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