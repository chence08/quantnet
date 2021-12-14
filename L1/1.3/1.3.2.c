#include <stdio.h>

// Calculate the surface of a triangle.
int main() {
    int base;
    int height;

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter height: ");
    scanf("%d", &height);

    float result = base * height / 2.0;
    printf("Result = %f", result);
}