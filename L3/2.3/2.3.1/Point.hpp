/* Author: YiJia Chen
Create a Point class with x- and y-coordinates.
Avoid multiple inclusion. */

#ifndef POINT_HPP
#define POINT_HPP
#include <string>
using namespace std;

class Point
{
public:
    Point(); // Default constructor
    ~Point(); // Destructor

    // Getter functions
    double GetX();
    double GetY();

    // Setter functions
    void SetX(double x);
    void SetY(double y);

    string ToString();

    /* Exercise 2.2.2 */
    double DistanceOrigin(); // Calculate the distance between the origin (0, 0).
    double Distance(Point p); // Calculate the distance between two points.

    /* Exercise 2.3.1 */
    Point(const Point&); // Copy constructor
    Point(double x, double y);
    
private:
    double m_x;
    double m_y;
};

#endif