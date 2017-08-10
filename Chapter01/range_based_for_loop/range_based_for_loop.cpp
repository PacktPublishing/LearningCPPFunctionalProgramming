/* range_based_for_loop.cpp */
#include <iostream>

auto main() -> int
{
    std::cout << "[range_based_for_loop.cpp]" << std::endl;

    // Declaring an array
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Displaying the array elements
    // using non-member begin() and end()
    std::cout << "Displaying array element using range-based for loop";
    std::cout << std::endl;
    for (auto a : arr)
        std::cout << a << " ";
    std::cout << std::endl;

    return 0;
}
