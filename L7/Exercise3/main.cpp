/*
Author: YiJia Chen

Use the count_if algorithm to count the number of elements smaller than a
certain number. The count_if function accepts a functor. Thus pass it a global
function that checks the double input is smaller than a certain value.

Replace the global checking function, by a function object.
This is a class that overloads the round bracket operator that in this case has
the same signature and functionality as the global function created previously.
Only in this case, the value to check for should not be a 'literal' value, but
taken from a data member that was set in the constructor of the function object.
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include "Functor.hpp"
using namespace std;

int main()
{
    vector<double> v {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << "(Global function) Number of elements smaller than 4: " <<
    count_if(v.begin(), v.end(),
    [](double input)
    {
        return input < 4;
    }) << endl;

    cout << "(Functor) Number of elements smaller than 3: " <<
    count_if(v.begin(), v.end(), Functor(3)) << endl;
}