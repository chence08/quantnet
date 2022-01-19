/* Author: YiJia Chen
- Ask the user for the x- and y- coordinates using the std::cin object.
- Test operator functions for Point, Line and Circle classes.
- Test ostream << operator for Point, Line and Circle classes.
*/

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"

int main()
{
    Point p1(1, 2), p2(3, 4);
    Line l(p1, p2);
    cout << p1 << endl;
    cout << l << endl;
}