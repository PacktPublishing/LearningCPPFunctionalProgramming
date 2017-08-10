/* event.cpp */
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

void CheckEventSignaling(
    bool b)
{
    if (b)
    {
        cout << "The event is signaled" << endl;
    }
    else
    {
        cout << "The event is not signaled" << endl;
    }
}

auto main() -> int
{
    cout << "[event.cpp]" << endl;

    auto ev = Event{
        EventType::ManualReset };

    CheckEventSignaling(ev.Wait(0));

    ev.Set();

    CheckEventSignaling(ev.Wait(0));

    ev.Clear();

    CheckEventSignaling(ev.Wait(0));

    return 0;
}