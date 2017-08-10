/* const.cpp */
#include <iostream>

using namespace std;

// My Age class will store an age value
class MyAge
{
public:
    const int age;
    MyAge(const int initAge = 20) :
        age(initAge)
    {
    }
};

auto main() -> int
{
    cout << "[const.cpp]" << endl;

    // Initializing several MyAge variables
    MyAge AgeNow, AgeLater(8);

    // Displaying age property in AgeNow instance
    cout << "My current age is ";
    cout << AgeNow.age << endl;

    // Displaying age property in AgeLater instance
    cout << "My age in eight years later is ";
    cout << AgeLater.age << endl;

    return 0;
}
