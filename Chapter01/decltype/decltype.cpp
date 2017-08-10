/* decltype.cpp */
#include <iostream>

// Creating template
template<typename I, typename J>
auto add(I i, J j) -> decltype(i + j)
{
    return i + j;
}

auto main() -> int
{
    std::cout << "[decltype.cpp]" << std::endl;

    // Consuming the template
    auto d = add<int, double>(2, 2.5);

    // Displaying the preceding variables' type
    std::cout << "result of 2 + 2.5: " << d << std::endl;

    return 0;
}
