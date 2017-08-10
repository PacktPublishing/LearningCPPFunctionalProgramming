/* mutable_2a.cpp */
#include <iostream>

using namespace std;

class Name
{
public:
    string str;
};

void Modify(Name &name)
{
    name.str = "Alexis Andrews";
}

auto main() -> int
{
    cout << "[mutable_2a.cpp]" << endl;

    // Initializing a string variable
    Name n = {"Frankie Kaur"};
    cout << "Initial name = " << n.str;
    cout << endl;

    // Invoking Modify() function
    // to modify the n variable
    Modify(n);

    // Displaying n value
    cout << "After manipulating = " << n.str;
    cout << endl;

    return 0;
}
