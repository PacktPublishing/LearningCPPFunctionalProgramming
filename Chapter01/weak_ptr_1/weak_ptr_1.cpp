/* weak_ptr_1.cpp */
#include <memory>
#include <iostream>

using namespace std;

auto main() -> int
{
    cout << "[weak_ptr_1.cpp]" << endl;

    auto sp = make_shared<int>(1234);

    auto wp = weak_ptr<int>{ sp };

    if(wp.expired())
    cout << "wp is expired" << endl;
    else
    cout << "wp is not expired" << endl;
    cout << "wp pointing counter = " << wp.use_count() << endl;
    if(auto locked = wp.lock())
    cout << "wp is locked. Value = " << *locked << endl;
    else
    {
    cout << "wp is unlocked" << endl;
    wp.reset();
    }
    cout << endl;

    sp = nullptr;

    if(wp.expired())
    cout << "wp is expired" << endl;
    else
    cout << "wp is not expired" << endl;
    cout << "wp pointing counter = " << wp.use_count() << endl;
    if(auto locked = wp.lock())
    cout << "wp is locked. Value = " << *locked << endl;
    else
    {
    cout << "wp is unlocked" << endl;
    wp.reset();
    }
    cout << endl;

    return 0;
}
