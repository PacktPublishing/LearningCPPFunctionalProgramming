/* Main.cpp - Step05 */
#include <iostream>
#include <chrono>
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
    cout << "[Step05]" << endl;
    cout << "--------" << endl;

    // Recording start time for the program
    auto start = chrono::high_resolution_clock::now();

    // Instance Customer object
    Customer customer;

    // Counting active customers
    cout << "Total active customers: " << endl;
    cout << customer.CountActiveCustomers(
        RegisterCustomers());
    cout << endl << "--------" << endl;

    // Get the active customer names
    cout << "List of active customer names:" << endl;
    vector<string> activeCustomerNames =
        customer.GetActiveCustomerNames(
            RegisterCustomers());
    for (auto name : activeCustomerNames)
    {
        cout << name << endl;
    }

    // Recording end time for the program
    auto finish = chrono::high_resolution_clock::now();

    // Calculating the elapsed time for the program
    chrono::duration<double, milli> elapsed = finish - start;

    // Displaying elapsed time for the program
    cout << "--------" << endl;
    cout << "Total consuming time = ";
    cout << elapsed.count() << " milliseconds" << endl;

    return 0;
}
