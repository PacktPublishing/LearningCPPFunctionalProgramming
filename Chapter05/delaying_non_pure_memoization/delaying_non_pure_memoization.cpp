/* delaying_non_pure_memoization.cpp */
#include <iostream>
#include <functional>

using namespace std;

template<class T> class Memoization
{
private:
    T const & (*m_subRoutine)(Memoization *);
    mutable T m_recordedFunc;
    function<T()> m_func;

    static T const & ForceSubroutine(
        Memoization * d)
    {
        return d->DoRecording();
    }

    static T const & FetchSubroutine(
        Memoization * d)
    {
        return d->FetchRecording();
    }

    T const & FetchRecording()
    {
        return m_recordedFunc;
    }

    T const & DoRecording()
    {
        m_recordedFunc = m_func();
        m_subRoutine = &FetchSubroutine;
        return FetchRecording();
    }

public:
    Memoization(
    function<T()> func)
        : m_func(func),
        m_subRoutine(&ForceSubroutine),
        m_recordedFunc(T())
    {
    }

    T Fetch()
    {
        return m_subRoutine(this);
    }
};

auto main() -> int
{
    cout << "[delaying_non_pure_memoization.cpp]" << endl;

    // Initializing several int variables
    int a = 10;
    int b = 5;
    int multiplexer = 0;

    // Constructing Memoization<> named multiply_impure
    Memoization<int> multiply_impure([&]()
    {
        return multiplexer * a * b;
    });

    // Invoking Fetch() method in multiply_impure instance
    // multiple times
    for (int i = 0; i < 5; ++i)
    {
        ++multiplexer;
        cout << "Multiplexer = " << multiplexer << endl;
        cout << "a * b = " << multiply_impure.Fetch();
        cout << endl;
    }

    return 0;
}
