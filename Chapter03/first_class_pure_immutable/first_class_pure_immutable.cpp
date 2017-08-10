/* first_class_pure_immutable.cpp */
#include <iostream>
#include <functional>

using namespace std;

// MyValue class stores the value
class MyValue
{
public:
    const int value;
    MyValue(int v) : value(v)
    {
    }
};

// MyFunction class stores the methods
class MyFunction
{
public:
    const int x, y;

    MyFunction(int _x, int _y) :
        x(_x), y(_y)
    {
    }

    MyValue addition() const
    {
        return MyValue(x + y);
    }

    MyValue subtraction() const
    {
        return MyValue(x - y);
    }

    MyValue multiplication() const
    {
        return MyValue(x * y);
    }

    MyValue division() const
    {
        return MyValue(x / y);
    }
};

auto main() -> int
{
    cout << "[first_class_pure_immutable.cpp]" << endl;

    // Setting the initial value
    // for MyFunction class constructor
    int a = 100;
    int b = 10;

    // Displaying initial value
    cout << "Initial value" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << endl;

    // Constructing the MyFunction class
    MyFunction func(a, b);

    // Generating wrapper for each function
    // in the MyFunction class
    // so it will be the first-class function
    auto callableAdd = mem_fn(&MyFunction::addition);
    auto callableSub = mem_fn(&MyFunction::subtraction);
    auto callableMul = mem_fn(&MyFunction::multiplication);
    auto callableDiv = mem_fn(&MyFunction::division);

    // Invoking the functions
    auto value1 = callableAdd(func);
    auto value2 = callableSub(func);
    auto value3 = callableMul(func);
    auto value4 = callableDiv(func);

    // Displaying result
    cout << "The result" << endl;
    cout << "addition = " << value1.value << endl;
    cout << "subtraction = " << value2.value << endl;
    cout << "multiplication = " << value3.value << endl;
    cout << "division = " << value4.value << endl;

    return 0;
}
