/* isprimemeta.cpp */
#include <iostream>

using namespace std;

// Defining template that decide
// whether or not the passed argument
// is a prime number
template <
    int lastNumber,
    int secondLastNumber>
class IsPrime
{
public:
    enum
    {
        primeNumber = (
            (lastNumber % secondLastNumber) &&
            IsPrime<lastNumber, secondLastNumber - 1>
                ::primeNumber)
    };
};

// Defining template for checking
// the number passed to the 'number' parameter
// is a prime number
template <int number>
class IsPrime<number, 1>
{
public:
    enum
    {
        primeNumber = 1
    };
};

// Defining template to print out
// the passed argument is it's a prime number
template <int number>
class PrimeNumberPrinter
{
public:
    PrimeNumberPrinter<number - 1> printer;

    enum
    {
        primeNumber = IsPrime<number, number - 1>
            ::primeNumber
    };

    void func()
    {
        printer.func();

        if (primeNumber)
        {
            cout << number << "\t";
        }
    }
};

// Defining template to just ignoring the number
// we pass 1 as argument to the parameter
// since 1 is not prime number
template<>
class PrimeNumberPrinter<1>
{
public:
    enum
    {
        primeNumber = 0
    };

    void func()
    {
    }
};

int main()
{
    cout << "[isprimemeta.cpp]" << endl;

    // Displaying the prime numbers between 1 and 500
    cout << "Filtering the numbers between 1 and 500 ";
    cout << "for of the prime numbers:" << endl;

    // Consuming PrimeNumberPrinter template
    PrimeNumberPrinter<500> printer;

    // invoking func() method from the template
    printer.func();

    cout << endl;
    return 0;
}
