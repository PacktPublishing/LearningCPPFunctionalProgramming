/* curry_2.cpp */

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

int volumeOfRectanglular(
    int length,
    int width,
    int height)
{
    return length * width * height;
}

auto main() -> int
{
    cout << "[curry_2.cpp]" << endl;

    // Currying the volumeOfRectanglular() function
    auto length5width4 = curry(
        volumeOfRectanglular, 5, 4);

    // Invoking the curried function
    cout << "Curried with spesific data:" << endl;
    cout << "length = 5, width 4" << endl;
    for(int i = 0; i <= 5; ++i)
    {
        cout << "length5width4(" << i << ") = ";
        cout << length5width4(i) << endl;
    }

    return 0;
}
