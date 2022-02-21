/* Author: YiJia Chen */

#include "Circle.hpp"
#include <iostream>
#include <sstream>
#define _USE_MATH_DEFINES
#include <cmath>

Circle::Circle(const Point& centre, double radius) : centre(centre)
{
    m_radius = radius >= 0 ? radius : -radius;
}

Point Circle::CentrePoint() const
{
    return centre;
}

double Circle::Radius() const
{
    return m_radius;
}

double Circle::Diameter() const
{
    return m_radius * 2;
}

double Circle::Area() const
{
    return M_PI * m_radius * m_radius;
}

double Circle::Circumference() const
{
    return M_PI * m_radius * 2;
}

string Circle::ToString() const
{
    stringstream ss;
    ss << "Circle of radius " << m_radius << " centered at " << centre.ToString();
    return ss.str();
}

Circle& Circle::operator=(const Circle& source)
{
    centre = source.centre;
    m_radius = source.m_radius;
    return *this;
}

/* Exercise 2.4.2 ostream << operator */
ostream& operator<<(ostream& os, const Circle& c)
{
    os << c.ToString();
    return os;
}