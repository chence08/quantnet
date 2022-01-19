/* Author: YiJia Chen */

#include <iostream>
#include "Point.hpp"

int main() {
    Point* p1 = new Point(); // default constructor
    Point* p2 = new Point(1, 2); // constructor with coordinates
    Point* p3 = new Point(*p2); // copy constructor

    cout << "\n\np2->Distance() = " << p2->Distance() << endl;
    cout << "p1->Distance(*p3) = " << p1->Distance(*p3) << endl;
    cout << p1 << endl;

    delete p1;
    delete p2;
    delete p3;

    int size;
    cout << "\nEnter size of array: ";
    cin >> size;
    // Point arr[size]; // Avoid variable length arrays for more portable code.
    Point* arr = new Point[size]; // Only can use default constructor.
    delete [] arr;
}