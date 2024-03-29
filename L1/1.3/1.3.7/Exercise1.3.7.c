/* Author: YiJia Chen 
Using binary shifts to multiply an integer by powers of 2. */
#include <stdio.h>

int main()
{
    int k, n;
    printf("We want to compute k * (2^n).\nEnter k: ");
    scanf("%d", &k);
    printf("Enter n: ");
    scanf("%d", &n);
    printf("%d * (2^%d) = %d", k, n, k << n);
}