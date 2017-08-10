/* first_class_3.cpp */
#include <vector>
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

auto main() -> int
{
    cout << "[first_class_3.cpp]" << endl;

    // Declaring a vector containing FuncType element
    vector<FuncType> functions;

    // Assigning several FuncType elements to the vector
    functions.push_back(addition);
    functions.push_back(subtraction);
    functions.push_back(multiplication);
    functions.push_back(division);

    int i, a, b;
    function<int(int, int)> func;

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

    // Invoking the function inside the vector
    cout << "Result = " << functions.at(i - 1)(a, b) << endl;

    return 0;
}
