/* immutableemployee.cpp */
#include "immutableemployee.h"

using namespace std;

ImmutableEmployee::ImmutableEmployee() :
    m_id(0),
    m_salary(0.0)
{
}

ImmutableEmployee::ImmutableEmployee(
    const int id,
    const string& firstName,
    const string& lastName,
    const double& salary) :
        m_id(id),
        m_firstName(firstName),
        m_lastName(lastName),
        m_salary(salary)
{
}
