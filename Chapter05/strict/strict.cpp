/* strict.cpp */
#include <iostream>

using namespace std;

int OuterFormula(int x, int yz)
{
    // For logging purpose only
    cout << "Calculate " << x << " + ";
    cout << "InnerFormula(" << yz << ")";
    cout << endl;

    // Returning the calculation result
    return x * yz;
}

int InnerFormula(int y, int z)
{
    // For logging purpose only
    cout << "Calculate " << y << " * ";
    cout << z << endl;

    // Returning the calculation result
    return y * z;
}

auto main() -> int
{
    cout << "[strict.cpp]" << endl;

    // Initializing three int variables
    // for the calculation
    int x = 4;
    int y = 3;
    int z = 2;

    // Calculating the expression
    cout << "Calculate " << x <<" + ";
    cout << "(" << y << " * " << z  << ")";
    cout << endl;
    int result = OuterFormula(x, InnerFormula(y, z));

    // For logging purpose only
    cout << x << " + ";
    cout << "(" << y << " * " << z  << ")";
    cout << " = " << result << endl;

    return 0;
}
