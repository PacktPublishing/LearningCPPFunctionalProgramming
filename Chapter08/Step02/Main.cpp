/* Main.cpp - Step02 */
#include <iostream>
#include "Customer.h"

using namespace std;

void RegisterCustomers()
{
    int i = 0;
    bool b = false;

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

    // Clear the registeredCustomers vector array
    Customer::registeredCustomers.clear();

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
        Customer::registeredCustomers.push_back(c);
    }
}

auto main() -> int
{
    cout << "[Step02]" << endl;
    cout << "--------" << endl;

    // Fill the Customer::registeredCustomers
    // with the content
    RegisterCustomers();

    // Instance Customer object
    Customer customer;

    // Get the active customer names
    cout << "List of active customer names:" << endl;
    vector<string> activeCustomerNames =
        customer.GetActiveCustomerByField("name");
    for (auto &name : activeCustomerNames)
    {
        cout << name << endl;
    }

    return 0;
}
