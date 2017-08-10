/* first_class_4.cpp */
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iostream>

using std::vector;
using std::function;
using std::transform;
using std::back_inserter;
using std::cout;
using std::endl;

// Defining a type of function named HyperbolicFunc
// representing a function
// that pass a double argument
// and return an double value
typedef function<double(double)> HyperbolicFunc;

// Initializing a vector containing four functions
vector<HyperbolicFunc> funcs = {
    sinh,
    cosh,
    tanh,
    [](double x) {
        return x*x; }
};

// Initializing a vector containing four functions
vector<HyperbolicFunc> inverseFuncs = {
    asinh,
    acosh,
    atanh,
    [](double x) {
        return exp(log(x)/2); }
};

// Declaring a template to be able to be reused
template <typename A, typename B, typename C>
function<C(A)> compose(
    function<C(B)> f,
    function<B(A)> g) {
        return [f,g](A x) {
            return f(g(x));
    };
}

auto main() -> int
{
    cout << "[first_class_4.cpp]" << endl;

    // Declaring a vector containing HyperbolicFunc element
    vector<HyperbolicFunc> composedFuncs;

    // Initializing a vector containing several double elements
    vector<double> nums;
    for (int i = 1; i <= 5; ++i)
        nums.push_back(i * 0.2);

    // Transforming the element inside the vector
    transform(
        begin(inverseFuncs),
        end(inverseFuncs),
        begin(funcs),
        back_inserter(composedFuncs),
        compose<double, double, double>);

    for (auto num: nums)
    {
        for (auto func: composedFuncs)
            cout << "f(g(" << num << ")) = " << func(num) << endl;

        cout << "---------------" << endl;
    }

    return 0;
}
