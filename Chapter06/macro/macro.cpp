/* macro.cpp */
#include <iostream>

using namespace std;

// Defining macro
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

auto main() -> int
{
    cout << "[macro.cpp]" << endl;

    // Initializing two int variables
    int x = 10;
    int y = 20;

    // Consuming the MAX macro
    // and assign the result to z variable
    int z = MAX(x,y);

    // Displaying the result
    cout << "Max number of " << x << " and " << y;
    cout << " is " << z << endl;

    return 0;
}
