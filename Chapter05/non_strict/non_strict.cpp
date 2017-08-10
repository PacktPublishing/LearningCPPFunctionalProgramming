/* non_strict.cpp */
#include <functional>
#include <iostream>

using namespace std;

int OuterFormulaNonStrict(
    int x,
    int y,
    int z,
    function<int(int, int)> yzFunc)
{
    // For logging purpose only
    cout << "Calculate " << x << " + ";
    cout << "InnerFormula(" << y << ", ";
    cout << z << ")" << endl;

    // Returning the calculation result
    return x * yzFunc(y, z);
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
    cout << "[non_strict.cpp]" << endl;

    // Initializing three int variables
    // for the calculation
    int x = 4;
    int y = 3;
    int z = 2;

    // Calculating the expression
    cout << "Calculate " << x <<" + ";
    cout << "(" << y << " * " << z  << ")";
    cout << endl;
    int result = OuterFormulaNonStrict(x, y, z, InnerFormula);

    // For logging purpose only
    cout << x << " + ";
    cout << "(" << y << " * " << z  << ")";
    cout << " = " << result << endl;

    return 0;
}
