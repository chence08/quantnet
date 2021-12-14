#include <stdio.h>

int main() {
    int prefix = 0;
    int postfix = 0;
    int x = --prefix;
    int y = postfix--;
    printf("Given i = 0:\n");
    printf("PREFIX\n");
    printf("After executing x = --i, x = %d and i = %d.\n", x, prefix);
    printf("POSTIFIX\n");
    printf("After executing y = i--, y = %d and i = %d.", y, postfix);
}