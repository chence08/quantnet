/*
Author: YiJia Chen
Compile with C++17

We simulate dice throwing. Create a discrete uniform random number generator
whose outcomes are in the closed range [1, 6].
*/

#include <boost/random.hpp>
#include <map>
#include <iostream>
using namespace std;

int main()
{
    // Throwing dice
    // Mersenne Twister
    boost::random::mt19937 myRng;

    // Set the seed
    myRng.seed(static_cast<boost::uint32_t> (time(0)));

    // Uniform in range [1, 6]
    boost::random::uniform_int_distribution<int> six(1, 6);

    map<int, long> statistics; // Structure to hold outcome + frequencies
    int outcome; // Current outcome

    int numTrials = 1E6;
    cout << "How many trials? " << numTrials << endl;
    for (int i = 0; i < numTrials; i++)
        statistics[six(myRng)]++;

    for (auto const& [key, val]: statistics)
        cout << "Trial " << key << " has " << 100 * (double) val / numTrials << "% outcomes\n";
}