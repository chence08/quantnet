/* Author: YiJia Chen */
#include <stdio.h>

void Swap(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

int main()
{
    int i = 123, j = 456;
    printf("Initial values\ni = %d, j = %d\n\n", i, j);
    Swap(&i, &j);
    printf("Final values\ni = %d, j = %d\n", i, j);
}