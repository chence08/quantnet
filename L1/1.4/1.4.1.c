#include <stdio.h>
#define WORD 1 // is a word
#define NOTWORD 0 // not a word

/* Get number of characters, words, newlines from keyboard 
We define word as any sequence of characters that does not contain a blank, tab or newline.
USE A WHILE LOOP*/
int main() {
    printf("Please input text, press Ctrl + D when you are done.\n");
    int c, numChars, numWords, numLines, isWord;

    isWord = NOTWORD;
    numChars = numWords = numLines = 0;
    while ((c = getchar()) != EOF) {
        ++numChars;
        if (c == '\n')
            ++numLines;
        if (c == ' ' || c == '\n' || c == '\t')
            isWord = NOTWORD;
        else if (isWord == NOTWORD) {
            isWord = WORD;
            ++numWords;
        }
    }
    printf("num of characters = %d\nnum of words = %d\nnum of newlines = %d\n", numChars, numWords, numLines);
}