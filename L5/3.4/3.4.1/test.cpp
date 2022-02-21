/* Author: Chen YiJia
Count the number of point constructor, destructor and assignment calls.
Compare them under colon and non-colon syntax.
*/

#include "Line_nonColon.hpp"
#include "Line_colonWithNonColonPoint.hpp"
#include "Line.hpp"

int main() {
    cout << "===Line before colon syntax===\n";
    Line_nonColon l1;
    cout << "\n===Line after colon syntax===\n";
    Line_colonWithNonColonPoint l2;
    cout << "\n===Both Point and Line now using the colon syntax===\n";
    Line l3;
}

/*
===Line before colon syntax===
[NON-COLON SYNTAX] No-args constructor invoked.
[NON-COLON SYNTAX] No-args constructor invoked.
[NON-COLON SYNTAX] No-args constructor invoked.
Assignment operator invoked.
[NON-COLON SYNTAX] Destructor invoked for Point_nonColon(0, 0)
[NON-COLON SYNTAX] No-args constructor invoked.
Assignment operator invoked.
[NON-COLON SYNTAX] Destructor invoked for Point_nonColon(0, 0)

===Line after colon syntax===
[NON-COLON SYNTAX] No-args constructor invoked.
[NON-COLON SYNTAX] No-args constructor invoked.

===Both Point and Line now using the colon syntax===
[COLON SYNTAX] No-args constructor invoked.
[COLON SYNTAX] No-args constructor invoked.
[COLON SYNTAX] Destructor invoked for Point(0, 0)
[COLON SYNTAX] Destructor invoked for Point(0, 0)
[NON-COLON SYNTAX] Destructor invoked for Point_nonColon(0, 0)
[NON-COLON SYNTAX] Destructor invoked for Point_nonColon(0, 0)
[NON-COLON SYNTAX] Destructor invoked for Point_nonColon(0, 0)
[NON-COLON SYNTAX] Destructor invoked for Point_nonColon(0, 0)

We can see from the output that before colon syntax, there were

4 constructors, 4 destructors and 2 assignment operators

invoked for the default constructors. After applying the colon syntax, there were

2 constructors, 2 destructors and 0 assignment operators.
*/