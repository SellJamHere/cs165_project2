How to use the program:
Our makefile is stored under the name "make". Navigate to where our makefile has been downloaded and enter in the command line:
    shell> make
    shell> ./a.out

Description of data structure implementation:
The data structure we are using for our main data element, BigInt, is a vector of short ints. Each of the short integers in a BigInt represent one of the digits of the number given to our program as input. Using this vector structure, we are able to perform all of the same operations on it as if it was an integer.

Theoretical time analysis of the underlying algorithms:
Our main alogirthm that determines whether a number is prime or not takes about 2^N time to complete (N being the number the function is given to determine the primality).

Production of a function (based on your timing and analysis) to predict the time required by your system for larger instances of the problem:
The time our program takes to complete for larger inputs is unrealistically slow and would be impossible to predict. However, we can assume that the time our program takes increases exponentially as the input size increases.

Accurate analysis of the space requirements:
The algorithm we believe takes the most space is our Karatsuba algorithm to do fast multiplication. Since Karatsuba is making copies of the inputs and then splitting those inputs in half until it can no long split the vector, we can assume that the space it takes is NlogN. 