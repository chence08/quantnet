/* Author: YiJia Chen */

#include "Line_nonColon.hpp"
#include <iostream>

Line_nonColon::Line_nonColon()
{
    p1 = Point_nonColon();
    p2 = Point_nonColon();
}

Line_nonColon::Line_nonColon(const Point_nonColon& p1, const Point_nonColon& p2)
{
    this->p1 = p1;
    this->p2 = p2;
}

Line_nonColon::Line_nonColon(const Line_nonColon& l)
{
    p1 = l.p1;
    p2 = l.p2;
}

Line_nonColon::~Line_nonColon()
{
}

Point_nonColon Line_nonColon::P1() const
{
    return p1;
}

Point_nonColon Line_nonColon::P2() const
{
    return p2;
}

void Line_nonColon::P1(const Point_nonColon& p1)
{
    this->p1 = p1;
}

void Line_nonColon::P2(const Point_nonColon& p2)
{
    this->p2 = p2;
}

string Line_nonColon::ToString() const
{
    string s = "Line_nonColon from ";
    s += p1.ToString() + " to " + p2.ToString() + ".\n";
    return s;
}

double Line_nonColon::Length() const
{
    return p1.Distance(p2);
}

Line_nonColon& Line_nonColon::operator=(const Line_nonColon& source)
{
    p1 = source.p1;
    p2 = source.p2;
    return *this;
}

/* Exercise 2.4.2 ostream << operator */
ostream& operator<<(ostream& os, const Line_nonColon& l)
{
    os << l.ToString();
    return os;
}