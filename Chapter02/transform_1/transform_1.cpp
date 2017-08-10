/* transform_1.cpp */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

auto main() -> int
{
    cout << "[transform_1.cpp]" << endl;

    // Initializing a vector containing integer elements
    vector<int> v1;
    for (int i = 0; i < 5; ++i)
        v1.push_back(i);

    // Creating another v2 vector
    vector<int> v2;
    // Resizing the size of v2 exactly same with v1
    v2.resize(v1.size());

    // Transforming the element inside the vector
    transform (
        begin(v1),
        end(v1),
        begin(v2),
        [](int i){
            return i * i;});

    // Displaying the elements of v1
    std::cout << "v1 contains:";
    for (auto v : v1)
        std::cout << " " << v;
    std::cout << endl;

    // Displaying the elements of v2
    std::cout << "v2 contains:";
    for (auto v : v2)
        std::cout << " " << v;
    std::cout << endl;

    return 0;
}
