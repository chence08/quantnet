/*
Author: YiJia Chen
Compile with C++11
*/

#include <list>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

template <typename T>
void vectorInfo(vector<T> v)
{
    cout << "Vector size = " << v.size() <<
    "\nVector capacity = " << v.capacity() << endl;
}

int main()
{
    /*
    1. Create a list of doubles and add some data. Use the front() and back()
    functions to access the first and last element.
    */
    cout << "\n1. LIST" << endl;
    list<double> l {1.5, 2.5, 3.5, 4.5, 5.5};
    cout << "First element: " << l.front() <<
    "\nSecond element: " << l.back() << endl;

    /*
    2. Create a vector of doubles and add some data. Then use the index operator
    to access some elements. Also make the vector grow.
    */
    cout << "\n2. VECTOR" << endl;
    vector<double> v {3.14, 99, -5.6};
    vectorInfo(v);
    cout << "Middle element = " << v[1] << endl;
    v.push_back(0);
    v.push_back(0);
    cout << "After adding two zeroes..." << endl;
    vectorInfo(v);

    /*
    3. Create a map that maps strings to doubles. Fill the map and access
    elements using the square bracket operator.
    */
    cout << "\n3. MAP" << endl;
    map<string, double> m {
        {"pi", 3.14},
        {"euler", 2.72}
    };
    cout << "Euler's number = " << m["euler"] << endl;
}