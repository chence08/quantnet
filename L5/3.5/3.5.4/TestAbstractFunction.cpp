/* Author: YiJia Chen */

#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

int main() {
    // Shape shape;
    /* It's not possible to create an instance of an abstract class. */

    Shape* shapes[3];
    shapes[0] = new Point;
    shapes[1] = new Line;
    shapes[2] = new Circle(Point(), 1);

    for (int i = 0; i != 3; i++) shapes[i]->Draw();
}
