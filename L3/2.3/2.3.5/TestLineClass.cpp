/* Author: YiJia Chen */

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"

void printInfo(const Line& l)
{
    cout << "\n" << l.ToString();
    cout << "Length of line from " << l.P1().ToString() << " to "
    << l.P2().ToString() << " = " << l.Length() << ".\n\n";
}

int main()
{
    cout << "Default constructor test:\n";
    Line l1; // Default constructor.
    printInfo(l1);

    cout << "\nConstructor with start and end point:\n";
    Point p1;
    Point p2(5, -5);
    Line l2(p1, p2);
    printInfo(l2);

    cout << "\nCopy constructor test:\n";
    Line l3(l2);
    printInfo(l3);
}