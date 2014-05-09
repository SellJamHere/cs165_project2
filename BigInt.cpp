#include "BigInt.h"
#include "Random.h"

#include <time.h>
#include <math.h>

#include "Timer.h"
#include "Random.h"

#define NUMBER_BASE 10

const int ASCII_0 = 48;

BigInt::BigInt()
{
    digits.push_back(0);
}

BigInt::BigInt(BigInt *bigInt)
{
    digits = bigInt->digits;
}

BigInt::BigInt(const BigInt *bigInt)
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

const BigInt& BigInt::operator=(const string &stringInt)
{
    this->digits.clear();
    int size = stringInt.size();

    for (int i = size - 1, j = 0; i >= 0; i--, j++)
    {
        this->digits.push_back(stringInt[i] - ASCII_0);
    }

    return *this;
}

BigInt BigInt::operator+(const BigInt &rightInt) const
{
    BigInt sum = add(*this, rightInt);
    return sum;
}

BigInt BigInt::operator+=(const BigInt &rightInt)
{
    *this = *this + rightInt;
    return *this;
}

BigInt BigInt::operator+=(int rightInt)
{
    BigInt bigRightInt(rightInt);
    *this = *this + bigRightInt;
    return *this;
}

BigInt BigInt::operator++(int)
{
    *this = *this += 1;
    return *this;
}

BigInt BigInt::operator-(const BigInt &rightInt) const
{
    BigInt difference = subtract(*this, rightInt);

    return difference;
}

BigInt BigInt::operator-=(const BigInt &rightInt)
{
    *this = *this - rightInt;
    return *this;
}

BigInt BigInt::operator--(int)
{
    *this = *this -= 1;
    return *this;
}

BigInt BigInt::operator*(const BigInt &rightInt) const
{
    return karatsuba(*this, rightInt);
}

BigInt BigInt::operator*(int rightInt) const
{
    BigInt integer(rightInt);
    return longMultiplication(*this, integer);
}

BigInt BigInt::operator/(const BigInt &rightInt) const
{
    BigInt remainder;
    return divideBySubtraction(*this, rightInt, remainder);
}

BigInt BigInt::operator/(int rightInt) const
{
    int remainder = 0;
    BigInt returnInt = longDivision(*this, rightInt, remainder);
    return returnInt;
}

BigInt BigInt::operator%(const BigInt &rightInt) const
{
    BigInt remainder;
    BigInt quotient = divideBySubtraction(*this, rightInt, remainder);
    return remainder;
}

//Overload relational operators
bool BigInt::operator==(const BigInt &rightInt) const
{
    if (this->digits.size() != rightInt.digits.size())
    {
        return false;
    }
    for (int i = this->digits.size() - 1; i >= 0; i--)
    {
        if (this->digits[i] != rightInt.digits[i])
        {
            return false;
        }
    }
    return true;
}

//BigInts must not have leading zeros when > is called
bool BigInt::operator>(const BigInt &rightInt) const
{
    if (this->digits.size() > rightInt.digits.size())
    {
        return true;
    }
    else if (this->digits.size() == rightInt.digits.size())
    {
        for (int i = this->digits.size() - 1; i >= 0; i--)
        {
            if (this->digits[i] > rightInt.digits[i])
            {
                return true;
            }
            else if (this->digits[i] < rightInt.digits[i])
            {
                return false;
            }
        }
    }
    return false;
}

bool BigInt::operator<(const BigInt &rightInt) const
{
    if (this->digits.size() < rightInt.digits.size())
    {
        return true;
    }
    else if (this->digits.size() == rightInt.digits.size())
    {
        for (int i = this->digits.size() - 1; i >= 0; i--)
        {
            if (this->digits[i] < rightInt.digits[i])
            {
                return true;
            }
            else if (this->digits[i] > rightInt.digits[i])
            {
                return false;
            }
        }
    }
    return false;
}

ostream& operator<<(ostream &os, const BigInt &bigInt)
{
    int integerSize = bigInt.digits.size();
    for (int i = integerSize - 1; i >= 0; i--)
    {
        os << bigInt.digits[i];
    }
    return os;
}

