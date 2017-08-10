/* mutableemployee.h */
#ifndef __MUTABLEEMPLOYEE_H__
#define __MUTABLEEMPLOYEE_H__

#include <string>

class MutableEmployee
{
private:
    int m_id;
    std::string m_firstName;
    std::string m_lastName;
    double m_salary;

public:
    MutableEmployee(
        int id,
        const std::string& firstName,
        const std::string& lastName,
        const double& salary);
    MutableEmployee();

    void SetId(const int id);
    void SetFirstName(
        const std::string& FirstName);
    void SetLastName(
        const std::string& LastName);
    void SetSalary(
        const double& Salary);

    int Id() const {return m_id;}
    std::string FirstName() const {return m_firstName;}
    std::string LastName() const {return m_lastName;}
    double Salary() const {return m_salary;}
};

#endif // End of __MUTABLEEMPLOYEE_H__
