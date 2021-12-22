/* Author: YiJia Chen */

/* Calculate the length of a string */
#include <stdio.h>
#define MAXLINE 30
// String length declaration
int Length(char str[]);

int main()
{
    char string[MAXLINE+1]; // Line of max 30 chars + \0
    int c;
    int i=0;

    // Print intro text
    printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);

    // Get the characters
    while ((c=getchar()) !=EOF && i<MAXLINE)
    {
        // Append entered characters to string
        string[i++]=(char)c;
    }
    string[i]='\0'; // String must be closed with \0
    printf("String length is %d\n", Length(string));
    return 0;
}
/* Implement the Length() function here */

int Length(char str[])
{
    int idx = 0;
    while (str[idx] != '\0')
        idx++;
    return idx;
}