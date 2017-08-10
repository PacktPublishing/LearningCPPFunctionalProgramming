/* switch.cpp */
#include <iostream>

using namespace std;

// Function to find out
// the square of an int
int Square(int a)
{
    return a * a;
}

auto main() -> int
{
    cout << "[switch.cpp]" << endl;

    // Initializing two int variables
    int input = 2;
    int output = 0;

    // Passing the correct argument
    // to the function
    switch (input)
    {
        case 1:
            output = Square(1);
            break;
        case 2:
            output = Square(2);
            break;
        default:
            output = Square(0);
            break;
    }

    // Displaying the result
    cout << "The result is " << output << endl;

    return 0;
}
