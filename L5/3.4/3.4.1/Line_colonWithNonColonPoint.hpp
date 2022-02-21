/* Author: YiJia Chen */

#ifndef LINE_COLON_WITH_NONCOLON_POINT_HPP
#define LINE_COLON_WITH_NONCOLON_POINT_HPP
#include "Point_nonColon.hpp" // string library already included.

class Line_colonWithNonColonPoint
{
public:
    // Constructors
    Line_colonWithNonColonPoint();
    Line_colonWithNonColonPoint(const Point_nonColon& p1, const Point_nonColon& p2);
    Line_colonWithNonColonPoint(const Line_colonWithNonColonPoint&);

    ~Line_colonWithNonColonPoint(); // Destructor
    
    // Getters
    Point_nonColon P1() const;
    Point_nonColon P2() const;

    // Setters
    void P1(const Point_nonColon& p1);
    void P2(const Point_nonColon& p2);

    string ToString() const;
    double Length() const;

    /* Exercise 2.4.1 */
    Line_colonWithNonColonPoint& operator=(const Line_colonWithNonColonPoint& source);

    /* Exercise 2.4.4 ostream << operator */
    friend ostream& operator<<(ostream& os, const Line_colonWithNonColonPoint& l);

private:
    Point_nonColon p1; // start
    Point_nonColon p2; // end
};

#endif