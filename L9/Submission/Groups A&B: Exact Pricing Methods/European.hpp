/* Author: YiJia Chen */

#ifndef EUROPEAN_HPP
#define EUROPEAN_HPP

#include <boost/math/distributions/normal.hpp>
#include <boost/tuple/tuple.hpp>
using namespace std;

typedef boost::tuple<vector<double>, vector<double>> priceVectors;

/**
 * Black-Scholes stock option model
 */
class European
{
private:
    double S; // asset price
    double K; // strike price
    double T; // maturity date
    double r; // risk-free interest rate == b (cost of carry)
    double sig; // constant volatility
    double b;

    double d1;
    double d2;
    
    // Standard Normal
    static inline const boost::math::normal_distribution<> NORMAL;

public:
    European(double S, double K, double T, double r, double sig, double b);

    // partA
    double getCall() const;
    double getPut() const;
    
    // part B
    double getCallFromParity(double put) const;
    double getPutFromParity(double call) const;
    bool satisfyParity();

    // partC
    void set_S(double newS)
    {
        S = newS;
        d1 = (log(S / K) + (r + sig*sig / 2) * T) 
        / (sig * sqrt(T));
        d2 = d1 - sig * sqrt(T);
    };
    void set_K(double newK)
    {
        K = newK;
        d1 = (log(S / K) + (r + sig*sig / 2) * T) 
        / (sig * sqrt(T));
        d2 = d1 - sig * sqrt(T);
    };
    void set_T(double newT)
    {
        T = newT;
        d1 = (log(S / K) + (r + sig*sig / 2) * T) 
        / (sig * sqrt(T));
        d2 = d1 - sig * sqrt(T);
    };
    void set_r(double newr)
    {
        r = newr;
        d1 = (log(S / K) + (r + sig*sig / 2) * T) 
        / (sig * sqrt(T));
        d2 = d1 - sig * sqrt(T);
    };
    void set_sig(double newsig)
    {
        sig = newsig;
        d1 = (log(S / K) + (r + sig*sig / 2) * T) 
        / (sig * sqrt(T));
        d2 = d1 - sig * sqrt(T);
    };
    priceVectors computeRange(const vector<double>& range, const int parameter);

    double getDeltaCall() const;
    double getDeltaPut() const;
    double getGamma() const;
};

#endif