/* mutable_1.cpp */
#include <iostream>

using namespace std;

auto main() -> int
{
    cout << "[mutable_1.cpp]" << endl;

    // Initializing an int variable
    int mutableVar = 100;
    cout << "Initial mutableVar = " << mutableVar;
    cout << endl;

    // Manipulating mutableVar
    for(int i = 0; i <= 10; ++i)
        mutableVar = mutableVar + i;

    // Displaying mutableVar value
    cout << "After manipulating mutableVar = " << mutableVar;
    cout << endl;

    return 0;
}
