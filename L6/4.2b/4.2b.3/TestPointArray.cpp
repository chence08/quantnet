/* Author: YiJia Chen */

#include "PointArray.hpp"

int main()
{
    PointArray arr(3);
    arr[1] = Point(0, 1);
    arr[2] = Point(0, -1);

    cout << "Calculate the total distances between\n" << arr <<
    "\n\nTotal Distance: " << arr.Length() << endl;
}