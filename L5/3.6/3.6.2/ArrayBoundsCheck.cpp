/* Author: YiJia Chen */

#include <iostream>
#include "Array.hpp"
#include "OutOfBoundsException.hpp"

int main() {
    Array arr1; // array of size 10
    
    // GetElement
    try
    {
        arr1.GetElement(-1);
    }
    catch(ArrayException& ex)
    {
        cout << ex.GetMessage() << endl;
    }

    // SetElement
    try
    {
        arr1.SetElement(10, Point());
    }
    catch(ArrayException& ex)
    {
        cout << ex.GetMessage() << endl;
    }
    
    // index operator
    try
    {
        arr1[99];
    }
    catch(ArrayException& ex)
    {
        cout << ex.GetMessage() << endl;
    }
    try
    {
        arr1[99] = Point();
    }
    catch(ArrayException& ex)
    {
        cout << ex.GetMessage() << endl;
    }
}