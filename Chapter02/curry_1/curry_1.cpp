/* curry_1.cpp */

#include <functional>
#include <iostream>

using namespace std;

// Variadic template for currying
template<typename Func, typename... Args>
auto curry(Func func, Args... args)
{
    return [=](auto... lastParam)
    {
        return func(args..., lastParam...);
    };
}

int areaOfRectangle(int length, int width)
{
    return length * width;
}

auto main() -> int
{
    cout << "[curry_1.cpp]" << endl;

    // Currying the areaOfRectangle() function
    auto length5 = curry(areaOfRectangle, 5);

    // Invoking the curried function
    cout << "Curried with spesific length = 5" << endl;
    for(int i = 0; i <= 5; ++i)
    {
        cout << "length5(" << i << ") = ";
        cout << length5(i) << endl;
    }

    return 0;
}
