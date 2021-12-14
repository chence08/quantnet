/* Author: YiJia Chen */
#include <stdio.h>

/* recursive factorial function */
long factorial(int a)
{
    if (a == 0)
        return 1;
    return a * factorial(a - 1);
}

int main() {
    printf("Enter a number: ");
    int a;
    scanf("%d", &a);
    if (a >= 0)
        printf("%ld\n", factorial(a));
    else
        printf("Number must be non-negative!\n");
}