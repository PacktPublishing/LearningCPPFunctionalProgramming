/* vector.cpp */
#include <vector>
#include <iostream>

auto main() -> int
{
    std::cout << "[vector.cpp]" << std::endl;

    // Initializing a vector containing three integer elements
    std::vector<int> vect = { 0, 1, 2 };

    // Displaying the original elements of the vector
    std::cout << "Original Data  : ";
    for (auto v : vect)
        std::cout << v << " ";
    std::cout << std::endl;

    // Adding two new data
    vect.push_back(3);
    vect.push_back(4);

    // Displaying the elements of the new vector
    // and reverse the order
    std::cout << "New Data Added : ";
    for (auto v : vect)
        std::cout << v << " ";
    std::cout << std::endl;

    // Modifying the content of
    // the 2nd and 4th element of the vector
    vect.at(2) = 5;
    vect.at(4) = 6;

    // Displaying the altered array elements
    std::cout << "Manipulate Data: ";
    for (auto v : vect)
        std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}
