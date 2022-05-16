/* Author: YiJia Chen */

/*
1. Every function must be declared as a template of type T.
2. The functions are now not a member of Array anymore but a member of Array<T>.
3. Further replace all references to Point with T.
4. Finally where an array is used as input or output, replace Array by Array<T>.
5. Don't forget that the test program shoud now include the source file instead
of the header file. Therefore the source file should now also include
#ifndef/#define/#endif statements.
*/

#ifndef ARRAY_CPP
#define ARRAY_CPP

#include "Array.hpp"
#include "OutOfBoundsException.hpp"

template<typename T>
int Array<T>::DEFAULT_SIZE = 10;

template<typename T>
Array<T>::Array()
{
    m_size = DEFAULT_SIZE;
    m_data = new T[m_size];
}

template<typename T>
Array<T>::Array(int size)
{
    m_size = size;
    m_data = new T[m_size];
}

template<typename T>
Array<T>::Array(const Array<T>& array)
{
    m_size = array.m_size;
    m_data = new T[m_size]; // deep copy
    for (int i = 0; i < m_size; i++)
        m_data[i] = array.m_data[i];
}

template<typename T>
Array<T>::~Array()
{
    delete [] m_data;
}

template<typename T>
const Array<T>& Array<T>::operator=(const Array& source)
{
    if (this == &source) // same pointer
        return *this;
    
    m_size = source.m_size;
    delete [] m_data; // delete old array
    m_data = new T[m_size];
    for (int i = 0; i < m_size; i++)
        m_data[i] = source.m_data[i];
    return *this;
}

template<typename T>
int Array<T>::Size() const
{
    return m_size;
}

template<typename T>
void Array<T>::SetElement(int index, const T& p)
{
    if (index >= 0 && index < m_size)
        m_data[index] = p;
    throw OutOfBoundsException(index);
}

template<typename T>
const T& Array<T>::GetElement(int index) const
{
    if (index >= 0 && index < m_size)
        return m_data[index];
    throw OutOfBoundsException(index);
}

template<typename T>
T& Array<T>::operator[](int index)
{
    if (index >= 0 && index < m_size)
        return m_data[index];
    throw OutOfBoundsException(index);
}

template<typename T>
const T& Array<T>::operator[](int index) const
{
    return GetElement(index);
}

template<typename T>
void Array<T>::DefaultSize(int newSize)
{
    DEFAULT_SIZE = newSize;
}

template<typename T>
int Array<T>::DefaultSize()
{
    return DEFAULT_SIZE;
}

#endif