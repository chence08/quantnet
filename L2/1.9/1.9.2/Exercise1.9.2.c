#include <stdio.h>

int main()
{
    FILE *fp = fopen("output", "w");

    int line[1000];
    int c, i, lineLength = 0;
    printf("Input text, hit ENTER to write to output file.\n");
    while ((c = getchar()) != 1)
    {
        line[lineLength++] = c;
        if (c == '\n') // User hits ENTER
        {
            for (i = 0; i < lineLength; i++)
                putchar(line[i]); // Print line
            lineLength = 0;
        }
    }
    printf("CTRL + A is a correct ending.\n");
}