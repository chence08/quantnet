/* Author: YiJia Chen */

#include "Shape.hpp"
#include <stdlib.h>
#include <sstream> // for ToString function to convert numbers to strings.
#include <iostream>

Shape::Shape() : m_id(rand())
{
}

Shape::Shape(const Shape& s) : m_id(s.m_id)
{
}

Shape& Shape::operator=(const Shape& source)
{
    m_id = source.m_id;
    return *this;
}

string Shape::ToString() const
{
    stringstream ss;
    ss << "ID: " << m_id;
    return ss.str();
}

Shape::~Shape()
{
    // cout << "Destructor invoked for " << ToString() << endl;
}

void Shape::Print() const
{
    cout << ToString() << endl;
}