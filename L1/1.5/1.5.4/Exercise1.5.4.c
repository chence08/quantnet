#include <stdio.h>

/* recursive function that gets number to be printed.
function should print the number digit by digit by using the putchar function. */
void printnumber1(int a)
{
    if (a < 0)
    {
        putchar('-');
        printnumber1(-a);
    }
    else if (a / 10)
        printnumber1(a / 10);
    if (a >= 0) 
        putchar(a % 10 + '0'); // adding the result to the ASCII value of 0 to get the correct ASCII representation of the number.
}

void printnumber2(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printnumber2(n / 10);
    putchar(n % 10 + '0');
}

int main()
{
    printf("Enter number: ");
    int a;
    scanf("%d", &a);
    printnumber2(a);
    putchar('\n');
}