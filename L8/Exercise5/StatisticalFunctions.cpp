/*
Author: YiJia Chen

Experiment with exponential and Poisson distributions that have many applications
to queueing theory, scheduling and jump (Levy) processes in finance.
*/

#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <iostream>
using namespace std;

int main()
{
    // Don't forget to tell compiler which namespace
    using namespace boost::math;

    // EXPONENTIAL DISTRIBUTION ------------------------------------------------
    cout << "EXPONENTIAL DISTRIBUTION" << endl;
    double scaleParameter = 0.5;

    // Default type is 'double'
    exponential_distribution<> myExponential(scaleParameter);

    cout << "Mean:" << mean(myExponential)
         << ",standard deviation "
         << standard_deviation(myExponential) << endl;

    // Distributional properties
    double x = 10.25;
    cout << "median: " << median(myExponential) << endl;
    cout << "mode: " << mode(myExponential) << endl;
    cout << "kurtosis excess: " << kurtosis_excess(myExponential) << endl;
    cout << "kurtosis: " << kurtosis(myExponential) << endl;
    cout << "characteristic function: " << chf(myExponential, x) << endl;
    cout << "hazard: " << hazard(myExponential, x) << endl;

    // POISSON DISTRIBUTION ----------------------------------------------------
    cout << "\n\nPOISSON DISTRIBUTION" << endl;
    double mean = 3.0;
    poisson_distribution<double> myPoisson(mean);

    double val = 13.0;
    cout << endl
         << "pdf: " << pdf(myPoisson, val) << endl;
    cout << "cdf: " << cdf(myPoisson, val) << endl;

    vector<double> pdfList;
    vector<double> cdfList;

    double start = 0.0;
    double end = 10.0;
    long N = 30; // Number of subdivisions

    val = 0.0;
    double h = (end - start) / double(N);

    for (long j = 1; j <= N; ++j)
    {
        pdfList.push_back(pdf(myPoisson, val));
        cdfList.push_back(cdf(myPoisson, val));

        val += h;
    }

    for (long j = 0; j < pdfList.size(); ++j)
    {
        cout << pdfList[j] << ", ";
    }

    cout << "***" << endl;

    for (long j = 0; j < cdfList.size(); ++j)
    {
        cout << cdfList[j] << ", ";
    }

    return 0;
}