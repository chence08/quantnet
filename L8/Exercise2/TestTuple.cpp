/*
Author: YiJia Chen
Compile with C++11

Boost tuples can be used to store different kinds of data as one entity.
It can be used if we need to combine data without the need to create a separate class.

1. Create a typedef for a `Person` tuple that contains a name, age and length.
2. Create a function that prints the person tuple. Use the get<T>() member
function to retrieve the data. Create a few person tuple instances and print them.
3. Increment the age of one of the persons. Note that to change a value of one
of the tuple elements, you can also use the get<T>() function since it returns
a reference to the value.
*/

#include <boost/tuple/tuple.hpp>
#include <iostream>
using namespace std;

// name, age, length
typedef boost::tuple<string, int, double> Person;

void printPerson(const Person& p)
{
    cout << p.get<1>() << " years old "
    << p.get<0>() << " with a height of " << p.get<2>() << "m." << endl;
}

int main()
{
    Person p1{"Alice", 20, 1.7};
    Person p2{"Bob", 16, 1.82};
    Person p3{"Eve", 40, 1.67};
    printPerson(p1);
    printPerson(p2);
    printPerson(p3);

    cout << "Increment Bob's age..." << endl;
    p2.get<1>()++;
    printPerson(p2);
}