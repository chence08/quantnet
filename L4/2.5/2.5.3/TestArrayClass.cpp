/* Author: YiJia Chen */

#include <iostream>
#include "Array.hpp"

int main() {
    Array arr1; // default constructor
    Array arr2(20); // constructor with size
    Array arr3(arr2); // copy constructor
    cout << "arr1.Size() = " << arr1.Size() <<
    "\narr2.Size() = " << arr2.Size() <<
    "\narr3.Size() = " << arr3.Size() << endl;

    arr1 = arr3;
    cout << "\narr1 = arr3\narr1.Size() = " << arr1.Size() <<
    "\narr2.Size() = " << arr2.Size() <<
    "\narr3.Size() = " << arr3.Size() << endl;

    arr3.SetElement(19, Point(1, 2));
    cout << "\narr3.SetElement(19, Point(1, 2))\n" <<
    "arr3[19] = " << arr3[19] <<
    "\narr1[19] = " << arr1[19] << endl;

    // arr2[0] = Point(3, 4);
    // cout << "arr2[0] = " << arr2[0] << endl;
    
    /* By using const for [] operator, it prevents the array elements
    from being changed outside of the SetElement function. */
}