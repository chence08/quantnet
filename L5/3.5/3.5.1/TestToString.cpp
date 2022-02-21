/* Author: YiJia Chen */

#include "Shape.hpp"
#include "Point.hpp"

int main() {
    Point p(10, 20);

    Shape* sp; // Create pointer to a shape variable
    sp = &p;
    cout << sp->ToString() << endl; // What is printed?
    /*
    Point(10, 20)
    */
}