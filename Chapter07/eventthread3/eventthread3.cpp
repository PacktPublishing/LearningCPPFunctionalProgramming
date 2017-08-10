/* eventthread3.cpp */
#include <iostream>
#include <windows.h>
#include "../uniquehandle_h/uniquehandle.h"

using namespace std;

struct WinException
{
    unsigned long error;

    explicit WinException(
        unsigned long value = GetLastError()) :
        error{ value }
    {
    }
};

enum class EventType
{
    AutoReset,
    ManualReset
};

class Event
{
private:
    NullHandle hnd;

public:
    Event(Event const &) = delete;
    auto operator=(Event const &)->Event & = delete;
    ~Event() = default;

    explicit Event(bool manual) :
        hnd
    {
        CreateEvent(nullptr,
        manual, false, nullptr)
    }
    {
        if (!hnd)
            throw WinException();
    }

    explicit Event(EventType evType) :
        hnd
    {
        CreateEvent(
            nullptr,
            static_cast<BOOL>(evType),
            false,
            nullptr)
    }
    {
        if (!hnd)
            throw WinException();
    }

    Event(Event && other) throw() :
        hnd
    {
        other.hnd.Release()
    }
    {
    }

    auto operator=(Event && other) throw() -> Event &
    {
        hnd = move(other.hnd);
    }

    void Set()
    {
        cout << "The event is set" << endl;
        SetEvent(hnd.Get());
    }

    void Clear()
    {
        cout << "The event is cleared" << endl;
        ResetEvent(hnd.Get());
    }

    auto Wait(
        DWORD const ms = INFINITE) -> bool
    {
        auto const result = WaitForSingleObject(
            hnd.Get(), ms);

        return result == WAIT_OBJECT_0;
    }
};

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

static auto ev = Event{
    EventType::AutoReset };

auto threadProc(void*) -> unsigned long
{
    cout << "Thread ID: ";
    cout << GetCurrentThreadId() << endl;

    ev.Wait();

    cout << "Run Thread ID: ";
    cout << GetCurrentThreadId() << endl;

    Sleep(1000);
    ev.Set();

    return 120;
}

auto main() -> int
{
    cout << "[eventthread3.cpp]" << endl;

    auto thread1 = NullHandle
    {
        CreateThread(
            nullptr,
            0,
            threadProc,
            nullptr,
            0,
            nullptr)
    };

    auto thread2 = NullHandle
    {
        CreateThread(
            nullptr,
            0,
            threadProc,
            nullptr,
            0,
            nullptr)
    };

    Sleep(100);
    ev.Set();
    Sleep(100);

    WaitAllThreads(thread1, thread2);

    return 0;
}