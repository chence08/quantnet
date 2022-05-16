/* Author: YiJia Chen */

#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.hpp"
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"

template<typename T, int size>
Stack<T, size>::Stack() : m_current(0), arr(size)
{
}

template<typename T, int size>
Stack<T, size>::~Stack()
{
}

template<typename T, int size>
const Stack<T, size>& Stack<T, size>::operator=(const Stack& source)
{
    if (this == &source)
        return *this;
    
    m_current = source.m_current;
    arr = source.arr;
    return *this;
}

template<typename T, int size>
void Stack<T, size>::Push(const T& element)
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

template<typename T, int size>
T& Stack<T, size>::Pop()
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