BigInt bigPow(const BigInt &base, const BigInt &exponent)
{
    // globalTimer.beginFunction("bigPow");
//    cout << "base: " << base << endl;
    BigInt power(base);
//    cout << "power: " << power << endl;
    BigInt i(1);
    //for (; exponent > i; i++)
    for (BigInt j(1); j < exponent; j++)
    {
//        cout << "base: " << base << endl;
        power = power * base;
//        cout << "power: " << power << endl;
    }
    // globalTimer.endFunction("bigPow");
    return power;
}

BigInt gcd(BigInt num1, BigInt num2)
{
    // globalTimer.beginFunction("gcd");
    BigInt temp;
    while (!(num2 == 0))
    {
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    // globalTimer.endFunction("gcd");
    return num1;
}

int J(BigInt x, BigInt y)
{
    BigInt one(1);
    BigInt two(2);
    BigInt four(4);
    BigInt eight(8);
    if (x == one)
    {
        return 1;
    }
    else if (!x.isOdd())
    {
        BigInt exponent = ((bigPow(y, two) - one) / eight);
        cout << "exponent: " << exponent << endl;
        
        //return (J(x/two, y) * bigPow(-1, exponent));
        if (exponent.isOdd())
        {
            return J(x / two, y) * - 1;
        }
        else
        {
            return J(x / two, y);
        }
    }
    else
    {
        BigInt exponent = ((x - one) * (y - one) / four);
        
        //return (J(y % x, x) * bigPow(-1, exponent));
        if (exponent.isOdd())
        {
            return J(y % x, x) * - 1;
        }
        else
        {
            return J(y % x, x);
        }
    }
}

int Steven(BigInt b, BigInt N)
{
    BigInt zero;
    BigInt one(1);
    BigInt two(2);
    BigInt x((N-one)/two);
    BigInt y(b);
    int a = 1;
    
    //return bigPow(b, ((N-one)/two));
    
    while (x > zero)
    {
        if (x.isOdd()){
            BigInt bigA(a);
            BigInt temp(multiplicationByAddition(y, bigA) % N);
            a = temp.toInt();
        }
        // BigInt two(2);
        //y = bigPow(y, two) % N;
        y = karatsuba(y, y) % N;
        x = x/two;
//        cout << "x: " << x << endl;
    }
    return a;
}

bool BigInt::optimusPrime() 
{
    Random randomGenerator;
    BigInt one(1);
    BigInt zero;
    int k = 10;
    // BigInt bigK(k);
    for (int i = 0; i < k; i++) {
        BigInt b(randomGenerator.getRandom(0)+1);
        cout << "b: " << b << endl;
        BigInt j(J(b,*this));
        BigInt steven(Steven(b,*this));
        steven = steven;
        
        
        BigInt Gcd;
        Gcd = gcd(b,*this);
        cout << "gcd: " << Gcd << " J: " << j << " Steven: " << steven << endl;
        if (!(Gcd == one && ((j - steven) == zero)))
        {
            return false;
        }
    }
    
    return true;
}



//Private methods
BigInt add(const BigInt &rightInt, const BigInt &leftInt)
{
    int largestDigitStop = (leftInt.digits.size() > rightInt.digits.size()) ? rightInt.digits.size() - 1 : leftInt.digits.size() - 1;
    
    int sum = 0;
    int carry = 0;

    //sum digits up to smallest number
    BigInt temp;
    temp.digits.pop_back();
    for (int i = 0; i <= largestDigitStop; i++)
    {
        sum = leftInt.digits[i] + rightInt.digits[i] + carry;
        if (sum >= NUMBER_BASE)
        {
            carry = 1;
            temp.digits.push_back(sum - NUMBER_BASE);
        }
        else
        {
            carry = 0;
            temp.digits.push_back(sum);
        }
    }

    //add digits of larger number
    if (largestDigitStop == leftInt.digits.size() - 1)
    {
        for (int i = largestDigitStop + 1; i < rightInt.digits.size(); i++)
        {
            sum = rightInt.digits[i] + carry;
            if (sum >= NUMBER_BASE)
            {
                carry = 1;
                temp.digits.push_back(sum - NUMBER_BASE);
            }
            else
            {
                carry = 0;
                temp.digits.push_back(sum);
            }
        }
    }
    else
    {
        for (int i = largestDigitStop + 1; i < leftInt.digits.size(); i++)
        {
            sum = leftInt.digits[i] + carry;
            if (sum >= NUMBER_BASE)
            {
                carry = 1;
                temp.digits.push_back(sum - NUMBER_BASE);
            }
            else
            {
                carry = 0;
                temp.digits.push_back(sum);
            }
        }
    }
    //final carry
    if (carry > 0)
    {
        temp.digits.push_back(carry);
    }
    removeLeadingZeros(temp);

    return temp;
}

BigInt subtract(const BigInt &leftInt, const BigInt &rightInt)
{
    
    if (!(leftInt > rightInt) && !(leftInt == rightInt))
    {
        //cout << leftInt << " is not greater than or equal to " << rightInt << endl;
        return leftInt;
    }
    int carry = 0;
    BigInt temp(leftInt);
    
    for (int i = 0; i < leftInt.digits.size(); i++)
    {
        if (i >= rightInt.digits.size())
        {
            break;
        }
        int difference = temp.digits[i] - rightInt.digits[i];
        if (difference < 0)
        {
            //find first index that isn't zero
            int zeroIndex = i + 1;
            while (temp.digits[zeroIndex] == 0)
            {
                zeroIndex++;
            }
            //borrow down
            while (zeroIndex > i)
            {
                temp.digits[zeroIndex] = temp.digits[zeroIndex] - 1;
                temp.digits[zeroIndex - 1] += NUMBER_BASE;
                zeroIndex--;
            }
            difference += NUMBER_BASE;
        }
        temp.digits[i] = difference;
    }

    removeLeadingZeros(temp);
//    if (temp.digits.size() == 0) {
//        temp.digits.push_back(0);
//    }
    
    return temp;
}

BigInt multiplicationByAddition(const BigInt &leftInt, const BigInt &rightInt)
{
    //find larger
    BigInt greater;
    BigInt lesser;
    if (leftInt > rightInt)
    {
        greater = leftInt;
        lesser = rightInt;
    } 
    else
    {
        greater = rightInt;
        lesser = leftInt;
    }
    BigInt i;
    BigInt count;
    BigInt sum;
    sum.digits.pop_back();

    for (; i < lesser; i++)
    {
        sum += greater;
    }

    return sum;
}

BigInt longMultiplication(const BigInt &num1, const BigInt &num2)
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

    BigInt temp;
    
    for (int i = 0; i < lesser.digits.size(); i++)
    {
        int carry = 0;
        int product;
        
        int j;
        for (j = 0; j < greater.digits.size(); j++)
        {
            if (temp.digits.size() < i + j + 1) 
            {
                temp.digits.push_back(0);
            }
            product = temp.digits[i + j] + (lesser.digits[i] * greater.digits[j]) + carry;
            carry = product / 10;
            temp.digits[i + j] = product % 10;
        }

        if (carry)
        {
            product = temp.digits[i + j] + carry;
            carry = product / 10;
            temp.digits[i + j] = product % 10;
        }
    }

    removeLeadingZeros(temp);

    return temp;
}


