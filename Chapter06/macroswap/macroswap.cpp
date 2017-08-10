/* macroswap.cpp */
#include <iostream>

using namespace std;

// Defining multi line macro
#define SWAP(a,b) { \
    (a) ^= (b); \
    (b) ^= (a); \
    (a) ^= (b); \
    }

auto main() -> int
{
    cout << "[macroswap.cpp]" << endl;

    // Initializing two int variables
    int x = 10;
    int y = 20;

    // Displaying original variable value
    cout << "before swapping" << endl;
    cout << "x = " << x << ", y = " << y ;
    cout << endl << endl;

    // Consuming the SWAP macro
    SWAP(x,y);

    // Displaying swapped variable value
    cout << "after swapping" << endl;
    cout << "x = " << x << ", y = " << y;
    cout << endl;

    return 0;
}
