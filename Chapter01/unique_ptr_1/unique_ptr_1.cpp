/* unique_ptr_1.cpp */
#include <memory>
#include <iostream>

using namespace std;

struct BodyMass
{
    int Id;
    float Weight;

    BodyMass(int id, float weight) :
        Id(id),
        Weight(weight)
    {
        cout << "BodyMass is constructed!" << endl;
        cout << "Id = " << Id << endl;
        cout << "Weight = " << Weight << endl;
    }

    ~BodyMass()
    {
        cout << "BodyMass is destructed!" << endl;
    }
};

auto main() -> int
{
    cout << "[unique_ptr_1.cpp]" << endl;

    auto myWeight = make_unique<BodyMass>(1, 165.3f);

    cout << endl << "Doing something!!!" << endl << endl;

    return 0;
}
