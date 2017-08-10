/* conditionmeta.cpp */
#include <iostream>

using namespace std;

// Function that will run
// if the condition is TRUE
void TrueStatement()
{
    cout << "True Statement is run." << endl;
}

// Function that will run
// if the condition is FALSE
void FalseStatement()
{
    cout << "False Statement is run." << endl;
}

// Defining IfElse template
template<bool predicate>
class IfElse
{
};

// Defining template for TRUE condition
// passed to 'predicate' parameter
template<>
class IfElse<true>
{
public:
    static inline void func()
    {
        TrueStatement();
    }
};

// Defining template for FALSE condition
// passed to 'predicate' parameter
template<>
class IfElse<false>
{
public:
    static inline void func()
    {
        FalseStatement();
    }
};

auto main() -> int
{
    cout << "[conditionmeta.cpp]" << endl;

    // Consuming IfElse template
    IfElse<(2 + 3 == 5)>::func();

    return 0;
}
