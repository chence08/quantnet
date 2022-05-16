/* Author: YiJia Chen */

#include "NumericArray.hpp"
#include "Point.hpp"

int main()
{
    NumericArray<double> arr1;
    NumericArray<double> arr2;
    for (int i = 0; i < arr1.Size(); i++)
    {
        arr1[i] = 2;
        arr2[i] = 2;
    }

    NumericArray<double> arr3;

    arr3 = arr1 + arr2; // array of ten "4"
    cout << arr3 << endl;
    arr1 = arr1 * 3.1; // array of ten "6.2"
    cout << arr1 << endl;

    double dp = NumericArray<double>::DotProduct(arr1, arr2);
    /*
    6.2 * 2 * 10 = 124
    */
    cout << dp << endl;

    NumericArray<Point> arr4;
    cout << arr4 << endl;
}

/*
What assumptions do you make about the type used as template argument?
They must support the relevant operators, so they must be numeric in nature.??

Can you create a numeric Array with Point Objects?
Yes, you can create such an Array. Everything will work as long as the relevant
operators such as `+` and `*` are implemented in the Point class, in which case, 
they are.
*/