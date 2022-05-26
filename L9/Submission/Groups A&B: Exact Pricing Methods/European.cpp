/* Author: YiJia Chen */

#include "European.hpp"
#include <cmath>
#include <iostream>

European::European(double S, double K, double T, double r, double sig, double b) :
S(S), K(K), T(T), r(r), sig(sig), b(b)
{
    d1 = (log(S / K) + (r + sig*sig / 2) * T) 
        / (sig * sqrt(T));
    
    d2 = d1 - sig * sqrt(T);
}

double European::getCall() const
{
    using namespace boost::math;
    return S * exp((b - r) * T) * cdf(NORMAL, d1) - K * exp(-r*T) * cdf(NORMAL, d2);
}

double European::getPut() const
{
    using namespace boost::math;
    return K * exp(-r*T) * cdf(NORMAL, -d2) - S * cdf(NORMAL, -d1);
}

double European::getCallFromParity(double put) const
{
    return put + S - K * exp(-r*T);
}

double European::getPutFromParity(double call) const
{
    return call + K * exp(-r*T) - S;
}

bool European::satisfyParity()
{
    return abs(getCall() + K * exp(-r*T) - getPut() - S) < 1E-7;
}

priceVectors European::computeRange(const vector<double>& range, const int parameter)
{
    vector<double> calls;
    vector<double> puts;
    European temp(*this);
    for (double x: range)
    {
        switch (parameter)
        {
            case 1: temp.set_S(x); break;
            case 2: temp.set_K(x); break;
            case 3: temp.set_T(x); break;
            case 4: temp.set_r(x); break;
            case 5: temp.set_sig(x); break;
            default: cout << "Invalid parameter!" << endl; exit(1);
        }
        double call = temp.getCall();
        double put = temp.getPut();
        cout << x << " Call: " << call << " Put: " << put << endl;
        calls.push_back(call);
        puts.push_back(put);
    }
    return {calls, puts};
}

double European::getDeltaCall() const
{
    return exp((b - r) * T) * cdf(NORMAL, d1);
}

double European::getDeltaPut() const
{
    return exp((b - r) * T) * (cdf(NORMAL, d1) - 1);
}

double European::getGamma() const
{
    return (pdf(NORMAL, d1) * exp((b - r) * T)) / (S * sig * sqrt(T));
}