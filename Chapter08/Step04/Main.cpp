/* Main.cpp - Step04 */
#include <iostream>
#include "Customer.h"

using namespace std;

vector<Customer> RegisterCustomers()
{
    int i = 0;
    bool b = false;

    vector<Customer> returnValue;

    // Initialize name
    vector<string> nameList =
    {
        "William",
        "Aiden",
        "Rowan",
        "Jamie",
        "Quinn",
        "Haiden",
        "Logan",
        "Emerson",
        "Sherlyn",
        "Molly"
    };

    for (auto name : nameList)
    {
        // Create Customer object
        // and fill all properties
        Customer c;
        c.id = i++;
        c.name = name;
        c.address = "somewhere";
        c.phoneNumber = "0123";
        c.email = name + "@xyz.com";
        c.isActive = b;

        // Flip the b value
        b = !b;

        // Send data to the registeredCustomers
        returnValue.push_back(c);
    }

    return returnValue;
}

auto main() -> int
{
    cout << "[Step04]" << endl;
    cout << "--------" << endl;

    // Instance Customer object
    Customer customer;

    // Get the active customer names
    cout << "List of active customer names:" << endl;
    vector<string> activeCustomerNames =
        customer.GetActiveCustomerNames(
            RegisterCustomers());
    for (auto name : activeCustomerNames)
    {
        cout << name << endl;
    }

    return 0;
}
