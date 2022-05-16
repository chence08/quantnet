/* Author: YiJia Chen */

#ifndef ARRAY_HPP
#define ARRAY_HPP

/*
1. Add a static data member to the Array class indicating the default size.
2. Initialise this static in the source file to a value.
3. Also add static functions to set and get the default size.
4. In the default constructor, use static default size variable instead of a 
literal value to set the array size.
*/

template<typename T>
class Array
{
private:
    T* m_data;
    int m_size;
    static int DEFAULT_SIZE;

public:
    Array();
    Array(int size);
    Array(const Array<T>&);
    ~Array();
    const Array<T>& operator=(const Array&);
    
    int Size() const;
    void SetElement(int index, const T& p);
    const T& GetElement(int index) const;
    /* return element by reference since the returned element has a
    longer lifetime than the GetElement() function. */
    
    T& operator[](int index);
    const T& operator[](int index) const;

    static void DefaultSize(int newSize);
    static int DefaultSize();
};

#ifndef ARRAY_CPP // Must be the same name as in source file #define
#include "Array.cpp"
#endif

#endif