/* Author: YiJia Chen */

#ifndef ARRAY_HPP
#define ARRAY_HPP

/*
1. Declare Array class as a template of type T.
2. Replace all references to Point with T.
3. Where an array is used as input or output, replace Array by Array<T>.
*/

template<typename T>
class Array
{
private:
    T* m_data;
    int m_size;

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
};

#ifndef ARRAY_CPP // Must be the same name as in source file #define
#include "Array.cpp"
#endif
/*
The template can keep including the header file for template classes
instead of the source file.
Can you explain how this works?

When "Array.cpp" is included, it also includes the header file "Array.hpp".
*/

#endif