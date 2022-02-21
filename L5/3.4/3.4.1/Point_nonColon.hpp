/* Author: YiJia Chen
Create a Point_nonColon class with x- and y-coordinates.
Avoid multiple inclusion. */

#ifndef POINT_NONCOLON_HPP
#define POINT_NONCOLON_HPP
#include <string>
#include <iostream> // for ostream << operator
using namespace std;

class Point_nonColon
{
public:
    Point_nonColon(); // Default constructor
    ~Point_nonColon(); // Destructor

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
    double Distance(const Point_nonColon& p) const; // Calculate the distance between two points.

    /* Exercise 2.3.1 */
    Point_nonColon(const Point_nonColon&); // Copy constructor
    Point_nonColon(double x, double y);

    /* Exercise 2.4.1 Adding Operators to the Point_nonColon class */
    Point_nonColon operator-() const; // Unary operator to negate the coordinates
    Point_nonColon operator*(double factor) const; // Binary operator to scale the coordinates
    Point_nonColon operator+(const Point_nonColon& p) const; // Add coordinates
    bool operator==(const Point_nonColon& p) const; // Equally compare relational operator
    Point_nonColon& operator=(const Point_nonColon& source); // Assignment operator
    Point_nonColon& operator*=(double factor); // Scale the coordinates & assign

    /* Exercise 2.4.4 ostream << operator */
    friend ostream& operator<<(ostream& os, const Point_nonColon& p);
    
private:
    double m_x;
    double m_y;
};

/* Normal inline functions for getters. */
inline double Point_nonColon::X() const
{
    return m_x;
};

inline double Point_nonColon::Y() const
{
    return m_y;
};

#endif