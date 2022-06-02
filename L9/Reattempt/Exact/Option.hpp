#ifndef OPTION_HPP
#define OPTION_HPP

class Option
{
protected:
    double S; // asset price
    double K; // strike price
    double T; // maturity date
    double r; // risk-free interest rate == b (cost of carry)
    double sigma; // constant volatility
    double b;

public:
    Option(double S, double K, double T, double r, double sigma, double b);

    virtual double getCall() const = 0;
    virtual double getPut() const = 0;
};

#endif