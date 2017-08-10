/* mutable_2.cpp */
#include <iostream>

using namespace std;

void Modify(string &name)
{
    name = "Alexis Andrews";
}

auto main() -> int
{
    cout << "[mutable_2.cpp]" << endl;

    // Initializing a string variable
    string n = "Frankie Kaur";
    cout << "Initial name = " << n;
    cout << endl;

    // Invoking Modify() function
    // to modify the n variable
    Modify(n);

    // Displaying n value
    cout << "After manipulating = " << n;
    cout << endl;

    return 0;
}
