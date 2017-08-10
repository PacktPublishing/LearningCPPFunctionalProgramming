/* unique_ptr_3.cpp */
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

unique_ptr<BodyMass> GetBodyMass()
{
    return make_unique<BodyMass>(1, 165.3f);
}

unique_ptr<BodyMass> UpdateBodyMass(
    unique_ptr<BodyMass> bodyMass)
{
    bodyMass->Weight += 1.0f;
    return bodyMass;
}

auto main() -> int
{
    cout << "[unique_ptr_3.cpp]" << endl;

    auto myWeight = GetBodyMass();

    cout << "Current weight = " << myWeight->Weight << endl;

    myWeight = UpdateBodyMass(move(myWeight));

    cout << "Updated weight = " << myWeight->Weight << endl;

    return 0;
}
