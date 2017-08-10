/* loop.cpp */
#include <iostream>

using namespace std;

// Function for printing
// given number
void PrintNumber(int i)
{
    cout << i << "\t";
}

auto main() -> int
{
    cout << "[loop.cpp]" << endl;

    // Initializing an int variable
    // marking as maximum number
    int i = 100;

    // Looping to print out
    // the numbers below i variable
    cout << "List of numbers between 100 and 1";
    cout << endl;
    do
    {
        PrintNumber(i);
    }
    while (--i > 0);
    cout << endl;

    return 0;
}
