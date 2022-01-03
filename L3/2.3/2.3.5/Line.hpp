/* Author: YiJia Chen */

#ifndef LINE_HPP
#define LINE_HPP
#include "Point.hpp" // string library already included.

class Line
{
public:
    // Constructors
    Line();
    Line(const Point& p1, const Point& p2);
    Line(const Line&);

    ~Line(); // Destructor
    
    // Getters
    Point P1() const;
    Point P2() const;

    // Setters
    void P1(const Point& p1);
    void P2(const Point& p2);

    string ToString() const;
    double Length() const;

private:
    Point p1; // start
    Point p2; // end
};

#endif