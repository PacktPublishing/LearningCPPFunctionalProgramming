/* loopmeta.cpp */
#include <iostream>

using namespace std;

// Function for printing
// given number
void PrintNumber(int i)
{
    cout << i << "\t";
}

// Defining template for printing number
// passing to its 'limit' parameter
// It's only run
// if the 'limit' has not been reached
template<int limit>
class DoWhile
{
private:
    enum
    {
        run = (limit-1) != 0
    };

public:
    static inline void func()
    {
        PrintNumber(limit);
        DoWhile<run == true ? (limit-1) : 0>
            ::func();
    }
};

// Defining template for doing nothing
// when the 'limit' reaches 0
template<>
class DoWhile<0>
{
public:
    static inline void func()
    {
    }
};

auto main() -> int
{
    cout << "[loopmeta.cpp]" << endl;

    // Defining a constant variable
    const int i = 100;

    // Looping to print out
    // the numbers below i variable
    // by consuming the DoWhile
    cout << "List of numbers between 100 and 1";
    cout << endl;
    DoWhile<i>::func();
    cout << endl;

    return 0;
}
