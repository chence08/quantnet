#ifndef PERPETUALAMERICAN_HPP
#define PERPETUALAMERICAN_HPP

#include "Option.hpp"

class PerpetualAmerican: public Option
{
public:
    PerpetualAmerican(double S, double K, double r, double sigma, double b);
    double getCall() const;
    double getPut() const;
};

#endif