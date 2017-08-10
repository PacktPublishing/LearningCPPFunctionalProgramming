/* Customer.h - Step02 */
#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include <string>
#include <vector>
#include <functional>

class Customer
{
private:
    std::string GetActiveCustomerNames(
        Customer customer) const;
    std::string GetActiveCustomerAddresses(
        Customer customer) const;
    std::string GetActiveCustomerPhoneNumbers(
        Customer customer) const;
    std::string GetActiveCustomerEmails(
        Customer customer) const;

public:
    static std::vector<Customer> registeredCustomers;
    int id = 0;
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::string email;
    bool isActive = true;

    std::vector<std::string> GetActiveCustomerByField(
        const std::string &field);

    std::vector<std::string> GetActiveCustomerByFunctionField(
        std::function<std::string(const Customer&, Customer)>
            funcField);
};
#endif //#ifndef __CUSTOMER_H__
