#include "European.hpp"
#include <cmath>

European::European(double S, double K, double T, double r, double sigma) :
Option(S, K, T, r, sigma, r)
{
}

double European::d1() const
{
    return (log(S / K) + (b + sigma*sigma / 2) * T) 
        / (sigma * sqrt(T));
}

double European::d2() const
{
    return d1() - sigma * sqrt(T);
}

double European::getCall() const
{
    using namespace boost::math;
    return S * exp((b - r) * T) * cdf(NORMAL, d1()) - K * exp(-r*T) * cdf(NORMAL, d2());
}

double European::getPut() const
{
    using namespace boost::math;
    return K * exp(-r*T) * cdf(NORMAL, -d2()) - S * cdf(NORMAL, -d1());
}

double European::getCallFromParity(double put) const
{
    return put + S - K * exp(-r*T);
}

double European::getPutFromParity(double call) const
{
    return call + K * exp(-r*T) - S;
}

bool European::satisfyParity() const
{
    return abs(getCall() + K * exp(-r*T) - getPut() - S) < 1E-7;
}

double European::getDeltaCall()
{
    b = 0;
    return exp(-r*T) * cdf(NORMAL, d1());
}

double European::getDeltaPut()
{
    b = 0;
    return exp(-r*T) * (cdf(NORMAL, d1()) - 1);
}

double European::getGamma()
{
    b = 0;
    return (pdf(NORMAL, d1()) * exp(-r*T)) / (S * sigma * sqrt(T));
}

double European::dividedDifferenceDelta(double h, string type)
{
    double v1, v2;
    double p1 = S + h;
    double p2 = S - h;
    S = p1;
    if (type == "call")
    {
        v1 = getCall();
        S = p2;
        v2 = getCall();
    }
    else if (type == "put")
    {
        v1 = getPut();
        S = p2;
        v2 = getPut();
    }
    return (v1 - v2) / (2*h);
}

double European::dividedDifferenceGamma(double h)
{
    double v1, v3;
    double v2 = getCall();
    double p1 = S + h;
    double p3 = S - h;
    S = p1; v1 = getCall();
    S = p3; v3 = getCall();
    return (v1 - 2*v2 + v3) / (2*h);
}