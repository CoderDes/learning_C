#include <stdio.h>

#define ASCII_SPACE 32

int main()
{
    int ch;
    int prevCh;
    while ((ch = getchar()) != EOF) {
        if (prevCh == ASCII_SPACE && ch == ASCII_SPACE) {
            continue;
        }
        putchar(ch);
        prevCh = ch;
    }
}