/* fold_1.cpp */
#include <vector>
#include <numeric>
#include <functional>
#include <iostream>

using namespace std;

auto main() -> int
{
    cout << "[fold_1.cpp]" << endl;

    // Initializing a vector containing integer elements
    vector<int> numbers = {0, 1, 2, 3, 4};

    // Calculating the sum of the value
    // in the vector
    auto foldl = accumulate(
        begin(numbers),
        end(numbers),
        0,
        std::plus<int>());

    // Calculating the sum of the value
    // in the vector
    auto foldr = accumulate(
        rbegin(numbers),
        rend(numbers),
        0,
        std::plus<int>());

    // Displaying the calculating result
    cout << "foldl result = " << foldl << endl;
    cout << "foldr result = " << foldr << endl;

    return 0;
}
