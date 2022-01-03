/* Author: YiJia Chen */

#include "Point.hpp"
#include <sstream> // for ToString function to convert doubles to strings.
#include <iostream> // std::cout
#include <cmath> // std::sqrt()

Point::Point() : m_x(0), m_y(0)
{
    cout << "No-args constructor invoked.\n";
}

Point::~Point()
{
    cout << "Destructor invoked for " << ToString() << endl;
}

// double Point::X() const
// {
//     return m_x;
// }

// double Point::Y() const
// {
//     return m_y;
// }

// void Point::X(double x)
// {
//     this->m_x = x;
// }

// void Point::Y(double y)
// {
//     this->m_y = y;
// }

string Point::ToString() const
{
    stringstream ss;
    ss << "Point(" << m_x << ", " << m_y << ")";
    return ss.str();
}

/* Exercise 2.2.2 */
double Point::Distance() const
{
    return sqrt(m_x * m_x + m_y * m_y);
}

double Point::Distance(const Point& p) const
// Since p is a constant reference, a runtime error occurs
// if this function tries to modify p.
{
    double horizontal = p.X() - m_x;
    double vertical = p.Y() - m_y;
    return sqrt(horizontal * horizontal + vertical * vertical);
}

/* Exercise 2.3.2 */
Point::Point(const Point& p) : m_x(p.m_x), m_y(p.m_y) // Copy constructor
{
    cout << "<Copy constructor invoked.>";
}

Point::Point(double x, double y) : m_x(x), m_y(y)
{
    cout << "Point::Point(x, y) invoked.\n";
}