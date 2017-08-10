/* Customer.cpp - Step02 */
#include <stdexcept>
#include "Customer.h"

using namespace std;

vector<Customer> Customer::registeredCustomers;

string Customer::GetActiveCustomerNames(
    Customer customer) const
{
    return customer.name;
}

string Customer::GetActiveCustomerAddresses(
    Customer customer) const
{
    return customer.address;
}

string Customer::GetActiveCustomerPhoneNumbers(
    Customer customer) const
{
    return customer.phoneNumber;
}

string Customer::GetActiveCustomerEmails(
    Customer customer) const
{
    return customer.email;
}

vector<string> Customer::GetActiveCustomerByFunctionField(
    function<string(const Customer&, Customer)> funcField)
{
    vector<string> returnList;

    Customer c;

    for (auto customer : Customer::registeredCustomers)
    {
        if (customer.isActive)
        {
            returnList.push_back(
                funcField(c, customer));
        }
    }
    return returnList;
}

vector<string> Customer::GetActiveCustomerByField(
    const string &field)
{
    function<string(const Customer&, Customer)> funct;

    if (field == "name")
    {
        funct = &Customer::GetActiveCustomerNames;
    }
    else if (field == "address")
    {
        funct = &Customer::GetActiveCustomerAddresses;
    }
    else if (field == "phoneNumber")
    {
        funct = &Customer::GetActiveCustomerPhoneNumbers;
    }
    else if (field == "email")
    {
        funct = &Customer::GetActiveCustomerEmails;
    }
    else
    {
        throw invalid_argument("Unknown field");
    }

    return GetActiveCustomerByFunctionField(funct);
}
