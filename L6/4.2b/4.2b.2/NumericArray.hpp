/* Author: YiJia Chen */

#ifndef NUMERICARRAY_HPP
#define NUMERICARRAY_HPP

#include "Array.cpp"

// Generic Inheritance
template<typename T>
class NumericArray: public Array<T>
{
public:
    // Constructors, Destructors and Assignment Operator
    NumericArray();
    NumericArray(int size);
    NumericArray(const NumericArray<T>&);
    ~NumericArray();
    const NumericArray<T>& operator=(const NumericArray<T>&);

    static T DotProduct(const NumericArray<T>& arr1, const NumericArray<T>& arr2);
};

template<typename T>
NumericArray<T> operator*(const NumericArray<T>& arr, double factor);

template<typename T>
NumericArray<T> operator+(const NumericArray<T>& arr1, const NumericArray<T>& arr2);

#ifndef NUMERICARRAY_CPP
#include "NumericArray.cpp"
#endif

#endif