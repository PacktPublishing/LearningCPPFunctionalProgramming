/* begin_end.cpp */
#include <iostream>

auto main() -> int
{
    std::cout << "[begin_end.cpp]" << std::endl;

    // Declaring an array
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // Displaying the array elements
    // using conventional for-loop
    std::cout << "Displaying array element using conventional for-loop";
    std::cout << std::endl;
    for (unsigned int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    // Displaying the array elements
    // using non-member begin() and end()
    std::cout << "Displaying array element using non-member begin() and end()";
    std::cout << std::endl;
    for (auto i = std::begin(arr); i != std::end(arr); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    return 0;
}
