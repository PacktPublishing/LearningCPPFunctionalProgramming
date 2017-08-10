/* mutableemployee.cpp */
#include "mutableemployee.h"

using namespace std;

MutableEmployee::MutableEmployee() :
    m_id(0),
    m_salary(0.0)
{
}

MutableEmployee::MutableEmployee(
    int id,
    const string& firstName,
    const string& lastName,
    const double& salary) :
        m_id(id),
        m_firstName(firstName),
        m_lastName(lastName),
        m_salary(salary)
{
}

void MutableEmployee::SetId(const int id)
{
    m_id = id;
}

void MutableEmployee::SetFirstName(
    const std::string& FirstName) {
    m_firstName = FirstName;
}

void MutableEmployee::SetLastName(
    const std::string& LastName) {
    m_lastName = LastName;
}

void MutableEmployee::SetSalary(
    const double& Salary) {
    m_salary = Salary;
}
