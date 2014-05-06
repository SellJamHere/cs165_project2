#include <iostream>

#include "BigInt.h"
#include <string>

using namespace std;

int main()
{
    BigInt bigInt(23);
    // cout << bigInt.toInt() << endl;
    // cout << bigInt << endl;
    // cout << bigInt.splitTopHalf(bigInt, 3) << " " << bigInt.splitBottomHalf(bigInt, 3) << endl;

    BigInt bigInt2;
    bigInt2 = "23";
    // cout << bigInt2.toInt() << endl;
    BigInt bigInt3 = bigInt + bigInt2;

    cout << bigInt << " + "  << bigInt2 << " = " << bigInt3 << endl;
    bigInt3 = bigInt - bigInt2;
    cout << bigInt << " - " << bigInt2 << " = " << bigInt3 << endl;

    cout << endl << endl << endl;

    BigInt greater(0);
    BigInt lesser("0");
    // greater--;
    cout << (lesser < greater ? "YES" : "NO") << endl;

    BigInt bigInt4("46");
    BigInt bigInt5("23");
    BigInt bigMult = bigInt4 * bigInt5;
    cout << bigInt4 << " * " << bigInt5 << " = " << bigMult << endl;

    bigMult = bigInt4 % bigInt5;
    cout << bigInt4 << " % " << bigInt5 << " = " << bigMult << endl;

    BigInt base(67);
    BigInt exponent(1000003);
//    cout << base << " ^ " << exponent << " = " << bigPow(base, exponent) << endl;
    cout << "GCD(" << base << ", " << exponent << ") = " << gcd(base, exponent) << endl;
    cout << "Make sure base(" << base << ") and exponent(" << exponent << ") did not change\n";
    
    cout << "J: " << J(base, exponent) << endl;
    
    cout << "Steven: " << Steven(base, exponent) << endl;

    return 0;
}