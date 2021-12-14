/* Author: YiJia Chen */
#include <stdio.h>

// Calculate the surface of a triangle.
int main()
{
    int base;
    int height;

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter height: ");
    scanf("%d", &height);

    printf("Result = %f\n", base * height / 2.0);
}