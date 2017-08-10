/* fibonaccimeta.cpp */
#include <iostream>

using namespace std;

// Defining Fibonacci template
// to calculate the Fibonacci sequence
template <int number>
struct Fibonacci
{
    enum
    {
        value =
            Fibonacci<number - 1>::value +
            Fibonacci<number - 2>::value
    };
};

// Defining template for
// specific input value
// 'number' = 1
template <>
struct Fibonacci<1>
{
    enum
    {
        value = 1
    };
};

// Defining template for
// specific input value
// 'number' = 0
template <>
struct Fibonacci<0>
{
    enum
    {
        value = 0
    };
};

auto main() -> int
{
    cout << "[fibonaccimeta.cpp]" << endl;

    // Displaying the compile-time constant
    cout << "Getting compile-time constant:";
    cout << endl;
    cout << "Fibonacci(25) = ";
    cout << Fibonacci<25>::value;
    cout << endl;

    return 0;
}
