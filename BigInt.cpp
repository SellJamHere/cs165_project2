#include "BigInt.h"

#define NUMBER_BASE 10

const int ASCII_0 = 48;

BigInt::BigInt()
{

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
        greater = new BigInt(this);
        lesser = rightInt;
    } 
    else
    {
        greater = new BigInt(rightInt);
        lesser = *this;
    }

    //add digits together up to the size of the smallest
    cout << "Beginning loop:" << endl;
    for (int i = 0; i < lesser.digits.size(); i++)
    {
        int sum = greater.digits[i] + lesser.digits[i];
        cout << greater.digits[i] << " + " << lesser.digits[i] << " = " << sum << endl;
        //if there is overflow add to next largest digit
        if (sum >= NUMBER_BASE)
        {
            cout << "CARRY! " << sum - NUMBER_BASE << endl;
            greater->digits[i] = sum - NUMBER_BASE;
            greater->digits[i + 1] += 1;
        }
        else
        {
            greater->digits[i] = sum;
        }
    }
    cout << "End loop" << endl;

    for (int i = lesser.digits.size(); i < greater.digits.size(); i++)
    {
        
    }

    return *greater;
}

BigInt & BigInt::operator-(BigInt &rightInt)
{
    return *this;
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