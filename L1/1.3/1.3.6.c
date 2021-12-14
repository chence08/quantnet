#include <stdio.h>

int main() {
    int a;
    unsigned b;
    printf("Enter any integer between -2147483648 and 2147483647: ");
    scanf("%d", &a);
    b = (unsigned) a;
    printf("signed representation = %d\nunsigned representation = %u\n", a, b);

    printf("After right shifting them by two places,\n");
    printf("%d -> %d (arithmetic shift for signed)\n", a, a >> 1);
    printf("%u -> %u (logical shift for unsigned)\n", b, b >> 1);
}