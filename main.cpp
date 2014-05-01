#include <iostream>

#include "BigInt.h"
#include <string>

using namespace std;

int main()
{
    BigInt bigInt(123456789);
    cout << bigInt.toInt() << endl;
    cout << bigInt << endl;
    // cout << bigInt.splitTopHalf(bigInt, 3) << " " << bigInt.splitBottomHalf(bigInt, 3) << endl;

    BigInt bigInt2;
    bigInt2 = "123456";
    cout << bigInt2.toInt() << endl;
    BigInt bigInt3 = bigInt + bigInt2 + bigInt;

    cout << bigInt << " + " << bigInt << " + "  << bigInt2 << " = " << bigInt3 << endl;
    cout << bigInt << " - " << bigInt2 << " = " << bigInt - bigInt2 << endl;

    cout << endl << endl << endl;

    BigInt bigInt4("100000000000000000039");
    BigInt bigMult = bigInt4 * bigInt4;
    
    cout << "bigInt4 * bigInt4 = " << bigMult << endl;

    return 0;
}