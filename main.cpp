#include <iostream>

#include "BigInt.h"
#include "Random.h"
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
    }

    return 0;
}