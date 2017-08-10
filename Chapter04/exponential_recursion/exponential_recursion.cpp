/* exponential_recursion.cpp */
#include <iostream>

using namespace std;

// Calculating the power of number
// using recursion
int power(int base, int exp)
{
    if(exp == 0)
        return 1;
    else
        return base * power(base, exp - 1);
}

auto main() -> int
{
    cout << "[exponential_recursion.cpp]" << endl;

    // Invoking power() function six times
    for(int i = 0; i <= 5; ++i)
    {
        cout << "power (2, " << i << ") = ";
        cout << power(2, i) << endl;
    }

    return 0;
}
