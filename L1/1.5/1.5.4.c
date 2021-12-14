#include <stdio.h>

/* recursive function that gets number to be printed.
function should print the number digit by digit by using the putchar function. */
void printnumber(int a) {
    if (a < 0) {
        putchar('-');
        printnumber(-a);
    }
    else if (a / 10)
        printnumber(a / 10);
    if (a >= 0) 
        putchar(a % 10 + '0'); // adding the result to the ASCII value of 0 to get the correct ASCII representation of the number.
}

int main() {
    printf("Enter number: ");
    int a;
    scanf("%d", &a);
    printnumber(a);
    putchar('\n');
}