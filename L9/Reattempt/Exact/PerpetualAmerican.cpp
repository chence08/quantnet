#include "PerpetualAmerican.hpp"
#include <cmath>

PerpetualAmerican::PerpetualAmerican(double S, double K, double r, double sigma, double b) :
Option(S, K, 0, r, sigma, b)
{
}

double PerpetualAmerican::getCall() const
{
    double y = 1.0/2 - b/pow(sigma, 2)
    + sqrt(pow(b/pow(sigma, 2) - 1.0/2, 2) + 2*r/pow(sigma, 2));

    return K / (y-1) * pow(((y-1) * S) / (y * K), y);
}

double PerpetualAmerican::getPut() const
{
    double y = 1.0/2 - b/pow(sigma, 2)
    - sqrt(pow(b/pow(sigma, 2) - 1.0/2, 2) + 2*r/pow(sigma, 2));

    return K / (1-y) * pow(((y-1) * S) / (y * K), y);
}