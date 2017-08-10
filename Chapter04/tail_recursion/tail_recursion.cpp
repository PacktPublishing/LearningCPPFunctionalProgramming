/* tail_recursion.cpp */
#include <iostream>

using namespace std;

void displayNumber(long long n)
{
    // Displaying the current n value
    cout << n << endl;

    // The last executed statement
    // is the recursive call
    displayNumber(n + 1);
}

auto main() -> int
{
    cout << "[tail_recursion.cpp]" << endl;

    // Invoking the displayNumber() function
    // containing tail recursion
    displayNumber(0);
    return 0;
}
