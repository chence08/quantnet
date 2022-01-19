/* Author: YiJia Chen */

#include <iostream>
#include "Point.hpp"

int main() {
    Point p(1.0, 1.0);
    if (p == (Point) 1.0) cout << "Equal!" << endl;
    else cout << "Not equal" << endl;
    /* This yields Equal! at first due to implicit conversion operators.
    After explicit modifier, it yields compiler error unless 1.0 is explicit cast to a Point.
    */
}