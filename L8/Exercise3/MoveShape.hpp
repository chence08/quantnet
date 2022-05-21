/* Author: YiJia Chen */

#ifndef MOVESHAPE_HPP
#define MOVESHAPE_HPP

#include <boost/variant.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

/**
 * 1. Create a variant visitor that moves the shapes. The vistor is derived from
 * boost::static_visitor<void> and must have members for the x- and y-offset that are
 * set in the constructor.
 * 2. For each shape, create an operator() that changes the coordinates of the shape.
 */
class MoveShape: public boost::static_visitor<void>
{
private:
    double x_offset;
    double y_offset;

public:
    MoveShape(double x_offset, double y_offset);
    void operator()(Point&) const;
    void operator()(Line&) const;
    void operator()(Circle&) const;
};

#endif