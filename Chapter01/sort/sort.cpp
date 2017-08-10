/* sort.cpp */
#include <vector>
#include <algorithm>
#include <iostream>

bool comparer(int a, int b)
{
    return (a > b);
}

auto main() -> int
{
    std::cout << "[sort.cpp]" << std::endl;

    // Initializing a vector containing several integer elements
    std::vector<int> vect = { 20, 43, 11, 78, 5, 96 };

    // Displaying the original elements of the vector
    std::cout << "Original Data    : ";
    for (auto v : vect)
        std::cout << v << " ";
    std::cout << std::endl;

    // Sorting the vector element ascending
    std::sort(std::begin(vect), std::end(vect));

    // Displaying the ascending sorted elements
    // of the vector
    std::cout << "Ascending Sorted : ";
    for (auto v : vect)
        std::cout << v << " ";
    std::cout << std::endl;

    // Sorting the vector element descending
    // using comparer
    std::sort(std::begin(vect), std::end(vect), comparer);

    // Displaying the descending sorted elements
    // of the vector
    std::cout << "Descending Sorted: ";
    for (auto v : vect)
        std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}
