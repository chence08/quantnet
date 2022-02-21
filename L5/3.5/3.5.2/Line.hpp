/* Author: YiJia Chen */

#ifndef LINE_HPP
#define LINE_HPP
#include "Point.hpp" // string library already included.
#include "Shape.hpp"

class Line: public Shape
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

    /* Exercise 2.4.1 */
    Line& operator=(const Line& source);

    /* Exercise 2.4.4 ostream << operator */
    friend ostream& operator<<(ostream& os, const Line& l);

private:
    Point p1; // start
    Point p2; // end
};

#endif