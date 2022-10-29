#include <stdio.h>

#define ASCII_BACKSPACE 8
#define ASCII_HORIZONTAL_TAB 9
#define ASCII_ESCAPE 27
#define ASCII_BACKSLASH 92

/*
    Write a program to copy its input to its output, replacing each tab by \t,
    each backspace by \b, and each backslash by \\. This makes tabs and backspaces
    visible
*/

int main()
{
    short ch;
    while ((ch = getchar()) != EOF) {
        if (ch == ASCII_HORIZONTAL_TAB) {
            printf("\\t");
            continue;
        }
        else if (ch == ASCII_BACKSPACE) {
            printf("\\b");
            continue;
        }
        else if (ch == ASCII_BACKSLASH) {
            printf("\\");
            printf("\\");
            continue;
        }
        putchar(ch);
    }
}