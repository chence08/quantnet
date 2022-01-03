/* Author: YiJia Chen */

#include <iostream>
#include "Point.hpp"
#include "Circle.hpp"

int main()
{
    Point p;
    Circle c(p, 5);

    cout << c.ToString() << endl;
    cout << c.CentrePoint().ToString() << endl;
    cout << "Radius = " << c.Radius() << endl;
    cout << "Diameter = " << c.Diameter() << endl;
    cout << "Area = " << c.Area() << endl;
    cout << "Circumference = " << c.Circumference() << endl;
}