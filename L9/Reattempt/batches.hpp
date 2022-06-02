/* Author: YiJia Chen */

#ifndef BATCHES
#define BATCHES

#include <map>
using namespace std;

namespace batches
{
    map<string, double> b1 {
        {"sig", 0.3},
        {"K", 65},
        {"T", 0.25},
        {"r", 0.08},
        {"S", 60},
        {"C", 2.13337},
        {"P", 5.84628},
        {"b", 0.08}
    };

    map<string, double> b2 {
        {"sig", 0.2},
        {"K", 100},
        {"T", 1},
        {"r", 0},
        {"S", 100},
        {"C", 7.96557},
        {"P", 7.96557},
        {"b", 0}
    };

    map<string, double> b3 {
        {"sig", 0.5},
        {"K", 10},
        {"T", 1},
        {"r", 0.12},
        {"S", 5},
        {"C", 0.204058},
        {"P", 4.07326},
        {"b", 0.12}
    };

    map<string, double> b4 {
        {"sig", 0.3},
        {"K", 100},
        {"T", 30},
        {"r", 0.08},
        {"S", 100},
        {"C", 92.1757},
        {"P", 1.2475},
        {"b", 0.08}
    };

    map<string, double> s1 {
        {"sig", 0.36},
        {"K", 100},
        {"T", 0.5},
        {"r", 0.1},
        {"S", 105},
        {"C", 0.5946},
        {"P", -0.3566}
    };

    map<string, double> a1 {
        {"sig", 0.1},
        {"K", 100},
        {"r", 0.1},
        {"S", 110},
        {"C", 18.5035},
        {"P", 3.03106},
        {"b", 0.02}
    };
}

#endif