/* pure_function_1.cpp */
#include <iostream>

using namespace std;

float circleArea(float r)
{
    return 3.14 * r * r;
}

auto main() -> int
{
    cout << "[pure_function_1.cpp]" << endl;

    // Initializing a float variable
    float f = 2.5f;

    // Invoking the circleArea() function
    // passing the f variable five times
    for(int i = 1; i <= 5; ++i)
    {
        cout << "Invocation " << i << " -> ";
        cout << "Result of circleArea(" << f << ") = ";
        cout << circleArea(f) << endl;
    }

    return 0;
}
