/* Author: YiJia Chen */

#ifndef ARRAYEXCEPTION_HPP
#define ARRAYEXCEPTION_HPP

#include <string>
using namespace std;

class ArrayException
{
public:
    virtual string GetMessage() const = 0;
};

#endif