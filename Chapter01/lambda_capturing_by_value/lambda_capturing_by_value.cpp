/* lambda_capturing_by_value.cpp */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

auto main() -> int
{
    cout << "[lambda_capturing_by_value.cpp]" << endl;

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
    int a = 2;
    int b = 8;

    // Capturing value explicitly from the two variables
    cout << "Printing elements between " << a;
    cout << " and " << b << " explicitly [a,b]:" << endl;
    for_each(
             begin(vect),
             end(vect),
             [a,b](int n){
                if (n >= a && n <= b)
                    cout << n << " ";
            });
     cout << endl;

     // Modifying variable a and b
     a = 3;
     b = 7;

     // Capturing value implicitly from the two variables
     cout << "printing elements between " << a;
     cout << " and " << b << " implicitly[=]:" << endl;
     for_each(
              begin(vect),
              end(vect),
              [=](int n){
                if (n >= a && n <= b)
                cout << n << " ";
            });
     cout << endl;

     return 0;
}
