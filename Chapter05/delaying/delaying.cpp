/* delaying.cpp */
#include <iostream>
#include <functional>

using namespace std;

template<class T> class Delay
{
private:
    function<T()> m_func;

public:
    Delay(
        function<T()> func)
        : m_func(func)
    {
    }

    T Fetch()
    {
        return m_func();
    }
};

auto main() -> int
{
    cout << "[delaying.cpp]" << endl;

    // Initializing several int variables
    int a = 10;
    int b = 5;

    cout << "Constructing Delay<> named multiply";
    cout << endl;
    Delay<int> multiply([a, b]()
    {
        cout << "Delay<> named multiply";
        cout << " is constructed." << endl;
        return a * b;
    });

    cout << "Constructing Delay<> named division";
    cout << endl;
    Delay<int> division([a, b]()
    {
        cout << "Delay<> named division ";
        cout << "is constructed." << endl;
        return a / b;
    });

    cout << "Invoking Fetch() method in ";
    cout << "multiply instance." << endl;
    int c = multiply.Fetch();

    cout << "Invoking Fetch() method in ";
    cout << "division instance." << endl;
    int d = division.Fetch();

    // Displaying the result
    cout << "The result of a * b = " << c << endl;
    cout << "The result of a / b = " << d << endl;

    return 0;
}
