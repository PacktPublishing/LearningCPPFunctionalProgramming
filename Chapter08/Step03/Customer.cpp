/* Customer.cpp - Step03 */
#include "Customer.h"

using namespace std;

vector<Customer> Customer::registeredCustomers;

vector<string> Customer::GetActiveCustomerNames()
{
    return Customer::GetActiveCustomerByFunctionField<string>(
        make_shared<CustomerName>());
}

vector<string> Customer::GetActiveCustomerAddresses()
{
    return Customer::GetActiveCustomerByFunctionField<string>(
        make_shared<CustomerAddress>());
}

vector<string> Customer::GetActiveCustomerPhoneNumbers()
{
    return Customer::GetActiveCustomerByFunctionField<string>(
        make_shared<CustomerPhoneNumber>());
}

vector<string> Customer::GetActiveCustomerEmails()
{
    return Customer::GetActiveCustomerByFunctionField<string>(
        make_shared<CustomerEmail>());
}

template<typename T>
vector<T> Customer::GetActiveCustomerByFunctionField(
    const shared_ptr<BaseClass<Customer, T>> &classField)
{
    vector<T> returnList;
    for (auto &customer : Customer::registeredCustomers)
    {
        if (customer.isActive)
        {
            returnList.push_back(
                classField->InvokeFunction(
                    make_shared<Customer>(customer)));
        }
    }
    return returnList;
}
