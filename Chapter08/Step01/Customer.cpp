/* Customer.cpp - Step01 */
#include "Customer.h"

using namespace std;

vector<Customer> Customer::registeredCustomers;

vector<string> Customer::GetActiveCustomerNames()
{
    vector<string> returnList;
    for (auto &customer : Customer::registeredCustomers)
    {
        if (customer.isActive)
        {
            returnList.push_back(customer.name);
        }
    }
    return returnList;
}

vector<string> Customer::GetActiveCustomerAddresses()
{
    vector<string> returnList;
    for (auto &customer : Customer::registeredCustomers)
    {
        if (customer.isActive)
        {
            returnList.push_back(customer.address);
        }
    }
    return returnList;
}

vector<string> Customer::GetActiveCustomerPhoneNumbers()
{
    vector<string> returnList;
    for (auto &customer : Customer::registeredCustomers)
    {
        if (customer.isActive)
        {
            returnList.push_back(customer.phoneNumber);
        }
    }
    return returnList;
}

vector<string> Customer::GetActiveCustomerEmails()
{
    vector<string> returnList;
    for (auto &customer : Customer::registeredCustomers)
    {
        if (customer.isActive)
        {
            returnList.push_back(customer.email);
        }
    }
    return returnList;
}
