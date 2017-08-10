/* im_pure_function_1.cpp */
#include <iostream>

using namespace std;

// Initializing a global variable
float phi = 3.14f;

float circleArea(float r)
{
    return phi * r * r;
}

auto main() -> int
{
    cout << "[im_pure_function_1.cpp]" << endl;

    // Initializing a float variable
    float f = 2.5f;

    // Involving the global variable
    // in the calculation
    for(int i = 1; i <= 5; ++i)
    {
        cout << "Invocation " << i << " -> ";
        cout << "Result of circleArea(" << f << ") = ";
        cout << circleArea(f) << endl;
    }

    return 0;
}
