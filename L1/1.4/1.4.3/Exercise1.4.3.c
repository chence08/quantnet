/* Author: YiJia Chen */
#include <stdio.h>
#define WORD 1 // is a word
#define NOTWORD 0 // not a word

/* Get number of characters, words, newlines from keyboard.
We define word as any sequence of characters that does not contain a blank, tab or newline.
USING SWITCH-CASE STATEMENTS INSTEAD OF IF BLOCKS. */
int main()
{
    printf("Please input text, press Ctrl + D when you are done.\n");
    int c, numChars, numWords, numLines, isWord;

    isWord = NOTWORD;
    numChars = numWords = numLines = 0;
    while ((c = getchar()) != EOF)
    {
        ++numChars;
        switch (c)
        {
            case ' ': case '\t':
                isWord = NOTWORD;
            case '\n':
                isWord = NOTWORD;
                ++numLines;
                break;
        }
        switch (isWord)
        {
            case NOTWORD:
                isWord = WORD;
                ++numWords;
                break;
        }
    }
    printf("\nnum of characters = %d\nnum of words = %d\nnum of newlines = %d\n", numChars, numWords, numLines);
}