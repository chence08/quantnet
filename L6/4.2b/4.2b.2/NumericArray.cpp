/* Author: YiJia Chen */

#ifndef NUMERICARRAY_CPP
#define NUMERICARRAY_CPP

#include "NumericArray.hpp"
#include "DifferentSizeException.hpp"

template<typename T>
NumericArray<T>::NumericArray() : Array<T>::Array()
{
}

template<typename T>
NumericArray<T>::NumericArray(int size) : Array<T>::Array(size)
{
}

template<typename T>
NumericArray<T>::NumericArray(const NumericArray<T>& source) :
Array<T>::Array(source)
{
}

template<typename T>
NumericArray<T>::~NumericArray()
{
    /*
    By Destructor Chaining, when an object of a derived class is destroyed, 
    the derived class destructor is called. After it finishes its tasks, 
    it invokes its base class destructor. This process continues until 
    the last destructor along the inheritance hierarchy is called.
    */
}

template<typename T>
const NumericArray<T>& NumericArray<T>::operator=(const NumericArray<T>& source)
{
    if (this == &source)
        return *this;
    Array<T>::operator=(source);
    return *this;
}

template<typename T>
NumericArray<T> operator*(const NumericArray<T>& arr, double factor)
{
    NumericArray<T> result = arr;
    for (int i = 0; i < result.Size(); i++)
        result[i] *= factor;
    return result;
}

template<typename T>
NumericArray<T> operator+(const NumericArray<T>& arr1, const NumericArray<T>& arr2)
{
    try
    {
        if (arr1.Size() != arr2.Size())
            throw DifferentSizeException(arr1.Size(), arr2.Size());

    }
    catch(DifferentSizeException& ex)
    {
        cout << ex.GetMessage() << endl;
    }
    NumericArray<T> result = arr1;
    for (int i = 0; i < result.Size(); i++)
        result[i] += arr2[i];
    return result;
}

template<typename T>
T NumericArray<T>::DotProduct(const NumericArray<T>& arr1, const NumericArray<T>& arr2)
{
    try
    {
        if (arr1.Size() != arr2.Size())
            throw DifferentSizeException(arr1.Size(), arr2.Size());

    }
    catch(DifferentSizeException& ex)
    {
        cout << ex.GetMessage() << endl;
    }
    T result = arr1[0] * arr2[0];
    for (int i = 1; i < arr1.Size(); i++)
        result += arr1[i] * arr2[i];
    return result;
}

#endif