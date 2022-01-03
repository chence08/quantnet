/* Author: YiJia Chen */

#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "Point.hpp"

class Circle
{
public:
    Circle(const Point& centre, double radius);

    Point CentrePoint() const;
    double Radius() const;
    
    double Diameter() const;
    double Area() const;
    double Circumference() const;

    string ToString() const;

private:
    Point centre;
    double m_radius;
};

#endif