/* Author: YiJia Chen */

#ifndef LINE_NONCOLON_HPP
#define LINE_NONCOLON_HPP
#include "Point_nonColon.hpp" // string library already included.

class Line_nonColon
{
public:
    // Constructors
    Line_nonColon();
    Line_nonColon(const Point_nonColon& p1, const Point_nonColon& p2);
    Line_nonColon(const Line_nonColon&);

    ~Line_nonColon(); // Destructor
    
    // Getters
    Point_nonColon P1() const;
    Point_nonColon P2() const;

    // Setters
    void P1(const Point_nonColon& p1);
    void P2(const Point_nonColon& p2);

    string ToString() const;
    double Length() const;

    /* Exercise 2.4.1 */
    Line_nonColon& operator=(const Line_nonColon& source);

    /* Exercise 2.4.4 ostream << operator */
    friend ostream& operator<<(ostream& os, const Line_nonColon& l);

private:
    Point_nonColon p1; // start
    Point_nonColon p2; // end
};

#endif