/* Author: YiJia Chen */

#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.hpp"
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"

template<typename T>
Stack<T>::Stack() : m_current(0), arr()
{
}

template<typename T>
Stack<T>::Stack(int size) : m_current(0), arr(size)
{
}

template<typename T>
Stack<T>::~Stack()
{
}

template<typename T>
const Stack<T>& Stack<T>::operator=(const Stack& source)
{
    if (this == &source)
        return *this;
    
    m_current = source.m_current;
    arr = source.arr;
    return *this;
}

template<typename T>
void Stack<T>::Push(const T& element)
{
    try
    {
        arr[m_current++] = element;
    }
    catch (ArrayException&)
    {
        m_current--;
        throw StackFullException();
    }
}

template<typename T>
T& Stack<T>::Pop()
{
    try
    {
        return arr[--m_current];
    }
    catch (ArrayException&)
    {
        m_current = 0;
        throw StackEmptyException();
    }
}

#endif