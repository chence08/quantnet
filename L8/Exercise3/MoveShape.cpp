/* Author: YiJia Chen */

#include "MoveShape.hpp"

MoveShape::MoveShape(double x_offset, double y_offset) : x_offset(x_offset), y_offset(y_offset)
{
}

void MoveShape::operator()(Point& p) const
{
    p.X(p.X() + x_offset);
    p.Y(p.Y() + y_offset);
}

void MoveShape::operator()(Line& l) const
{
    Point p1 = l.P1();
    Point p2 = l.P2();
    operator()(p1);
    operator()(p2);
    l.P1(p1);
    l.P2(p2);
}

void MoveShape::operator()(Circle& c) const
{
    Point centre = c.CentrePoint();
    operator()(centre);
    c.CentrePoint(centre);
}