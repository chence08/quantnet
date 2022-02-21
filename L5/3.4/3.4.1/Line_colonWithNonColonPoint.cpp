/* Author: YiJia Chen */

#include "Line_colonWithNonColonPoint.hpp"
#include <iostream>

Line_colonWithNonColonPoint::Line_colonWithNonColonPoint() : p1(), p2()
{
}

Line_colonWithNonColonPoint::Line_colonWithNonColonPoint(const Point_nonColon& p1, const Point_nonColon& p2) : p1(p1), p2(p2)
{
}

Line_colonWithNonColonPoint::Line_colonWithNonColonPoint(const Line_colonWithNonColonPoint& l) : p1(l.p1), p2(l.p2)
{
}

Line_colonWithNonColonPoint::~Line_colonWithNonColonPoint()
{
}

Point_nonColon Line_colonWithNonColonPoint::P1() const
{
    return p1;
}

Point_nonColon Line_colonWithNonColonPoint::P2() const
{
    return p2;
}

void Line_colonWithNonColonPoint::P1(const Point_nonColon& p1)
{
    this->p1 = p1;
}

void Line_colonWithNonColonPoint::P2(const Point_nonColon& p2)
{
    this->p2 = p2;
}

string Line_colonWithNonColonPoint::ToString() const
{
    string s = "Line_colonWithNonColonPoint from ";
    s += p1.ToString() + " to " + p2.ToString() + ".\n";
    return s;
}

double Line_colonWithNonColonPoint::Length() const
{
    return p1.Distance(p2);
}

Line_colonWithNonColonPoint& Line_colonWithNonColonPoint::operator=(const Line_colonWithNonColonPoint& source)
{
    p1 = source.p1;
    p2 = source.p2;
    return *this;
}

/* Exercise 2.4.2 ostream << operator */
ostream& operator<<(ostream& os, const Line_colonWithNonColonPoint& l)
{
    os << l.ToString();
    return os;
}