/* impure_function_1.cpp */
#include <iostream>

using namespace std;

// Initializing a global variable
int currentState = 0;

int increment(int i)
{
    currentState += i;
    return currentState;
}

auto main() -> int
{
    cout << "[impure_function_1.cpp]" << endl;

    // Initializing a local variable
    int fix = 5;

    // Involving the global variable
    // in the calculation
    for(int i = 1; i <= 5; ++i)
    {
        cout << "Invocation " << i << " -> ";
        cout << "Result of increment(" << fix << ") = ";
        cout << increment(fix) << endl;
    }

    return 0;
}
