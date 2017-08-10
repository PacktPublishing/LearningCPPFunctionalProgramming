/* immutableemployee.h */
#ifndef __IMMUTABLEEMPLOYEE_H__
#define __IMMUTABLEEMPLOYEE_H__

#include <string>

class ImmutableEmployee
{
private:
    int m_id;
    std::string m_firstName;
    std::string m_lastName;
    double m_salary;

public:
    ImmutableEmployee(
        const int id,
        const std::string& firstName,
        const std::string& lastName,
        const double& _salary);
    ImmutableEmployee();

    const int Id() const {
        return m_id;
    }

    const std::string& FirstName() const {
        return m_firstName;
    }

    const std::string& LastName() const {
        return m_lastName;
    }

    const double Salary() const {
        return m_salary;
    }

    const ImmutableEmployee SetId(
                                  const int id) const {
        return ImmutableEmployee(
            id, m_firstName, m_lastName, m_salary);
    }

    const ImmutableEmployee SetFirstName(
                                         const std::string& firstName) const {
        return ImmutableEmployee(
            m_id, firstName, m_lastName, m_salary);
    }

    const ImmutableEmployee SetLastName(
                                        const std::string& lastName) const {
        return ImmutableEmployee(
            m_id, m_firstName, lastName, m_salary);
    }

    const ImmutableEmployee SetSalary(
                                      const double& salary) const {
        return ImmutableEmployee(
            m_id, m_firstName, m_lastName, salary);
    }
};

#endif // End of __IMMUTABLEEMPLOYEE_H__
