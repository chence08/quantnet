/*
Author: YiJia Chen

Create a function that calculates the sum of a container with doubles.
1. Create a template function called Sum() that accepts the template argument T
as input and returns a double. The template argument will be a container.

2. In the implmenentation, get an iterator (T::const_iterator) for the end.
Then create a loop that iterates the container T and adds all values.
Finally return the sum.

3. In the main program, call the Sum() function for the different container
from the previous exercise. list, vector and map.

Also create a Sum() function that calculates the sum between two iterators.
The function uses the iterator type and accepts two iterators,
the start and end iterator.
*/

#include <list>
#include <vector>
#include <map>
#include <numeric>
#include <iostream>
using namespace std;

template <typename Iter>
double Sum(Iter& start, const Iter& end)
{
    double result = 0;
    while (start != end)
    {
        result += *(start++);
    }
    return result;
}

template <typename T>
double Sum(const T& container)
{
    typename T::const_iterator start = container.begin();
    typename T::const_iterator end = container.end();
    return Sum(start, end);
}

// For map
template <typename U, typename T>
double Sum(typename map<U, T>::const_iterator& start,
           const typename map<U, T>::const_iterator& end)
{
    double result = 0;
    while (start != end)
    {
        result += (start++)->second;
    }
    return result;
}

template <typename U, typename T>
double Sum(const map<U, T>& container)
{
    typename map<U, T>::const_iterator start = container.begin();
    typename map<U, T>::const_iterator end = container.end();
    return Sum<U, T>(start, end);
}

int main()
{
    cout << "\n1. LIST" << endl;
    list<double> l {1.5, 2.5, 3.5, 4.5, 5.5};
    cout << Sum(l) << endl;

    cout << "\n2. VECTOR" << endl;
    vector<double> v {3.14, 99, -5.6};
    cout << Sum(v) << endl;

    cout << "\n3. MAP" << endl;
    map<string, double> m {
        {"pi", 3.14},
        {"euler", 2.72}
    };
    cout << Sum(m) << endl;
}