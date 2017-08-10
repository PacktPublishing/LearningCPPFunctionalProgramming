/* lambda_initialization_captures.cpp */
#include <iostream>

using namespace std;

auto main() -> int
{
    cout << "[lambda_initialization_captures.cpp]" << endl;

    // Initializing a variable
    int a = 5;
    cout << "Initial a = " << a << endl;

    // Initializing value to lambda using the variable
    auto myLambda = [&x = a]() { x += 2; };

    // Executing the Lambda
    myLambda();

    // Displaying a new value of the variable
    cout << "New a     = " << a << endl;

    return 0;
}
