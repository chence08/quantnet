/* Author: YiJia Chen */

#include <iostream>

#include "../batches.hpp"
#include "European.hpp"

typedef vector<vector<double>> matrix;

bool compareDouble(double d1, double d2)
{
    return abs(d1 - d2) < 1E-5;
}

void partA(map<string, double> b)
{
    European e(
        b["S"],
        b["K"],
        b["T"],
        b["r"],
        b["sig"],
        b["b"]
    );
    const double call = e.getCall();
    const double put = e.getPut();
    cout << "Compute Call: " << call << " Correct Call: " << b["C"] << 
    " Check: " << (compareDouble(call, b["C"]) ? "Passed!" : "Failed!") << endl;
    cout << "Compute Put: " << put << " Correct Put: " << b["P"] << 
    " Check: " << (compareDouble(put, b["P"]) ? "Passed!" : "Failed!") << endl;
}

/**
 * 1. Calculate the call (or put) price for a corresponding put (or call) price AND
 * 2. Check if a given set of put/call prices satisfy parity
 */
void partB(map<string, double> b)
{
    European e(
        b["S"],
        b["K"],
        b["T"],
        b["r"],
        b["sig"],
        b["b"]
    );
    const double call = e.getCallFromParity(b["P"]);
    const double put = e.getPutFromParity(b["C"]);
    cout << "Compute Call: " << call << " Correct Call: " << b["C"] << 
    " Check: " << (compareDouble(call, b["C"]) ? "Passed!" : "Failed!") << endl;
    cout << "Compute Put: " << put << " Correct Put: " << b["P"] << 
    " Check: " << (compareDouble(put, b["P"]) ? "Passed!" : "Failed!") << endl;
    cout << "Parity Check: " << (e.satisfyParity() ? "Passed!" : "Failed!") << endl;
}

vector<double> createMesh(double start, int steps, double h)
{
    vector<double> result;
    for (int i = 0; i < steps; i++)
        result.push_back(start + h * i);
    return result;
}

// partD
matrix matrixPricer(matrix parameters)
{
    if (parameters.size() != 6)
        exit(1);
    int numRows = parameters[0].size();
    for (vector<double> v: parameters)
    {
        if (v.size() != numRows)
            exit(1);
    }

    vector<double> calls;
    vector<double> puts;
    for (int r = 0; r < numRows; r++)
    {
        European e(
            parameters[0][r],
            parameters[1][r],
            parameters[2][r],
            parameters[3][r],
            parameters[4][r],
            parameters[5][r]
        );
        calls.push_back(e.getCall());
        puts.push_back(e.getPut());
    }
    matrix result;
    result.push_back(calls);
    result.push_back(puts);
    return result;
}

// =============================================================================

void GreekA(map<string, double> b)
{
    European e(
        b["S"],
        b["K"],
        b["T"],
        b["r"],
        b["sig"],
        b["b"]
    );
    cout << "Delta Call: " << e.getDeltaCall() << endl;
    cout << "Delta Put: " << e.getDeltaPut() << endl;
}

int main()
{
    cout << "a) Check call and put option prices." << endl;
    cout << "BATCH 1" << endl;
    partA(batches::b1);
    cout << "BATCH 2" << endl;
    partA(batches::b2);
    cout << "BATCH 3" << endl;
    partA(batches::b3);
    cout << "BATCH 1" << endl;
    partA(batches::b4);

    cout << "\nb) Check put-call parity correctness" << endl;
    cout << "BATCH 1" << endl;
    partB(batches::b1);
    cout << "BATCH 2" << endl;
    partB(batches::b2);
    cout << "BATCH 3" << endl;
    partB(batches::b3);
    cout << "BATCH 1" << endl;
    partB(batches::b4);

    cout << "\nc) Compute option price for a range of stock prices." << endl;
    vector<double> stockPrices = createMesh(10, 41, 1); // 10, 11, ..., 50
    European e1(
        batches::b1["S"],
        batches::b1["K"],
        batches::b1["T"],
        batches::b1["r"],
        batches::b1["sig"],
        batches::b1["b"]
    );
    cout << "Using Batch 1..." << endl;
    priceVectors prices = e1.computeRange(stockPrices, 1); // generalised for any pricing parameters.

    cout << "=====GREEKS=====" << endl;
    GreekA(batches::s1);
}