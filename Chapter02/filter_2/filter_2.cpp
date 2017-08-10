/* filter_2.cpp */
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
    cout << "[filter_2.cpp]" << endl;

    // Initializing a vector containing integer elements
    vector<int> numbers;
    for (int i = 0; i < 20; ++i)
        numbers.push_back(i);

    // Displaying the elements of numbers
    cout << "The original numbers: " << endl;
    copy(
        begin(numbers),
        end(numbers),
        ostream_iterator<int>(cout, " "));
    cout << endl;

    // Declaring a vector containing int elements
    vector<int> nonPrimes;

    // Filtering the vector
    remove_copy_if(
        numbers.begin(),
        numbers.end(),
        back_inserter(nonPrimes),
        [](int n) {
            if(n < 2){
                return (n != 0) ? true : false;}
            else {
                for (int j = 2; j < n; ++j){
                    if (n % j == 0) {
                        return false;}
            }

            return true;
        }});

    // Displaying the elements of nonPrimes
    // using copy() function
    cout << "The non-primes numbers: " << endl;
    copy(
        begin(nonPrimes),
        end(nonPrimes),
        ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
