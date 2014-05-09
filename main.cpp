#include <iostream>

#include "BigInt.h"
#include "Random.h"
#include "Timer.h"
#include <string>

using namespace std;

int main()
{
    while (true)
    {
    string bint;
    cout << "Please enter a number terminated by a carriage return: " << endl;
    getline (cin, bint);
    
    BigInt B(bint);
    
    //cout << "You entered the big integer: " << B << endl;
    
    // BigInt bigInt(23);
    // // cout << bigInt.toInt() << endl;
    // // cout << bigInt << endl;
    // // cout << bigInt.splitTopHalf(bigInt, 3) << " " << bigInt.splitBottomHalf(bigInt, 3) << endl;

    // BigInt bigInt2;
    // bigInt2 = "23";
    // // cout << bigInt2.toInt() << endl;
    // BigInt bigInt3 = bigInt + bigInt2;

    // //cout << bigInt << " + "  << bigInt2 << " = " << bigInt3 << endl;
    // bigInt3 = bigInt - bigInt2;
    // //cout << bigInt << " - " << bigInt2 << " = " << bigInt3 << endl;

    // cout << endl << endl;

    // BigInt greater(0);
    // BigInt lesser("0");
    // // greater--;
    // //cout << (lesser < greater ? "YES" : "NO") << endl;

    // BigInt bigInt4("12345678910111213");
    // BigInt bigInt5("3231145");
    // BigInt bigMult = bigInt4 / bigInt5;
    // cout << bigInt4 << " / " << bigInt5 << " = " << bigMult << endl;


    // bigMult = bigInt4 % bigInt5;
    // cout << bigInt4 << " % " << bigInt5 << " = " << bigMult << endl;

//     BigInt base(67);
//     BigInt exponent(34);
// //    cout << base << " ^ " << exponent << " = " << bigPow(base, exponent) << endl;
//     cout << "GCD(" << base << ", " << exponent << ") = " << gcd(base, exponent) << endl;
//     cout << "Make sure base(" << base << ") and exponent(" << exponent << ") did not change\n";
    
//     cout << "J: " << J(base, exponent) << endl;
    
//     cout << "Steven: " << Steven(base, exponent) << endl;
    
    
    //Random number generator
//    Random random;
//    int rando = random.getRandom(30);
//    for (int i = 0; i<20; i++)
//    {
//        rando = random.getRandom(0);
//        cout << "Random number: " << rando << endl;
//    }
//    cout << "Random number: " << rando << endl;
    
    //Random number from 0 to
    // BigInt bigInt6("1000");
    // BigInt ran = randomize(bigInt6);
    //cout << "Random number between 0 and " << bigInt6 << " : " << ran << endl;
    
//     //Random number generator
//     Random random;
//     int rando = random.getRandom(20);
//     for (int i = 0; i<20; i++)
//     {
//         rando = random.getRandom(0);
//         cout << "Random number: " << rando << endl;
//     }
//     cout << "Random number: " << rando << endl;

//    BigInt bigPrime("331");
//    bool result = MillerLite(bigPrime, 10);
    bool prime = B.BumbleBee();
    
    if (prime == 0)
    {
        cout << "The number: " << endl;
        cout << B << endl;
        cout << "is not prime. The next prime number is: " << endl;
        BigInt next = nextPrime(B);
        cout << next << endl;
    }
    else if (prime == 1)
    {
        cout << "The number: " << endl;
        cout << B << endl;
        cout << "is prime." << endl;
    }
    // cout << "Prime? " << prime;
    // cout << "Prime with miller? " << result;


    cout << globalTimer << endl;
    
    //return 0;
    }
}