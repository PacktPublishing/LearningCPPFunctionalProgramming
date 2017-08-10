/* immutable_3.cpp */
#include <iostream>
#include "../immutableemployee/immutableemployee.h"

using namespace std;

auto main() -> int
{
    cout << "[immutable_3.cpp]" << endl;

    // Initializing several variables
    string first = "Frankie";
    string last = "Kaur";
    double d = 1500.0;

    // Creating the instance of ImmutableEmployee
    ImmutableEmployee me(0, first, last, d);

    // Displaying initial value
    cout << "Content of ImmutableEmployee instance" << endl;
    cout << "ID : " << me.Id() << endl;
    cout << "Name : " << me.FirstName()
    << " " << me.LastName() << endl;
    cout << "Salary : " << me.Salary() << endl << endl;

    // Modifying the initial value
    ImmutableEmployee me2 = me.SetId(1);
    ImmutableEmployee me3 = me2.SetFirstName("Alexis");
    ImmutableEmployee me4 = me3.SetLastName("Andrews");
    ImmutableEmployee me5 = me4.SetSalary(2100.0);

    // Displaying the new value
    cout << "Content of ImmutableEmployee after modifying" << endl;
    cout << "ID : " << me5.Id() << endl;
    cout << "Name : " << me5.FirstName()
    << " " << me5.LastName() <<    endl;
    cout << "Salary : " << me5.Salary() << endl;

    return 0;
}
