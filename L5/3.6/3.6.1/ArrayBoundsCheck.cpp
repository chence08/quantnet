/* Author: YiJia Chen */

#include <iostream>
#include "Array.hpp"

int main() {
    Array arr1; // array of size 10
    
    // GetElement
    try
    {
        arr1.GetElement(-1);
    }
    catch(int e)
    {
        cout << e << ": Cannot GetElement at out of bounds index!" << endl;
    }

    // SetElement
    try
    {
        arr1.SetElement(10, Point());
    }
    catch(int e)
    {
        cout << e << ": Cannot SetElement at out of bounds index!" << endl;
    }
    
    // index operator
    try
    {
        arr1[99];
    }
    catch(int e)
    {
        cout << e << ": Cannot access element at out of bounds index!" << endl;
    }
    try
    {
        arr1[99] = Point();
    }
    catch(int e)
    {
        cout << e << ": Cannot modify element at out of bounds index!" << endl;
    }
}