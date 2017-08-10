/* singlethread.cpp */
#include <thread>
#include <iostream>

using namespace std;

void threadProc()
{
    cout << "Thread ID: ";
    cout << this_thread::get_id() << endl;
}

auto main() -> int
{
    cout << "[singlethread.cpp]" << endl;

    thread thread1(threadProc);
    thread1.join();

    return 0;
}