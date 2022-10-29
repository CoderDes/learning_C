#include <stdio.h>

#define IN 1
#define OUT 0

#define SPACE ' '
#define NEW_LINE '\n'
#define TAB '\t'

int main()
{
    int state = OUT;
    int ch;
    while((ch = getchar()) != EOF) {
        int isWord = ch != SPACE && ch != NEW_LINE && ch != TAB;
        if (isWord) {
            putchar(ch);
            state = IN;
        }
        else if (state == IN) {
            putchar(NEW_LINE);
            state = OUT;
        }
    }
}