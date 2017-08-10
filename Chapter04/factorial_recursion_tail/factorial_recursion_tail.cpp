/* factorial_recursion_tail.cpp */
#include <iostream>

using namespace std;

// Function for calculating factorial
// tail recursion
int factorialTail(int n, int i)
{
    if (n == 0)
        return i;

    return factorialTail(n - 1, n * i);
}

// The caller of tail recursion function
int factorial(int n)
{
    return factorialTail(n, 1);
}

auto main() -> int
{
    cout << "[factorial_recursion_tail.cpp]" << endl;

    // Invoking fibonacci() function ten times
    for(int i = 1; i < 1000000; ++i)
    {
        cout << i << "! = " << factorial(i) << endl;
    }

    return 0;
}
