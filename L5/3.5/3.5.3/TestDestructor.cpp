/* Author: YiJia Chen */

#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"

int main() {
    Shape* shapes[3];
    shapes[0] = new Shape;
    shapes[1] = new Point;
    shapes[2] = new Line;

    for (int i = 0; i != 3; i++) delete shapes[i];
}

/*
===Before virtual===
Destructor invoked for ID: 16807
Destructor invoked for ID: 282475249
Destructor invoked for ID: 1622650073

===After virtual===
Destructor invoked for ID: 16807
Destructor invoked for Point(0, 0), ID: 282475249
Destructor invoked for ID: 282475249
Destructor invoked for Line from Point(0, 0), ID: 984943658 to Point(0, 0), ID: 1144108930, ID: 1622650073.

Destructor invoked for Point(0, 0), ID: 1144108930
Destructor invoked for ID: 1144108930
Destructor invoked for Point(0, 0), ID: 984943658
Destructor invoked for ID: 984943658
Destructor invoked for ID: 1622650073

---

The proper destructors are called after declaring the base class destructor virtual.
*/