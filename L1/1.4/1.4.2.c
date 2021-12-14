#include <stdio.h>
#define WORD 1 // is a word
#define NOTWORD 0 // not a word

/* Get number of characters, words, newlines from keyboard.
We define word as any sequence of characters that does not contain a blank, tab or newline.
USING DO-WHILE INSTEAD OF WHILE. */
int main() {
    printf("Please input text, press Ctrl + D when you are done.\n");
    int c, numChars, numWords, numLines, isWord;

    isWord = NOTWORD;
    numChars = numWords = -1;
    numLines = 0;
    do {
        c = getchar();
        ++numChars;
        if (c == '\n')
            ++numLines;
        if (c == ' ' || c == '\n' || c == '\t')
            isWord = NOTWORD;
        else if (isWord == NOTWORD) {
            isWord = WORD;
            ++numWords;
        }
    } while (c != EOF);
    printf("\nnum of characters = %d\nnum of words = %d\nnum of newlines = %d\n", numChars, numWords, numLines);
}