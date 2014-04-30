#include "BigInt.h"

#include <math.h>

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

BigInt::BigInt(int integer)
{
    int i = 0;
    while (integer > 0)
    {
        digits.push_back(integer % NUMBER_BASE);
        integer /= NUMBER_BASE;
        i++;
    }
    if (digits.size() == 0)
    {
        digits.push_back(0);
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
    
    int carry = 0;
    for (int i = 0; i < lesser.digits.size(); i++)
    {
        temp->digits[i] = ((greater->digits[i] + lesser.digits[i] + carry) % NUMBER_BASE);
        carry = (greater->digits[i] + lesser.digits[i] + carry) / NUMBER_BASE;
    }
    if(carry != 0)
    {
        temp->digits.push_back(carry);
    }

    return *temp;
}

BigInt & BigInt::operator-(BigInt &rightInt)
{
    int carry = 0;
    BigInt *temp = new BigInt(*this);
    
    for (int i = 0; i < this->digits.size(); i++)
    {
        if (i >= rightInt.digits.size())
        {
            break;
        }
        int difference = temp->digits[i] - rightInt.digits[i];
        if (difference < 0)
        {
            temp->digits[i + 1] = temp->digits[i + 1] - 1;
            difference += 10;
        }
        temp->digits[i] = difference;
    }

    return *temp;
}

BigInt & BigInt::operator*(BigInt &rightInt)
{
    return longMultiplication(*this, rightInt);
}

BigInt & BigInt::operator*(int rightInt)
{
    BigInt integer(rightInt);
    return longMultiplication(*this, integer);
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

//Private methods
bool BigInt::lessThanTen()
{
    return digits.size() < 4;
}

int BigInt::toInt()
{
    if (digits.size() <= 9)
    {
        int toInt = 0;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            toInt += digits[i] * pow(10, i);
        }  
        return toInt;
    }
    else
    {
        cout << "BigInt too large for int representation.\n";
        return -1;
    }
}


BigInt & BigInt::longMultiplication(BigInt &num1, BigInt &num2)
{
    //find largest digit size
    BigInt greater;
    BigInt lesser;
    if (num1.digits.size() > num2.digits.size())
    {
        greater = num1;
        lesser = num2;
    } 
    else
    {
        greater = num2;
        lesser = num1;
    }

    BigInt *temp = new BigInt();
    
    for (int i = 0; i < greater.digits.size(); i++)
    {
        int carry = 0;
        int product;
        
        int j;
        for (j = 0; j < lesser.digits.size(); j++)
        {
            if (temp->digits.size() < i + j + 1)
            {
                temp->digits.push_back(0);
            }
            product = temp->digits[i + j] + (greater.digits[i] * lesser.digits[j]) + carry;
            carry = product / 10;
            temp->digits[i + j] = product % 10;
        }

        if (carry)
        {
            product = temp->digits[i + j] + carry;
            carry = product / 10;
            temp->digits[i + j] = product % 10;
        }
    }

    removeLeadingZeros(*temp);

    return *temp;
}

BigInt & BigInt::karatsuba(BigInt &int1, BigInt &int2)
{
    //Base case: for small numbers
    // if (int1.digits.size() == 1 && int2.digits.size() == 1)
    // {
    //     BigInt *temp = new BigInt(int1.digits[0] * int2.digits[0]);
    //     return *temp;
    // }
    if (int1.lessThanTen() || int2.lessThanTen())
    {
        BigInt *tempInt = new BigInt(int1.toInt()*int2.toInt());
        cout << "Small Mult: " << *tempInt << endl;
        return *tempInt;
    }
    int m = max(int1.digits.size(), int2.digits.size()) / 2;
    
    //Split int1
    BigInt &top1 = splitTopHalf(int1, m);
    cout << "top1: " << top1 << "    ";
    BigInt &bottom1 = splitBottomHalf(int1, m);
    cout << "bottom1: " << bottom1 << "    ";

    //Split int2
    BigInt &top2 = splitTopHalf(int2, m);
    cout << "top2: " << top2 << "    ";
    BigInt &bottom2 = splitBottomHalf(int2, m);
    cout << "bottom2: " << bottom2 << "    " << endl;

    BigInt &z0 = karatsuba(bottom1, bottom2);
    cout << "z0: " << z0 << endl;
    BigInt &z1 = karatsuba((bottom1 + top1), (bottom2 + top2));
    cout << " z1: " << z1 << endl;
    BigInt &z2 = karatsuba(top1, top2);    
    cout << " z2: " << z2 << endl;
        
    BigInt *temp = new BigInt((z2 * (int)pow(10, 2 * m)) + ((z1 - z2 - z0) * (int)pow(10, m)) + z0);
    return *temp;
}

BigInt & BigInt::splitTopHalf(BigInt &num, int index)
{
    BigInt *top = new BigInt();
    for (int i = index; i < num.digits.size(); i++)
    {
        top->digits.push_back(num.digits[i]);
    }
    return *top;
}

BigInt & BigInt::splitBottomHalf(BigInt &num, int index)
{
    BigInt *bottom = new BigInt();
    for (int i = 0; i < index; i++)
    {
        bottom->digits.push_back(num.digits[i]);
    }
    return *bottom;
}

void BigInt::removeLeadingZeros(BigInt &bigInt)
{
    int i = bigInt.digits.size() - 1;
    while (bigInt.digits[i] == 0)
    {
        i--;
    }
    bigInt.digits.resize(i + 1);
}
