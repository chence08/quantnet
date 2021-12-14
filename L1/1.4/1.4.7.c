#include <stdio.h>

/* Count how many times each of the numbers 0-4 have been typed.
Use switch-case.
Use default to count the number of other characters. */
int main() {
    printf("Enter input. Press Ctrl + D after you are done.\n");
    int c, zero, one, two, three, four, others;
    zero = one = two = three = four = others;
    
    while ((c = getchar()) != EOF) {
        switch (c) {
        case '0': ++zero; break;
        case '1': ++one; break;
        case '2': ++two; break;
        case '3': ++three; break;
        case '4': ++four; break;
        default: ++others; break;
        }
    }
    printf("\nzeroes = %d\nones = %d\ntwos = %d\n", zero, one, two);
    switch (three)
    {
    case 0:
        printf("Number three appears zero times.");
        break;
    case 1:
        printf("Number three appears one time.");
        break;
    case 2:
        printf("Number three appears two times.");
        break;
    default:
        printf("The number three appears more than two times.");
        break;
    }
    printf("\nfours = %d\nothers = %d\n", four, others);
}