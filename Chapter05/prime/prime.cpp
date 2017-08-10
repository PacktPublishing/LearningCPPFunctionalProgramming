/* prime.cpp */
#include <iostream>
#include <cmath>

using namespace std;

bool PrimeCheck(int i)
{
    // All even numbers are not prime number
    // except 2
    if ((i % 2) == 0)
    {
        return i == 2;
    }

    // Calculating the square root of i
    // and store in int data type variable
    // if the argument i is not even number,
    int sqr = sqrt(i);

    // For numbers 9 and below,
    // the prime numbers is simply the odd numbers
    // For number above 9
    // the prime numbers is all of odd numbers
    // except the square number
    for (int t = 3; t <= sqr; t += 2)
    {
        if (i % t == 0)
        {
            return false;
        }
    }

    // The number 1 is not prime number
    // but still passing the preceding test
    return i != 1;
}

auto main() -> int
{
    cout << "[prime.cpp]" << endl;

    // Initializing a counting variable
    int n = 0;

    // Displaying the first 100 prime numbers
    cout << "List of the first 100 prime numbers:" << endl;
    for (int i = 0; ; ++i)
    {
        if (PrimeCheck(i))
        {
            cout << i << "\t";

            if (++n == 100)
                return 0;
        }
    }

    return 0;
}
