/* lambda_returning_value.cpp */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

auto main() -> int
{
    cout << "[lambda_returning_value.cpp]" << endl;

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

    // Creating another vect2 vector
    vector<int> vect2;
    // Resize the size of vect2 exactly same with vect
    vect2.resize(vect.size());
    // Doubling the elements of vect and store to vect2
    transform(
              begin(vect),
              end(vect),
              begin(vect2),
              [](int n) {
                return n * n;
            });

    // Displaying the elements of vect2
    cout << "Squared Data:" << endl;
    for_each(
             begin(vect2),
             end(vect2),
             [](int n) {
                cout << n << " ";
            });
    cout << endl;

    // Creating another vect3 vector
    vector<double> vect3;
    // Resize the size of vect3 exactly same with vect
    vect3.resize(vect.size());
    // Finding the average of the elements of vect
    // and store to vect2
    transform(
              begin(vect2),
              end(vect2),
              begin(vect3),
              [](int n) -> double {
                return n / 2.0;
            });

    // Displaying the elements of vect3
    cout << "Average Data:" << endl;
    for_each(
             begin(vect3),
             end(vect3),
             [](double d) {
                cout << d << " ";
            });
    cout << endl;

    return 0;
}
