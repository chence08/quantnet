#include <stdio.h>

int minus(int a, int b) {
    return a - b;
}

int main() {
    int a, b;
    printf("Compute a - b.\nEnter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    printf("%d\n", minus(a, b));
}