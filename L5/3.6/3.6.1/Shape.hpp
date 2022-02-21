/* Author: YiJia Chen */

#ifndef SHAPE_HPP
#define SHAPE_HPP

// for ToString() function
#include <string>
using namespace std;

class Shape
{
public:
    // Constructors
    Shape();
    Shape(const Shape&);

    // Assignment operator
    Shape& operator=(const Shape& source);

    /*
    To make the compiler generate the required code to find out what type of
    object Shape *variable is actually pointing to so it can call the right version;
    we need to declare the function as virtual.
    */
    virtual string ToString() const;

    int ID() const;

    // Destructor
    virtual ~Shape();

    virtual void Draw() const = 0; // pure virtual function

    void Print() const;

private:
    int m_id;
};

inline int Shape::ID() const
{
    return m_id;
};

#endif