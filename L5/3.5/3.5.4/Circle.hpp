/* Author: YiJia Chen */

#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "Point.hpp"
#include "Shape.hpp"

class Circle: public Shape
{
public:
    Circle();
    Circle(const Point& centre, double radius);

    Point CentrePoint() const;
    double Radius() const;
    
    double Diameter() const;
    double Area() const;
    double Circumference() const;

    string ToString() const;

    /* Exercise 2.4.1 */
    Circle& operator=(const Circle& source);

    void Draw() const;

private:
    Point centre;
    double m_radius;
};

/* Exercise 2.4.2 ostream << operator */
ostream& operator<<(ostream& os, const Circle& c);

#endif