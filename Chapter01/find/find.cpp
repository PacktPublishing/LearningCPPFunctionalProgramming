/* find.cpp */
#include <vector>
#include <algorithm>
#include <iostream>
#include "../vehicle/vehicle.h"

using namespace std;

bool TwoWheeled(const Vehicle &vehicle)
{
    return vehicle.GetNumOfWheel() == 2 ?
        true : false;
 }

auto main() -> int
{
    cout << "[find.cpp]" << endl;

    // Initializing several Vehicle instances
    Vehicle car("car", 4);
    Vehicle motorcycle("motorcycle", 2);
    Vehicle bicycle("bicycle", 2);
    Vehicle bus("bus", 6);

    // Assigning the preceding Vehicle instances to a vector
    vector<Vehicle> vehicles = { car, motorcycle, bicycle, bus };

    // Displaying the elements of the vector
    cout << "All vehicles:" << endl;;
    for (auto v : vehicles)
        std::cout << v.GetType() << endl;
    cout << endl;

    // Displaying the elements of the vector
    // which are the two-wheeled vehicles
    cout << "Two-wheeled vehicle(s):" << endl;;
    auto tw = find_if(
                      begin(vehicles),
                      end(vehicles),
                      TwoWheeled);
    while (tw != end(vehicles))
    {
        cout << tw->GetType() << endl ;
        tw = find_if(++tw, end(vehicles), TwoWheeled);
    }
    cout << endl;

    // Displaying the elements of the vector
    // which are not the two-wheeled vehicles
    cout << "Not the two-wheeled vehicle(s):" << endl;;
    auto ntw = find_if_not(begin(vehicles),
                           end(vehicles),
                           TwoWheeled);
    while (ntw != end(vehicles))
    {
        cout << ntw->GetType() << endl ;
        ntw = find_if_not(++ntw, end(vehicles), TwoWheeled);
    }

    return 0;
}
