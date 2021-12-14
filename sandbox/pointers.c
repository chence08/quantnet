#include <stdio.h>

int main() {
    int x = 1, y = 2, z[10];
    printf("INIT: The memory addresses are:\nx = %p, y = %p, z = %p, z[0] = %p\n\n",
    (void *)&x, (void *)&y, (void *)&z, (void *)&z[0]);
    
    int *ip; // ip is a pointer to int
    printf("1: x = %d, y = %d, ip = %p\n", x, y, ip);

    ip = &x; // ip now points to x
    printf("2: x = %d, y = %d, ip = %p\n", x, y, ip);

    y = *ip; // y is now 1
    printf("3: x = %d, y = %d, ip = %p\n", x, y, ip);

    *ip = 0; // x is now 0
    printf("4: x = %d, y = %d, ip = %p\n", x, y, ip);

    ip = &z[0]; // ip now points to z[0]
    printf("5: x = %d, y = %d, ip = %p", x, y, ip);
}

// int main() {
//     int ip; // ip is 1
//     printf("%d", ip);
// }