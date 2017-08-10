/* lambda_expression_generic.cpp */
#include <iostream>

using namespace std;

auto main() -> int
{
    cout << "[lambda_capturing_by_reference.cpp]" << endl;

    // Creating a generic lambda expression
    auto findMax = [](auto &x, auto &y){
        return x > y ? x : y; };

    // Initializing various variables
    int i1 = 5, i2 = 3;
    float f1 = 2.5f, f2 = 2.05f;

    // Consuming generic lambda expression
    // using integer data type
    cout << "i1 = 5, i2 = 3" << endl;
    cout << "Max: " << findMax(i1, i2) << endl << endl;

    // Consuming generic lambda expression
    // using double data type
    cout << "f1 = 2.5f, f2 = 2.05f" << endl;
    cout << "Max: " << findMax(f1, f2) << endl << endl;

    return 0;
}
