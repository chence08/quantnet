/* Author: YiJia Chen
For Exercises 1.6.1 and 1.6.2 */

#include <stdio.h> // <> for standard libraries.
#include "Defs.h" // Quotes for file that is at location of source program.

/* Demonstration of C Preprocessor.
1. File Inclusion
2. Macro Substitution in Defs.h
3. Conditional Inclusion to avoid multiple inclusion of header file. */
int main()
{
    printf("Exercise 1:\n");
    int a = 1, b = 2, c = 3;
    PRINT1(a);
    PRINT2(a, b);

    printf("\nExercise 2:\n");
    PRINT1(MAX2(a, b));
    PRINT1(MAX3(a, b, c));
}