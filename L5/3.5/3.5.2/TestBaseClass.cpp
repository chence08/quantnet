/* Author: YiJia Chen */

#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

int main() {
    Point p(10, 20);
    Line l;
    Circle c(p, 1);

    Shape* sp; // Create pointer to a shape variable
    sp = &p;
    cout << sp->ToString() << endl; // What is printed?
    /*
    Point(10, 20)
    */

    sp = &l;
    cout << sp->ToString() << endl; // What is printed?
    /*
    Point(10, 20)
    */

    sp = &c;
    cout << sp->ToString() << endl; // What is printed?
    /*
    Point(10, 20)
    */
}