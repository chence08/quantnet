/* Author: YiJia Chen */

#include "Line.hpp"
#include <iostream>

Line::Line() : Shape(), p1(), p2()
{
}

Line::Line(const Point& p1, const Point& p2) : Shape(), p1(p1), p2(p2)
{
}

// Notice the copy constructor of the base class is invoked!
Line::Line(const Line& l) : Shape(l), p1(l.p1), p2(l.p2)
{
}

Line::~Line()
{
}

Point Line::P1() const
{
    return p1;
}

Point Line::P2() const
{
    return p2;
}

void Line::P1(const Point& p1)
{
    this->p1 = p1;
}

void Line::P2(const Point& p2)
{
    this->p2 = p2;
}

string Line::ToString() const
{
    string s = "Line from ";
    s += p1.ToString() + " to " + p2.ToString();
    string shapeDescription = Shape::ToString(); // Shape description to be appended.
    s += ", " + shapeDescription + ".\n";
    return s;
}

double Line::Length() const
{
    return p1.Distance(p2);
}

Line& Line::operator=(const Line& source)
{
    Shape::operator=(source);
    p1 = source.p1;
    p2 = source.p2;
    return *this;
}

/* Exercise 2.4.2 ostream << operator */
ostream& operator<<(ostream& os, const Line& l)
{
    os << l.ToString();
    return os;
}