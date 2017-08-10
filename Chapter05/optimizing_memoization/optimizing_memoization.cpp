/* optimizing_memoization.cpp */
#include <iostream>
#include <functional>
#include <chrono>

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

// Function for calculating Fibonacci sequence
int fibonacci(int n)
{
    if(n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

auto main() -> int
{
    cout << "[optimizing_memoization.cpp]" << endl;

    // Recording start time for the program
    auto start = chrono::high_resolution_clock::now();

    // Initializing int variable to store the result
    // from Fibonacci calculation
    int fib40Result = 0;

    // Constructing Memoization<> named fib40
    Memoization<int> fib40([]()
    {
        return fibonacci(40);
    });

    for (int i = 1; i <= 5; ++i)
    {
        cout << "Invocation " << i << ". ";

        // Recording start time
        auto start = chrono::high_resolution_clock::now();

        // Invoking the Fetch() method
        // in fib40 instance
        fib40Result = fib40.Fetch();

        // Recording end time
        auto finish = chrono::high_resolution_clock::now();

        // Calculating the elapsed time
        chrono::duration<double, milli> elapsed = finish - start;

        // Displaying the result
        cout << "Result = " << fib40Result << ". ";

        // Displaying elapsed time
        // for each fib40.Fetch() invocation
        cout << "Consuming time = " << elapsed.count();
        cout << " milliseconds" << endl;
    }

    // Recording end time for the program
    auto finish = chrono::high_resolution_clock::now();

    // Calculating the elapsed time for the program
    chrono::duration<double, milli> elapsed = finish - start;

    // Displaying elapsed time for the program
    cout << "Total consuming time = ";
    cout << elapsed.count() << " milliseconds" << endl;

    return 0;
}
