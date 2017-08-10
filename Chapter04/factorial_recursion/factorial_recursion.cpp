/* factorial_recursion.cpp */
#include <iostream>

using namespace std;

// Function containing recursion
int factorial(int n)
{
    // Running recursion here
    if (n == 0)
        return 1;
    else
        return n * factorial (n - 1);
}

auto main() -> int
{
    cout << "[factorial_recursion.cpp]" << endl;

    // Invoking factorial() function nine times
    for(int i = 1; i < 10; ++i)
    {
        cout << i << "! = " << factorial(i) << endl;
    }

    return 0;
}
