/* condition.cpp */
#include <iostream>

using namespace std;

// Function that will run
// if the condition is TRUE
void TrueStatement()
{
    cout << "True Statement is run." << endl;
}

// Function that will run
// if the condition is FALSE
void FalseStatement()
{
    cout << "False Statement is run." << endl;
}

auto main() -> int
{
    cout << "[condition.cpp]" << endl;

    // Choosing the function
    // based on the condition
    if (2 + 3 == 5)
        TrueStatement();
    else
        FalseStatement();

    return 0;
}
