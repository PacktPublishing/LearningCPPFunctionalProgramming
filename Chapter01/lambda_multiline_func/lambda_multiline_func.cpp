/* lambda_multiline_func.cpp */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

auto main() -> int
{
    cout << "[lambda_multiline_func.cpp]" << endl;

    // Initializing a vector containing integer element
    vector<int> vect;
    for (int i = 0; i < 10; ++i)
        vect.push_back(i);

    // Displaying whether or not the element is prime number
    for_each(
             begin(vect),
             end(vect),
             [](int n) {
                cout << n << " is";
                if(n < 2)
                {
                    if(n == 0)
                    cout << " not";
                }
                else
                {
                    for (int j = 2; j < n; ++j)
                    {
                        if (n % j == 0)
                        {
                            cout << " not";
                            break;
                        }
                    }
                }

                cout << " prime number" << endl;
            });

    return 0;
}
