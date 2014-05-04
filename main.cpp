#include <iostream>

#include "BigInt.h"
#include <string>

using namespace std;

int main()
{
    BigInt bigInt(1000);
    // cout << bigInt.toInt() << endl;
    // cout << bigInt << endl;
    // cout << bigInt.splitTopHalf(bigInt, 3) << " " << bigInt.splitBottomHalf(bigInt, 3) << endl;

    BigInt bigInt2;
    bigInt2 = "3";
    // cout << bigInt2.toInt() << endl;
    BigInt bigInt3 = bigInt + bigInt2;

    cout << bigInt << " + "  << bigInt2 << " = " << bigInt3 << endl;
    bigInt3 = bigInt - bigInt2;
    cout << bigInt << " - " << bigInt2 << " = " << bigInt3 << endl;

    cout << endl << endl << endl;

    BigInt greater(0);
    BigInt lesser("0");
    // greater--;
    cout << (greater > lesser ? "YES" : "NO") << endl;

    BigInt bigInt4("144011");
    BigInt bigInt5("1230");
    BigInt bigMult = bigInt4 / bigInt5;
    cout << bigInt4 << " / " << bigInt5 << " = " << bigMult << endl;

    bigMult = bigInt4 % bigInt5;
    cout << bigInt4 << " % " << bigInt5 << " = " << bigMult << endl;

    return 0;
}