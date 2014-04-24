#include <iostream>

#include "BigInt.h"
#include <string>

using namespace std;

int main()
{
    string numberString = "12345";
    BigInt bigInt(numberString);
    cout << bigInt << endl;

    numberString = "12367";
    bigInt = numberString;
    cout << bigInt << endl;

    return 0;
}