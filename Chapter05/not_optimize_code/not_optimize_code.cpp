/* not_optimize_code.cpp */
#include <iostream>
#include <functional>
#include <chrono>

using namespace std;

template<class T> class Delay
{
private:
    function<T()> m_func;

public:
    Delay(
        function<T()> func)
        : m_func(func)
    {
    }

    T Fetch()
    {
        return m_func();
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
    cout << "[not_optimize_code.cpp]" << endl;

    // Recording start time for the program
    auto start = chrono::high_resolution_clock::now();

    // Initializing int variable to store the result
    // from Fibonacci calculation
    int fib40Result = 0;

    // Constructing Delay<> named fib40
    Delay<int> fib40([]()
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
