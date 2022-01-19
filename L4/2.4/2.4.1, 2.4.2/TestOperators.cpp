/* Author: YiJia Chen
- Ask the user for the x- and y- coordinates using the std::cin object.
- Test operator functions for Point, Line and Circle classes.
- Test ostream << operator for Point, Line and Circle classes.
*/

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

int main()
{
    double x, y;
    cout << "Exercise 2.4.1\n====Test Point class====\n\n" << "Enter x-coordinate: ";
    cin >> x;
    cout << "Enter y-coordinate: ";
    cin >> y;

    Point point(x, y);
    
    cout << "p = " << point << endl;
    cout << "-p = " << -point << endl; // - operator
    cout << "p * 0.5 = " << point * 0.5 << endl; // * operator

    Point point2(x, y); // point2 equals point
    Point point3(x+1, y); // point 3 does not equal point
    cout << "\nq1 = " << point2 << ", q2 = "<< point3 << endl;
    cout << "p == q1 yields " << std::boolalpha << (point == point2) << endl;
    cout << "p == q2 yields " << std::boolalpha << (point == point3) << endl;
    
    point = point3; // = operator
    cout << "\np = q2\np = " << point << endl;
    
    point *= 5; // *= operator
    cout << "\np *= 5; p becomes " << point << endl;

    /* Test assignment operator for Line and Circle */
    cout << "\n====Test Line class====" << endl;
    Line l1, l2(-point2, point3);
    cout << "l1 = " << l1 << "l2 = " << l2 << endl;
    l1 = l2;
    cout << "l1 = l2; l1 = " << l1 << endl;

    cout << "====Test Circle class====" << endl;
    Circle c1(point, 5), c2(point2, 3);
    cout << "c1 = " << c1 << "\nc2 = " << c2 << endl;
    c1 = c2;
    cout << "c1 = c2; c1 = " << c1 << endl;
}