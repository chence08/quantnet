/* Author: YiJia Chen */

#ifndef STACK_HPP
#define STACK_HPP

#include "Array.cpp"

template<typename T, int size>
class Stack
{
private:
    int m_current;
    Array<T> arr;

public:
    Stack();
    ~Stack();
    const Stack<T, size>& operator=(const Stack&);
    friend ostream& operator<<(ostream& os, const Stack& stack)
    {
        return os << stack.arr;
    }

    /**
     * Store the element at the current position in the array.
     * Increment m_current afterwards.
     * Make sure m_current is not changed when Array threw an exception.
     */
    void Push(const T& element);

    /**
     * Decrements m_current and then returns the element at that position.
     */
    T& Pop();
};

#ifndef STACK_CPP
#include "Stack.cpp"
#endif

#endif