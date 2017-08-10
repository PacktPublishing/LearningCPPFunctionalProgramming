/* lambda_tiny_func.cpp */
#include <vector>
#include <algorithm>
#include <iostream>
#include "../vehicle/vehicle.h"

using namespace std;

auto main() -> int
{
    cout << "[lambda_tiny_func.cpp]" << endl;

    // Initializing several Vehicle instances
    Vehicle car("car", 4);
    Vehicle motorcycle("motorcycle", 2);
    Vehicle bicycle("bicycle", 2);
    Vehicle bus("bus", 6);

    // Assigning the preceding Vehicle instances to a vector
    vector<Vehicle> vehicles = { car, motorcycle, bicycle, bus };

    // Displaying the elements of the vector
    // using Lambda expression
    cout << "All vehicles:" << endl;
    for_each(
             begin(vehicles),
             end(vehicles),
             [](const Vehicle &vehicle){
                 cout << vehicle.GetType() << endl;
            });

    return 0;
}
