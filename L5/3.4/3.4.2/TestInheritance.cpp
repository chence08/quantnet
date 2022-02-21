/* Author: YiJia Chen */

#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"

int main() {
    Shape s;
    Point p(10, 20);
    Line l(Point(1, 2), Point(3, 4));

    cout << s.ToString() << endl;
    cout << p.ToString() << endl;
    cout << l.ToString() << endl;

    cout << "Shape ID: " << s.ID() << endl;
    cout << "Point ID: " << p.ID() << endl; // ID of the point. Does this work?
    /* Yes. */
    cout << "Line ID: " << l.ID() << endl; // ID of the line. Does this work?
    /* Yes. */

    Shape* sp; // Create pointer to a shape variable
    sp = &p;
    cout << sp->ToString() << endl; // What is printed?
    /*
    ID: 282475249

    282475249 is generated by rand() from <stdlib.h>.
    The ToString method of Shape is invoked instead of Point.
    */

    // Create and copy Point p to a new point.
    Point p2;
    p2 = p;
    cout << p2 << ", " << p2.ID() << endl;
    /*
    Is the ID copied if you do not call the base class assignment in point?
    No, it will not be copied.
    It will just take on the value that was initialized by p2 instead.
    */
}