/* immutable_1.cpp */
#include <iostream>

using namespace std;

auto main() -> int
{
    cout << "[immutable_1.cpp]" << endl;

    // Initializing an int variable
    int mutableVar = 100;
    cout << "Initial mutableVar = " << mutableVar;
    cout << endl;

    // Manipulating mutableVar using immutable approach
    int mutableVar0 = mutableVar + 0;
    int mutableVar1 = mutableVar0 + 1;
    int mutableVar2 = mutableVar1 + 2;
    int mutableVar3 = mutableVar2 + 3;
    int mutableVar4 = mutableVar3 + 4;
    int mutableVar5 = mutableVar4 + 5;
    int mutableVar6 = mutableVar5 + 6;
    int mutableVar7 = mutableVar6 + 7;
    int mutableVar8 = mutableVar7 + 8;
    int mutableVar9 = mutableVar8 + 9;
    int mutableVar10 = mutableVar9 + 10;

    // Displaying mutableVar value in mutable variable
    cout << "After manipulating mutableVar = " << mutableVar10;
    cout << endl;

    return 0;
}
