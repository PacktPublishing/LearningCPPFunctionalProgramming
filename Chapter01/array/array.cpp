/* array.cpp */
#include <array>
#include <iostream>

auto main() -> int
{
    std::cout << "[array.cpp]" << std::endl;

    // Initializing an array containing five integer elements
    std::array<int, 10> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // Displaying the original elements of the array
    std::cout << "Original Data   : ";
    for(auto a : arr)
        std::cout << a << " ";
    std::cout << std::endl;

    // Modifying the content of
    // the 1st and 3rd element of the array
    arr[1] = 9;
    arr[3] = 7;

    // Displaying the altered array elements
    std::cout << "Manipulated Data: ";
    for(auto a : arr)
        std::cout << a << " ";
    std::cout << std::endl;

    return 0;
}
