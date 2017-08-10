/* Customer.cpp - Step04 */
#include "Customer.h"

using namespace std;

vector<string> Customer::GetActiveCustomerNames(
    vector<Customer> customers)
{
    return Customer::GetActiveCustomerByFunctionField<string>(
        customers,
        make_shared<CustomerName>());
}

vector<string> Customer::GetActiveCustomerAddresses(
    vector<Customer> customer)
{
    return Customer::GetActiveCustomerByFunctionField<string>(
        customer,
        make_shared<CustomerAddress>());
}

vector<string> Customer::GetActiveCustomerPhoneNumbers(
    vector<Customer> customer)
{
    return Customer::GetActiveCustomerByFunctionField<string>(
         customer,
        make_shared<CustomerPhoneNumber>());
}

vector<string> Customer::GetActiveCustomerEmails(
    vector<Customer> customer)
{
    return Customer::GetActiveCustomerByFunctionField<string>(
        customer,
        make_shared<CustomerEmail>());
}

template<typename T>
vector<T> Customer::GetActiveCustomerByFunctionField(
    vector<Customer> customers,
    const shared_ptr<BaseClass<Customer, T>>
        &classField)
{
    vector<T> returnList;
    for (auto &customer : customers)
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
