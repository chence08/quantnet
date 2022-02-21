/* Author: YiJia Chen */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include "Point.hpp"

class Array
{
private:
    Point* m_data;
    int m_size;

public:
    Array();
    Array(int size);
    Array(const Array&);
    ~Array();
    const Array& operator=(const Array&);
    
    int Size() const;
    void SetElement(int index, const Point& p);
    Point& GetElement(int index) const;
    /* return element by reference since the returned element has a
    longer lifetime than the GetElement() function. */
    
    Point& operator[](int index);
    const Point& operator[](int index) const;
};

inline int Array::Size() const
{
    return m_size;
};

#endif