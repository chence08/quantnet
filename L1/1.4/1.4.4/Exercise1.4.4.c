/* Author: YiJia Chen */
#include <stdio.h>

/* Fahrenheit to Celsius within range 0 to 300.
Using while loop. */
int main()
{
    printf("%10s %10s\n", "Fahrenheit", "Celsius");
    int start = 0, end = 300, step = 20;
    
    int fahrenheit = start;
    while (fahrenheit <= end)
    {
        printf("%10d %10.1f\n", fahrenheit, (5.0/9) * (fahrenheit - 32));
        fahrenheit += 20;
    }
}