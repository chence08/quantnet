/* Author: YiJia Chen */

#include <iostream>
#include "Array.cpp"

int main() {
    Array<int> intArray1;
    Array<int> intArray2;
    Array<double> doubleArray;

    cout << intArray1.DefaultSize() << endl;
    cout << intArray2.DefaultSize() << endl;
    cout << doubleArray.DefaultSize() << endl;

    intArray1.DefaultSize(15);

    cout << intArray1.DefaultSize() << endl;
    cout << intArray2.DefaultSize() << endl;
    cout << doubleArray.DefaultSize() << endl;
}

/*
What values are printed? Can you explain the result?
10
10
10
15
15
10

We can see modifying the DEFAULT_SIZE in intArray1 only affected the instances of
Array<int> and not Array<double>.

This is because the template arguments become part of the class name, and
Array<int> and Array<double> are regarded as distinct classes. Hence, their
static members are distinct from one another by definition of static variables and methods.
*/
