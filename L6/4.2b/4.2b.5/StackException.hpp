/* Author: YiJia Chen */

#ifndef STACKEXCEPTION_HPP
#define STACKEXCEPTION_HPP

#include <string>
using namespace std;

class StackException
{
public:
    virtual string GetMessage() const = 0;
};

#endif