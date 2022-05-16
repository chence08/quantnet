/* Author: YiJia Chen */

#ifndef OUTOFBOUNDSEXCEPTION_HPP
#define OUTOFBOUNDSEXCEPTION_HPP

#include "ArrayException.hpp"
#include <sstream>

class OutOfBoundsException: public ArrayException
{
private:
    int m_index;

public:
    OutOfBoundsException(int erroneousIndex): m_index(erroneousIndex) {}

    string GetMessage() const
    {
        stringstream ss;
        ss << "Index " << m_index << " is out of bounds!";
        return ss.str();
    }
};

#endif