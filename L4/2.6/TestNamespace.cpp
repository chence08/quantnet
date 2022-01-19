/* Author: YiJia Chen */

#include <iostream>
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"

int main() {
    // 1) Full namespace for Point class
    YiJia::CAD::Point p1, p2(1, 2);
    cout << "p1 = " << p1 << ", p2 = " << p2 << endl;

    // 2) 'using' declaration for Line class
    using YiJia::CAD::Line;
    Line l(p1, p2);
    cout << "\nl = " << l << endl;

    // 3) 'using' declaration for a Containers namespace
    using namespace YiJia::Containers;
    Array arr;
    arr.SetElement(1, p2);
    cout << "Elements in arr:" << endl;
    for (int i = 0; i < arr.Size(); i++)
        cout << "index " << i << ": " << arr[i] << endl;

    // 4) Using the circle class, create a shorter alias for YiJia::CAD namespace
    namespace YJ = YiJia::CAD;
    YJ::Circle c(p1, 5);
    cout << "\nc = " << c << endl;
}