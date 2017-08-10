/* switchmeta.cpp */
#include <iostream>

using namespace std;

// Function to find out
// the square of an int
int Square(int a)
{
    return a * a;
}

// Defining template for
// default output
// for any input value
template<int val>
class SwitchTemplate
{
public:
    static inline int func()
    {
        return Square(0);
    }
};

// Defining template for
// specific input value
// 'val' = 1
template<>
class SwitchTemplate<1>
{
public:
    static inline int func()
    {
        return Square(1);
    }
};

// Defining template for
// specific input value
// 'val' = 2
template<>
class SwitchTemplate<2>
{
public:
    static inline int func()
    {
        return Square(2);
    }
};

auto main() -> int
{
    cout << "[switchmeta.cpp]" << endl;

    // Defining constant expression
    const int i = 2;

    // Consuming the SwitchTemplate template
    int output = SwitchTemplate<i>::func();

    // Displaying the result
    cout << "The result is " << output << endl;

    return 0;
}
