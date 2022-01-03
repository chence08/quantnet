/* Author: YiJia Chen */

#include "Point.hpp"
#include <sstream> // for ToString function to convert doubles to strings.
#include <iostream> // std::cout
#include <cmath> // std::sqrt()

Point::Point()
{
}

Point::~Point()
{
}

double Point::GetX()
{
    return m_x;
}

double Point::GetY()
{
    return m_y;
}

void Point::SetX(double x)
{
    this->m_x = x;
}

void Point::SetY(double y)
{
    this->m_y = y;
}

string Point::ToString()
{
    stringstream ss;
    ss << "Point(" << m_x << ", " << m_y << ")\n";
    return ss.str();
}

/* Exercise 2.2.2 */
double Point::DistanceOrigin()
{
    return sqrt(m_x * m_x + m_y * m_y);
}

double Point::Distance(Point p)
{
    double horizontal = p.GetX() - m_x;
    double vertical = p.GetY() - m_y;
    return sqrt(horizontal * horizontal + vertical * vertical);
}