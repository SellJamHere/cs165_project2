#include <iostream>

#include "BigInt.h"
#include <string>

using namespace std;

int main()
{
    BigInt bigInt("12345");

    BigInt bigInt2;
    bigInt2 = "1234";
    BigInt bigInt3 = bigInt + bigInt;

    cout << bigInt << " + " << bigInt << " + "  << bigInt2 << " = " << bigInt3 << endl;

    return 0;
}