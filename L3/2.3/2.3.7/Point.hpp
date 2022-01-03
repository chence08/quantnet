/* Author: YiJia Chen
Create a Point class with x- and y-coordinates.
Avoid multiple inclusion. */

#ifndef POINT_HPP
#define POINT_HPP
#include <string>
using namespace std;

class Point
{
public:
    Point(); // Default constructor
    ~Point(); // Destructor

    /* Exercise 2.3.3 
    - Rename DistanceOrigin to Distance.
    - Rename getter and setter to demonstrate function overloading. */
    // Getter functions
    double X() const;
    double Y() const;

    // Setter functions in default inline form.
    void X(double x) {this->m_x = x;};
    void Y(double y) {this->m_y = y;};

    string ToString() const;

    double Distance() const; // Calculate the distance between the origin (0, 0).
    double Distance(const Point& p) const; // Calculate the distance between two points.

    /* Exercise 2.3.1 */
    Point(const Point&); // Copy constructor
    Point(double x, double y);
    
private:
    double m_x;
    double m_y;
};

/* Normal inline functions for getters. */
inline double Point::X() const
{
    return m_x;
};

inline double Point::Y() const
{
    return m_y;
};

#endif