//doesn't work yet
BigInt karatsuba(const BigInt &int1, const BigInt &int2)
{
    if (int1.lessThanTen() || int2.lessThanTen())
    {
        BigInt tempInt(multiplicationByAddition(int1, int2));
//        cout << "Small Mult: " << tempInt << endl;
        return tempInt;
    }

    int m = max(int1.digits.size(), int2.digits.size()) / 2;
    
    //Split int1
    BigInt top1 = splitTopHalf(const_cast<BigInt &>(int1), m);
    //removeLeadingZeros(top1);
//    cout << "top1: " << top1 << "    ";
    BigInt bottom1 = splitBottomHalf(const_cast<BigInt &>(int1), m);
    //removeLeadingZeros(bottom1);
//    cout << "bottom1: " << bottom1 << "    ";

    //Split int2
    BigInt top2 = splitTopHalf(const_cast<BigInt &>(int2), m);
    //removeLeadingZeros(top2);
//    cout << "top2: " << top2 << "    ";
    BigInt bottom2 = splitBottomHalf(const_cast<BigInt &>(int2), m);
    //removeLeadingZeros(bottom2);
//    cout << "bottom2: " << bottom2 << "    " << endl;

    BigInt z0 = karatsuba(bottom1, bottom2);
    removeLeadingZeros(z0);
//    cout << "z0: " << z0 << endl;
    BigInt z1 = karatsuba((bottom1 - top1), (bottom2 - top2));
    removeLeadingZeros(z1);
//    cout << " z1: " << z1 << endl;
    BigInt z2 = karatsuba(top1, top2);
    removeLeadingZeros(z2);
//    cout << " z2: " << z2 << endl;
    
    BigInt ten(10);
    BigInt two(2);
//    BigInt bigM(m);
    BigInt part1(z2.shiftLeft(m * 2));
    BigInt part2((z2 + z0 - z1).shiftLeft(m));
    //BigInt part2((z1 - z2 - z0).shiftLeft(m));
    //part2 = part2.shiftLeft(m);
    
    BigInt temp(part1 + part2 + z0);
    
    //cout << "Result of karatsuba: " << temp << endl;
    return temp;
}

