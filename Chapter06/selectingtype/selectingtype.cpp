/* selectingtype.cpp */
#include <iostream>

using namespace std;

// Defining IfElseDataType template
template<
    bool predicate,
    typename TrueType,
    typename FalseType>
struct IfElseDataType
{
};

// Defining template for TRUE condition
// passed to 'predicate' parameter
template<
    typename TrueType,
    typename FalseType>
struct IfElseDataType<
    true,
    TrueType,
    FalseType>
{
    typedef TrueType type;
};

// Defining template for FALSE condition
// passed to 'predicate' parameter
template<
    typename TrueType,
    typename FalseType>
struct IfElseDataType<
    false,
    TrueType,
    FalseType>
{
    typedef FalseType type;
};

auto main() -> int
{
    cout << "[selectingtype.cpp]" << endl;

    // Consuming template and passing
    // 'SHRT_MAX == 2147483647'
    // It will be FALSE
    // since the maximum value of short
    // is 32767
    // so the data type for myVar
    // will be 'int'
    IfElseDataType<
        SHRT_MAX == 2147483647,
        short,
        int>::type myVar;

    // Assigning myVar to maximum value
    // of 'short' type
    myVar = 2147483647;

    // Displaying the data type of myVar
    cout << "myVar has type ";
    cout << typeid(myVar).name() << endl;

    return 0;
}
