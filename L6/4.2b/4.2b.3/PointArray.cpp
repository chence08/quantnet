/* Author: YiJia Chen */

#include "PointArray.hpp"

PointArray::PointArray() : Array<Point>::Array()
{
}

PointArray::PointArray(int size) : Array<Point>::Array(size)
{
}

PointArray::PointArray(const PointArray& source) :
Array<Point>::Array(source)
{
}

PointArray::~PointArray()
{
    /*
    By Destructor Chaining, when an object of a derived class is destroyed, 
    the derived class destructor is called. After it finishes its tasks, 
    it invokes its base class destructor. This process continues until 
    the last destructor along the inheritance hierarchy is called.
    */
}

const PointArray& PointArray::operator=(const PointArray& source)
{
    if (this == &source)
        return *this;
    Array<Point>::operator=(source);
    return *this;
}

// returns the total length between the points in the array.
/*
Interpreted to mean the total length between every pair of points.
*/
double PointArray::Length()
{
    double result = 0;
    for (int i = 0; i < Size(); i++)
    {
        for (int j = 0; j < Size(); j++)
        {
            result += (*this)[i].Distance((*this)[j]);
        }
    }
    return result;
}