BigInt divideBySubtraction(const BigInt &numerator, const BigInt &denominator, BigInt &remainder)
{
    BigInt one(1);
    BigInt count;
    BigInt dividend(numerator);

    while (dividend > denominator || dividend == denominator)
    {
//        cout << "dividend: " << dividend << endl;
        dividend -= denominator;
//        cout << "dividend: " << dividend << endl;
        count = count + one;
    }
    remainder = dividend;
    return count;
}

BigInt longDivision(const BigInt &num1, int num2, int &remainder) 
{
    //return 0 if num1 < num2
    BigInt bigNum2(num2);
    if (num1 < bigNum2) {
        return 0;
    }
    BigInt temp;
    int d = num1.digits[num1.digits.size() - 1];
    
    int i = num1.digits.size() - 1;
    while (i >= 0)
    {
        int result = d / num2;
        while (result == 0){
            temp.digits.push_back(result);
            d = num1.digits[i] * 10 + num1.digits[i-1];
            i--;
            result = d / num2;
        }
        
        temp.digits.push_back(result);
        
        d = d - (result * num2);
        
        i--;
        
        if (result != 0)
            d = d * 10 + num1.digits[i];
    }
    
    remainder = d / num2;
    reverse(temp.digits.begin(), temp.digits.end());
    removeLeadingZeros(temp);
    return temp;
}

//Helper functions
BigInt splitTopHalf(const BigInt &num, int index) 
{
    BigInt top;
    top.digits.pop_back();
    for (int i = index; i < num.digits.size(); i++)
    {
        top.digits.push_back(num.digits[i]);
    }
    return top;
}

BigInt splitBottomHalf(const BigInt &num, int index) 
{
    BigInt bottom;
    bottom.digits.pop_back();
    for (int i = 0; i < index; i++)
    {
        bottom.digits.push_back(num.digits[i]);
    }
    return bottom;
}

bool BigInt::lessThanTen() const
{
    return digits.size() < 2;
}

int BigInt::toInt() const
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

void removeLeadingZeros(BigInt &bigInt)
{
    int i = bigInt.digits.size() - 1;
//    cout << "digits: " << bigInt << endl;
    while (i >= 1 && bigInt.digits[i] == 0)
    {
//        cout << "digits[" << i << "] = " << bigInt.digits[i] << endl;
        i--;
    }
    bigInt.digits.resize(i + 1);
    if (bigInt.digits.size() == 0) {
        bigInt.digits.push_back(0);
    }
}

bool BigInt::isOdd()
{
    if (digits.size() > 0)
    {
        return digits[0] % 2 == 1;
    }
    else {
        cout << "Integer is size <= 0";
        return false;
    }
}

BigInt BigInt::shiftLeft(int digits) const
{
    BigInt temp(this);
    for (int i = 0; i < digits; i++) {
        vector<short>::iterator it = temp.digits.begin();
        it = temp.digits.insert(it , 0);
    }
    
    return temp;
}

time_t timer;
Random r;
int r1 = r.getRandom(time(&timer));

BigInt randomize(BigInt N)
{
    BigInt random(N);
    
    for (int i = N.digits.size()-1; i >= 0; i--)
    {
        r1 = r.getRandom(0);
        random.digits[i] = r1;
    }
    
    random = (random % (N - 1)) + 1;
    
    
    removeLeadingZeros(random);
    return random;
}
