/* Author: YiJia Chen */

#ifndef FUNCTOR_HPP
#define FUNCTOR_HPP

class Functor
{
private:
    double upperBound;

public:
    Functor(double upperBound)
    {
        this->upperBound = upperBound;
    }

    bool operator()(double input)
    {
        return input < upperBound;
    }
};

#endif