/* Author: YiJia Chen */

#include <iostream>
#include "Point.hpp"

int main() {
    Point* *arr = new Point*[3]; // array of Point pointers with 3 elements on the heap.
    /*
    local variable 'arr' stored in the stack, 'new' operator allocates memory in the freestore for an array of 3 Point pointers.

           +-------------+-------------+-------------+
    arr <--|Point* arr[0]|Point* arr[1]|Point* arr[2]| (arr stored persistently on heap)
           +-------------+-------------+-------------+
    */
    cout << "Address of pointers:" <<
    "\narr -> " << &arr <<
    "\narr[0] -> " << &arr[0] <<
    "\narr[1] -> " << &arr[1] <<
    "\narr[2] -> " << &arr[2] << endl;

    arr[0] = new Point();
    arr[1] = new Point(1, 2);
    arr[2] = new Point(*arr[1]);
    /*
           +-------------+-------------+-------------+
    arr <--|Point* arr[0]|Point* arr[1]|Point* arr[2]| (arr stored persistently on heap)
           +------+------+------+------+------+------+
                  |             |             |
                  v             v             v
            Point(0,0)    Point(1,2)    Point(1,2)
    */

    cout << "\n\nIterate the array and print each point" << endl;
    for (int i = 0; i < 3; i++)
        cout << *arr[i] << endl;
    
    cout << "\nIterate the array and delete each point" << endl;
    for (int i = 0; i < 3; i++)
        delete arr[i];
    cout << "\nGibberish pointers after deleting each point:\n" << *arr[0] << ", " << *arr[1] << ", " << *arr[2] << endl;
    /*
           +-------------+-------------+-------------+
    arr <--|Point* arr[0]|Point* arr[1]|Point* arr[2]| (arr stored persistently on heap)
           +-------------+-------------+-------------+
    */

    delete [] arr;
    cout << "\nAddress of pointers after deleting the array itself:" <<
    "\narr -> " << &arr <<
    "\narr[0] -> " << &arr[0] <<
    "\narr[1] -> " << &arr[1] <<
    "\narr[2] -> " << &arr[2] << endl;
}