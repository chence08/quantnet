#ifndef EUROPEAN_HPP
#define EUROPEAN_HPP

#include "Option.hpp"
#include <boost/math/distributions/normal.hpp>
using namespace std;

class European: public Option
{
private:
    static inline const boost::math::normal_distribution<> NORMAL;

public:
    European(double S, double K, double T, double r, double sigma);
    double getCall() const;
    double getPut() const;

    double d1() const;
    double d2() const;

    double getCallFromParity(double put) const;
    double getPutFromParity(double call) const;
    bool satisfyParity() const;

    // Future Option Pricing, i.e. b = 0;
    double getDeltaCall();
    double getDeltaPut();
    double getGamma();

    double dividedDifferenceDelta(double h, string type);
    double dividedDifferenceGamma(double h);
};

#endif