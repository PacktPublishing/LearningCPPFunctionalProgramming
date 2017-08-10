/* Customer.h - Step01 */
#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include <string>
#include <vector>

class Customer
{
public:
    static std::vector<Customer> registeredCustomers;
    int id = 0;
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::string email;
    bool isActive = true;

    std::vector<std::string> GetActiveCustomerNames();
    std::vector<std::string> GetActiveCustomerAddresses();
    std::vector<std::string> GetActiveCustomerPhoneNumbers();
    std::vector<std::string> GetActiveCustomerEmails();
};
#endif // __CUSTOMER_H__
