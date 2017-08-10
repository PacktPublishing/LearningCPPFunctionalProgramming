#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include <string>

class Vehicle
{
    private:
        std::string m_vehicleType;
        int m_totalOfWheel;

    public:
        Vehicle(
                const std::string &type,
                int wheel);
        Vehicle();
        ~Vehicle();

        std::string GetType() const {return m_vehicleType;}
        int GetNumOfWheel() const {return m_totalOfWheel;}
};

#endif // __VEHICLE_H__
