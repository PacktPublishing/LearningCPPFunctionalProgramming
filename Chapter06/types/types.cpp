/* types.cpp */
#include <iostream>

using namespace std;

// Defining a data type
// in template
template<typename T>
struct datatype
{
    using type = T;
};

auto main() -> int
{
    cout << "[types.cpp]" << endl;

    // Selecting a data type in compile time
    using t = typename datatype<int>::type;

    // Using the selected data type
    t myVar = 123;

    // Displaying the selected data type
    cout << "myVar = " << myVar;

    return 0;
}
