/* Author: YiJia Chen */
#include <stdio.h>

/* Celsius to Fahrenheit within range 0 to 300.
Using for loop. */
int main()
{
    printf("%10s %10s\n", "Celsius", "Fahrenheit");
    int celsius;
    for (celsius = 0; celsius <= 19; celsius++)
        printf("%10d %10.1f\n", celsius, (9.0/5) * celsius + 32);
}