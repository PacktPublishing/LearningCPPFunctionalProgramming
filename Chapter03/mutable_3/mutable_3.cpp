/* mutable_3.cpp */
#include <iostream>
#include "../mutableemployee/mutableemployee.h"

using namespace std;

auto main() -> int
{
    cout << "[mutable_3.cpp]" << endl;

    // Initializing several variables
    string first = "Frankie";
    string last = "Kaur";
    double d = 1500.0;

    // Creating an instance of MutableEmployee
    MutableEmployee me(0, first, last, d);

    // Displaying initial value
    cout << "Content of MutableEmployee instance" << endl;
    cout << "ID     : " << me.Id() << endl;
    cout << "Name   : " << me.FirstName();
    cout << " " << me.LastName() << endl;
    cout << "Salary : " << me.Salary() << endl << endl;

    // Mutating the instance of MutableEmployee
    me.SetId(1);
    me.SetFirstName("Alexis");
    me.SetLastName("Andrews");
    me.SetSalary(2100.0);

    // Displaying mutate value
    cout << "Content of MutableEmployee after mutating" << endl;
    cout << "ID     : " << me.Id() << endl;
    cout << "Name   : " << me.FirstName();
    cout << " " << me.LastName() << endl;
    cout << "Salary : " << me.Salary() << endl;

    return 0;
}
