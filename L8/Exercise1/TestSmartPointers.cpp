/*
Author: YiJia Chen

The boost::shared_ptr<T> class stores a pointer and will delete the object
automatically when nobody is referencing the object anymore. Thus instead of
creating an array of Shape* we can create an array with boost::shared_ptr<Shape>
and the deletion of the shapes will be done automatically.

1. Create a program that creates an array with shared pointers for shapes.
2. Fill it with various shapes and print them.
3. Check if the shapes are automatically deleted.
*/

#include <boost/shared_ptr.hpp>
#include "Array.cpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

// Typedef for a shared pointer to shape and
// a typedef for an array with shapes stored as shared pointers.
typedef boost::shared_ptr<Shape> ShapePtr;
typedef Array<ShapePtr> ShapeArray;

void testRegularPointers()
{
    cout << "=====Test Regular Pointers=====" << endl;
    Array<Shape*> arr(3);
    arr[0] = new Point();
    arr[1] = new Line();
    arr[2] = new Circle(Point(), 1);

    for (int i = 0; i < 3; i++)
        arr[i]->Print();
}

void testSharedPointer()
{
    cout << "=====Test Shared Pointers=====" << endl;
    ShapeArray arr(3);
    arr[0] = ShapePtr(new Point);
    arr[1] = ShapePtr(new Line);
    arr[2] = ShapePtr(new Circle(Point(), 1));

    for (int i = 0; i < 3; i++)
        arr[i]->Print();
}

int main()
{
    testRegularPointers();
    cout << endl;
    testSharedPointer();
}

/*
Output:
=====Test Regular Pointers=====
Destructor invoked for ID: 1144108930
Point(0, 0), ID: 16807
Line from Point(0, 0), ID: 1622650073 to Point(0, 0), ID: 984943658, ID: 282475249.

Circle of radius 1 centered at Point(0, 0), ID: 1144108930, ID: 470211272
Destructor invoked for Base Array!

=====Test Shared Pointers=====
Destructor invoked for ID: 823564440
Point(0, 0), ID: 101027544
Line from Point(0, 0), ID: 1458777923 to Point(0, 0), ID: 2007237709, ID: 1457850878.

Circle of radius 1 centered at Point(0, 0), ID: 823564440, ID: 1115438165
Destructor invoked for Base Array!
Destructor invoked for ID: 823564440
Destructor invoked for ID: 1115438165
Destructor invoked for ID: 2007237709
Destructor invoked for ID: 1458777923
Destructor invoked for ID: 1457850878
Destructor invoked for ID: 101027544

Evidently, the shapes are automatically deleted when using shared_ptr.
*/
