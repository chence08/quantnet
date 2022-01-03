/* Author: YiJia Chen
- Ask the user for the x- and y- coordinates using the std::cin object.
- Create a Point object using the default constructor.
- Set the coordinates entered by the user using the Setter functions.
- Print the description of the point returned by the ToString() function.
- Print the point coordinates using the Get functions. */

#include <iostream>
#include "Point.hpp"

int main()
{
    double x, y;
    cout << "=====Exercise 2.3.1=====\n" << "Enter x-coordinate: ";
    cin >> x;
    cout << "Enter y-coordinate: ";
    cin >> y;

    Point point(x, y);

    // point.SetX(x);
    // point.SetY(y);

    cout << point.ToString();

    cout << "point.GetX() = " << point.X() << endl;
    cout << "point.GetY() = " << point.Y() << endl;

    /* Exercise 2.2.2 */
    cout << "\n=====Exercise 2.2.2=====\n";
    cout << "Distance to origin = " << point.Distance() << endl;
    Point point2(5, -5);
    cout << "Distance to (5, -5) = " << point.Distance(point2) << endl;

    /* Exercise 2.3.4 */
    const Point cp(1.5, 3.9);
    // cp.X(0.3);
    cout << cp.X() << endl;
}