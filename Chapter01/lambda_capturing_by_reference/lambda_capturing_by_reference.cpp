/* lambda_capturing_by_reference.cpp */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

auto main() -> int
{
    cout << "[lambda_capturing_by_reference.cpp]" << endl;

    // Initializing a vector containing integer element
    vector<int> vect;
    for (int i = 0; i < 10; ++i)
        vect.push_back(i);

    // Displaying the elements of vect
    cout << "Original Data:" << endl;
    for_each(
             begin(vect),
             end(vect),
             [](int n){
                cout << n << " ";
            });
    cout << endl;

    // Initializing two variables
    int a = 1;
    int b = 1;

    // Capturing value from the two variables
    // and mutate them
    for_each(
             begin(vect),
             end(vect),
             [&a, &b](int& x){
                const int old = x;
                x *= 2;
                a = b;
                b = old;
            });

    // Displaying the elements of vect
    cout << "Squared Data:" << endl;
    for_each(
             begin(vect),
             end(vect),
             [](int n) {
                cout << n << " ";
            });
    cout << endl << endl;

    // Displaying value of variable a and b
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
