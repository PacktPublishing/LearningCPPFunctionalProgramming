/* shared_ptr_1.cpp */
#include <memory>
#include <iostream>

using namespace std;

auto main() -> int
{
    cout << "[shared_ptr_1.cpp]" << endl;

    auto sp1 = shared_ptr<int>{};

    if(sp1)
        cout << "sp1 is initialized" << endl;
    else
        cout << "sp1 is not initialized" << endl;
    cout << "sp1 pointing counter = " << sp1.use_count() << endl;
    if(sp1.unique())
        cout << "sp1 is unique" << endl;
    else
        cout << "sp1 is not unique" << endl;
    cout << endl;

    sp1 = make_shared<int>(1234);

    if(sp1)
        cout << "sp1 is initialized" << endl;
    else
        cout << "sp1 is not initialized" << endl;
    cout << "sp1 pointing counter = " << sp1.use_count() << endl;
    if(sp1.unique())
        cout << "sp1 is unique" << endl;
    else
        cout << "sp1 is not unique" << endl;
    cout << endl;

    auto sp2 = sp1;

        cout << "sp1 pointing counter = " << sp1.use_count() << endl;
    if(sp1.unique())
        cout << "sp1 is unique" << endl;
    else
        cout << "sp1 is not unique" << endl;
    cout << endl;

    cout << "sp2 pointing counter = " << sp2.use_count() << endl;
    if(sp2.unique())
        cout << "sp2 is unique" << endl;
    else
        cout << "sp2 is not unique" << endl;
    cout << endl;

    sp2.reset();

    cout << "sp1 pointing counter = " << sp1.use_count() << endl;
    if(sp1.unique())
        cout << "sp1 is unique" << endl;
    else
        cout << "sp1 is not unique" << endl;
    cout << endl;

    return 0;
}
