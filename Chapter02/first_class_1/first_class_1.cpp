/* first_class_1.cpp */
#include <functional>
#include <iostream>

using namespace std;

// Defining a type of function named FuncType
// representing a function
// that pass two int arguments
// and return an int value
typedef function<int(int, int)> FuncType;

int addition(int x, int y)
{
    return x + y;
}

int subtraction(int x, int y)
{
    return x - y;
}

int multiplication(int x, int y)
{
    return x * y;
}

int division(int x, int y)
{
    return x / y;
}

void PassingFunc(
    FuncType fn, int x, int y)
{
    cout << "Result = " << fn(x, y) << endl;
}

auto main() -> int
{
    cout << "[first_class_1.cpp]" << endl;

    int i, a, b;
    FuncType func;

    // Displaying menu for user
    cout << "Select mode:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "Choice: ";
    cin >> i;

    // Preventing user to select
    // unavailable modes
    if(i < 1 || i > 4)
    {
        cout << "Please select available mode!";
        return 1;
    }

    // Getting input from user for variable a
    cout << "a -> ";
    cin >> a;

    // Input validation for variable a
    while (cin.fail())
    {
        // Clearing input buffer to restore cin to a usable state
        cin.clear();

        // Ignoring last input
        cin.ignore(INT_MAX, '\n');

        cout << "You can only enter numbers.\n";
        cout << "Enter a number for variable a -> ";
        cin >> a;
    }

    // Getting input from user for variable b
    cout << "b -> ";
    cin >> b;

    // Input validation for variable b
    while (cin.fail())
    {
        // Clearing input buffer to restore cin to a usable state
        cin.clear();

        // Ignoring last input
        cin.ignore(INT_MAX, '\n');

        cout << "You can only enter numbers.\n";
        cout << "Enter a number for variable b -> ";
        cin >> b;
    }

    switch(i)
    {
        case 1: PassingFunc(addition, a, b); break;
        case 2: PassingFunc(subtraction, a, b); break;
        case 3: PassingFunc(multiplication, a, b); break;
        case 4: PassingFunc(division, a, b); break;
    }

    return 0;
}
