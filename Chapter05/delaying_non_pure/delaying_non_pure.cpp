/* delaying_non_pure.cpp */
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
    cout << "[delaying_non_pure.cpp]" << endl;

    // Initializing several int variables
    int a = 10;
    int b = 5;
    int multiplexer = 0;

    // Constructing Delay<> named multiply_impure
    Delay<int> multiply_impure([&]()
    {
        return multiplexer * a * b;
    });

    // Invoking Fetch() method in multiply_impure instance
    // multiple times
    for (int i = 0; i < 5; ++i)
    {
        ++multiplexer;
        cout << "Multiplexer = " << multiplexer << endl;
        cout << "a * b = " << multiply_impure.Fetch();
        cout << endl;
    }

    return 0;
}
