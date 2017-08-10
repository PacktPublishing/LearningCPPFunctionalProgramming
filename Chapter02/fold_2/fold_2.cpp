/* fold_2.cpp */
#include <vector>
#include <numeric>
#include <functional>
#include <iostream>

using namespace std;

// Function for logging the flow
int addition(const int& x, const int& y)
{
    cout << x << " + " << y << endl;
    return x + y;
}

auto main() -> int
{
    cout << "[fold_2.cpp]" << endl;

    // Initializing a vector containing integer elements
    vector<int> numbers = {0, 1, 2, 3, 4};

    // Calculating the sum of the value
    // in the vector
    // from left to right
    cout << "foldl" << endl;
    auto foldl = accumulate(
        begin(numbers),
        end(numbers),
        0,
        addition);

    // Calculating the sum of the value
    // in the vector
    // from right to left
    cout << endl << "foldr" << endl;
    auto foldr = accumulate(
        rbegin(numbers),
        rend(numbers),
        0,
        addition);

    cout << endl;

    // Displaying the calculating result
    cout << "foldl result = " << foldl << endl;
    cout << "foldr result = " << foldr << endl;

    return 0;
}
