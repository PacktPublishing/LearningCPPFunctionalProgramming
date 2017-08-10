/* factorial_iteration_do_while.cpp */
#include <iostream>

using namespace std;

// Function containing
// do-while loop iteration
int factorial (int n)
{
    int result = 1;
    int i = 1;

    // Running iteration using do-while loop
    do
    {
        result *= i;
    }
    while(++i <= n);

    return result;
}

auto main() -> int
{
    cout << "[factorial_iteration_do_while.cpp]" << endl;

    // Invoking factorial() function nine times
    for(int i = 1; i < 10; ++i)
    {
        cout << i << "! = " << factorial(i) << endl;
    }

    return 0;
}
