/* tail_recursion_goto.cpp */
#include <iostream>

using namespace std;

void displayNumber(long long n)
{
loop:
    // Displaying the current n value
    cout << n << endl;

    // Update parameters of recursive call
    // and replace recursive call with goto
    n++;
    goto loop;
}

auto main() -> int
{
    cout << "[tail_recursion_goto.cpp]" << endl;

    // Invoking the displayNumber() function
    // containing tail recursion
    displayNumber(0);

    return 0;
}
