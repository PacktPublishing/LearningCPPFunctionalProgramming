/* tuples_2.cpp */
#include <tuple>
#include <iostream>

using namespace std;

auto main() -> int
{
    cout << "[tuples_2.cpp]" << endl;

    // Initializing two Tuples
    tuple<int, string, bool> t1(1, "Robert", true);
    auto t2 = make_tuple(2, "Anna", false);

    int i;
    string s;
    bool b;

    // Unpacking t1 tuples
    tie(i, s, b) = t1;
    cout << "tie(i, s, b) = t1" << endl;
    cout << "i = " << i << endl;
    cout << "s = " << s << endl;
    cout << "b = " << boolalpha << b << endl;
    cout << endl;

    // Unpacking t2 tuples
    tie(ignore, s, ignore) = t2;
    cout << "tie(ignore, s, ignore) = t2" << endl;
    cout << "new i = " << i << endl;
    cout << "new s = " << s << endl;
    cout << "new b = " << boolalpha << b << endl;
    cout << endl;

    return 0;
}
