/* Author: YiJia Chen */

#ifndef STACKFULLEXCEPTION_HPP
#define STACKFULLEXCEPTION_HPP

#include "StackException.hpp"

class StackFullException: public StackException
{
public:
    string GetMessage() const
    {
        return "Stack is Full!";
    }
};

#endif