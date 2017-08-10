/* factorial_iteration_for.cpp */
#include <iostream>

using namespace std;

// Function containing
// for loop iteration
int factorial (int n)
{
    int result = 1;

    // Running iteration using for loop
    for(int i = 1; i <= n; ++i)
    {
        result *= i;
    }

    return result;
}

auto main() -> int
{
    cout << "[factorial_iteration_for.cpp]" << endl;

    // Invoking factorial() function nine times
    for(int i = 1; i < 10; ++i)
    {
        cout << i << "! = " << factorial(i) << endl;
    }

    return 0;
}
