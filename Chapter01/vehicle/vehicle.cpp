#include "vehicle.h"

using namespace std;

// Constructor with default value for
// m_vehicleType and m_totalOfWheel
Vehicle::Vehicle() : m_totalOfWheel(0)
{
}

// Constructor with user-defined value for
// m_vehicleType and m_totalOfWheel
Vehicle::Vehicle(
                const string &type,
                int wheel) :
    m_vehicleType(type),
    m_totalOfWheel(wheel)
{
}

// Destructor
Vehicle::~Vehicle()
{
}
