/* eventthread.cpp */
#include <iostream>
#include <windows.h>
#include "../uniquehandle_h/uniquehandle.h"

using namespace std;

void Wrap(HANDLE *)
{
}

template <typename T, typename... Args>
void Wrap(
    HANDLE * left,
    T const & right,
    Args const & ... args)
{
    *left = right.Get();
    Wrap(++left, args...);
}

template <typename... Args>
void WaitAllThreads(Args const & ... args)
{
    HANDLE handles[sizeof...(Args)];

    Wrap(handles, args...);

    WaitForMultipleObjects(
        sizeof...(Args),
        handles,
        true,
        INFINITE);
}

auto threadProc(void*) -> unsigned long
{
    cout << "Thread ID: ";
    cout << GetCurrentThreadId() << endl;
    return 120;
}

auto main() -> int
{
    cout << "[eventthread.cpp]" << endl;

    auto thread1 = NullHandle
    {
        CreateThread(
            nullptr,
            0,
            threadProc,
            nullptr,
            CREATE_SUSPENDED,
            nullptr)
    };

    auto thread2 = NullHandle
    {
        CreateThread(
            nullptr,
            0,
            threadProc,
            nullptr,
            CREATE_SUSPENDED,
            nullptr)
    };

    ResumeThread(thread1.Get());
    ResumeThread(thread2.Get());

    WaitAllThreads(thread1, thread2);

    return 0;
}