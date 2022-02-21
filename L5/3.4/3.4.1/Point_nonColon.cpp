/* Author: YiJia Chen */

#include "Point_nonColon.hpp"
#include <sstream> // for ToString function to convert doubles to strings.
#include <iostream> // std::cout
#include <cmath> // std::sqrt()

Point_nonColon::Point_nonColon()
{
    cout << "[NON-COLON SYNTAX] No-args constructor invoked.\n";
    m_x = 0;
    m_y = 0;
}

Point_nonColon::~Point_nonColon()
{
    cout << "[NON-COLON SYNTAX] Destructor invoked for " << ToString() << endl;
}

// double Point_nonColon::X() const
// {
//     return m_x;
// }

// double Point_nonColon::Y() const
// {
//     return m_y;
// }

// void Point_nonColon::X(double x)
// {
//     this->m_x = x;
// }

// void Point_nonColon::Y(double y)
// {
//     this->m_y = y;
// }

string Point_nonColon::ToString() const
{
    stringstream ss;
    ss << "Point_nonColon(" << m_x << ", " << m_y << ")";
    return ss.str();
}

/* Exercise 2.2.2 */
double Point_nonColon::Distance() const
{
    return sqrt(m_x * m_x + m_y * m_y);
}

double Point_nonColon::Distance(const Point_nonColon& p) const
// Since p is a constant reference, a runtime error occurs
// if this function tries to modify p.
{
    double horizontal = p.X() - m_x;
    double vertical = p.Y() - m_y;
    return sqrt(horizontal * horizontal + vertical * vertical);
}

/* Exercise 2.3.2 */
Point_nonColon::Point_nonColon(const Point_nonColon& p) // Copy constructor
{
    // cout << "<Copy constructor invoked.>";
    m_x = p.m_x;
    m_y = p.m_y;
}

Point_nonColon::Point_nonColon(double x, double y) : m_x(x), m_y(y)
{
    // cout << "Point_nonColon::Point_nonColon(x, y) invoked.\n";
    this->m_x = x;
    this->m_y = y;
}

/* Exercise 2.4.1 */
Point_nonColon Point_nonColon::operator-() const
{
    return Point_nonColon(-m_x, -m_y);
}

Point_nonColon Point_nonColon::operator*(double factor) const
{
    return Point_nonColon(m_x * factor, m_y * factor);
}

Point_nonColon Point_nonColon::operator+(const Point_nonColon& p) const
{
    return Point_nonColon(m_x + p.m_x, m_y + p.m_y);
}

bool Point_nonColon::operator==(const Point_nonColon& p) const
{
    return m_x == p.m_x && m_y == p.m_y;
}

Point_nonColon& Point_nonColon::operator=(const Point_nonColon& source)
{
    cout << "Assignment operator invoked.\n";
    m_x = source.m_x;
    m_y = source.m_y;
    return *this;
}

Point_nonColon& Point_nonColon::operator*=(double factor)
{
    *this = Point_nonColon(m_x * factor, m_y * factor);
    return *this;
}

ostream& operator<<(ostream& os, const Point_nonColon& p)
{
    os << p.ToString();
    return os;
}