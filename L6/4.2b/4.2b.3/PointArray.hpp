/* Author: YiJia Chen */

#ifndef POINTARRAY_HPP
#define POINTARRAY_HPP

#include "Array.cpp"
#include "Point.hpp"

// Concrete Inheritance
class PointArray: public Array<Point>
{
public:
    // Constructors, Destructors and Assignment Operator
    PointArray();
    PointArray(int size);
    PointArray(const PointArray&);
    ~PointArray();
    const PointArray& operator=(const PointArray&);

    double Length();
};

#endif