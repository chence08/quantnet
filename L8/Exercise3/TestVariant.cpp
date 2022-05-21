/*
Author: YiJia Chen

In contrast to tuple, a boost::variant stores one value that can be one of the
specified types. It is thus similar to a C union but it is type safe.

Create a function that ask the user what kind of shape to create and returns that.
In this case we can return the created shape as `Shape*` because all shapes have
a common base class but that involves creating the shapes with `new`.
Instead, we can return the create shape a boost::variant which would also be needed
if the shapes did not have a common base class.

---

Checking what kind a type is stored in the variant is cumbersome. Therefore, the
boost::variant supports visitors.
*/

#include <boost/variant.hpp>
#include "MoveShape.hpp" // visitor
#include <vector>

typedef boost::variant<Point, Line, Circle> ShapeType;

/**
 * 1. Create a typedef for a ShapeType variant that contain a Point, Line or Circle.
 * 2. Create a function that returns the variant. Within this function ask the user
 * for the shape type to create.
 * 3. Create the requested shape and assign it to the variant and return it.
 */
ShapeType createShape()
{
    int choice;
    cout << "[1] Point\n[2] Line\n[3] Circle\nChoose shape: ";
    cin >> choice;

    ShapeType shape;
    switch (choice)
    {
        case 1: shape = Point(); break;
        case 2: shape = Line(); break;
        case 3: shape = Circle(Point(), 1); break;
        default: cout << "Invalid choice!" << endl; exit(1);
    }
    return shape;
}

/**
 * 1. Call the function and print the result by sending it to cout.
 * 2. Try to assign the variant to a Line variable by using the global boost::get<T>() function.
 * This will throw a boost::bad_get exception when the variant didn't contain a line.
 * 
 * ---
 * 
 * 1. Create an instance of the visitor and use the boost::apply_visitor(visitor, variant)
 * global function to move the shape.
 * 2. Print the shape afterwards to check if the visitor indeed changed the coordinates.
 */
int main()
{
    ShapeType createdShape = createShape();
    cout << "You have created a " << createdShape << endl;
    try
    {
        Line l = boost::get<Line>(createdShape);
    }
    catch(boost::bad_get& e)
    {
        cerr << e.what() << '\n';
    }
    
    // ---

    cout << "\n=====Testing visitor=====" << endl;
    vector<ShapeType> v {Point(), Line(), Circle(Point(), 1)};
    cout << "Before moving..." << endl;
    for (ShapeType s: v)
        cout << s << endl;
    
    MoveShape moveShape(0.5, -0.5);
    cout << "\nAfter moving..." << endl;
    for (ShapeType s: v)
    {
        boost::apply_visitor(moveShape, s);
        cout << s << endl;
    }
}