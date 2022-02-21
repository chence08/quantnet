/* Author: YiJia Chen */

#include "Array.hpp"
#include "OutOfBoundsException.hpp"

Array::Array()
{
    m_size = 10;
    m_data = new Point[m_size];
}

Array::Array(int size)
{
    m_size = size;
    m_data = new Point[m_size];
}

Array::Array(const Array& array)
{
    m_size = array.m_size;
    m_data = new Point[m_size]; // deep copy
    for (int i = 0; i < m_size; i++)
        m_data[i] = array.m_data[i];
}

Array::~Array()
{
    delete [] m_data;
}

const Array& Array::operator=(const Array& source)
{
    if (this == &source) // same pointer
        return *this;
    
    m_size = source.m_size;
    delete [] m_data; // delete old array
    m_data = new Point[m_size];
    for (int i = 0; i < m_size; i++)
        m_data[i] = source.m_data[i];
    return *this;
}

void Array::SetElement(int index, const Point& p)
{
    if (index >= 0 && index < m_size)
        m_data[index] = p;
    throw OutOfBoundsException(index);
}

Point& Array::GetElement(int index) const
{
    if (index >= 0 && index < m_size)
        return m_data[index];
    throw OutOfBoundsException(index);
}

Point& Array::operator[](int index)
{
    return GetElement(index);
}

const Point& Array::operator[](int index) const
{
    return GetElement(index);
}