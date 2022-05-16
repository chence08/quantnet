/* Author: YiJia Chen */

#ifndef STACKEMPTYEXCEPTION_HPP
#define STACKEMPTYEXCEPTION_HPP

#include "StackException.hpp"

class StackEmptyException: public StackException
{
public:
    string GetMessage() const
    {
        return "Stack is Empty!";
    }
};

#endif