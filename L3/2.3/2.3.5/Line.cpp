/* Author: YiJia Chen */

#include "Line.hpp"
#include <iostream>

Line::Line() : p1(), p2()
{
}

Line::Line(const Point& p1, const Point& p2) : p1(p1), p2(p2)
{
}

Line::Line(const Line& l) : p1(l.p1), p2(l.p2)
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
    s += p1.ToString() + " to " + p2.ToString() + ".\n";
    return s;
}

double Line::Length() const
{
    return p1.Distance(p2);
}