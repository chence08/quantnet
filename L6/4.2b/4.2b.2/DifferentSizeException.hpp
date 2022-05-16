#ifndef DIFFERENTSIZEEXCEPTION_HPP
#define DIFFERENTSIZEEXCEPTION_HPP

#include "ArrayException.hpp"
#include <sstream>

class DifferentSizeException: public ArrayException
{
private:
    int size1;
    int size2;

public:
    DifferentSizeException(int size1, int size2): size1(size1), size2(size2) {}

    string GetMessage() const
    {
        stringstream ss;
        ss << "Arrays have different sizes " << size1 << " and " << size2;
        return ss.str();
    }
};

#endif