/* permutation.cpp */
#include <iostream>

using namespace std;

// Calculation the permutation
// of the given string
void doPermute(
    const string &chosen,
    const string &remaining)
{
    if(remaining == "")
    {
        cout << chosen << endl;
    }
    else
    {
        for(uint32_t u = 0; u < remaining.length(); ++u)
        {
            doPermute(
            chosen + remaining[u],
            remaining.substr(0, u)
                + remaining.substr(u + 1));
        }
    }
}

// The caller of doPermute() function
void permute(
    const string &s)
{
    doPermute("", s);
}

auto main() -> int
{
    cout << "[permutation.cpp]" << endl;

    // Initializing str variable
    // then ask user to fill in
    string str;
    cout << "Permutation of a string" << endl;
    cout << "Enter a string: ";
    getline(cin, str);

    // Finding the possibility of the permutation
    // by calling permute() function
    cout << endl << "The possibility permutation of ";
    cout << str << endl;
    permute(str);

    return 0;
}
