/* auto.cpp */
#include <iostream>
#include <typeinfo>

auto main() -> int
{
    std::cout << "[auto.cpp]" << std::endl;

    // Creating several auto-type variables
    auto a = 1;
    auto b = 1.0;
    auto c = a + b;
    auto d = {b, c};

    // Displaying the preceding variables' type
    std::cout << "type of a: " << typeid(a).name() << std::endl;
    std::cout << "type of b: " << typeid(b).name() << std::endl;
    std::cout << "type of c: " << typeid(c).name() << std::endl;
    std::cout << "type of d: " << typeid(d).name() << std::endl;
    return 0;
}
