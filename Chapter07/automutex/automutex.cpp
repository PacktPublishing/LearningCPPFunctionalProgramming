/* automutex.cpp */
#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

auto main() -> int
{
    cout << "[automutex.cpp]" << endl;
    
    mutex mtx;
    int counter = 0;
    
    thread threads[5];
    
    for (int i = 0; i < 5; ++i)
    {
        threads[i] = thread([&counter, &mtx]()
        {
            for (int i = 0; i < 10000; ++i)
            {
                {
                    lock_guard <mutex> guard(mtx);
                    ++counter;
                }
    
                cout << "Thread ID: ";
                cout << this_thread::get_id();
                cout << "\tCurrent Counter = ";
                cout << counter << endl;
            }
        });
    }
    
    for (auto& thread : threads)
    {
        thread.join();
    }
    
    cout << "Final result = " << counter << endl;
    
    return 0;
}