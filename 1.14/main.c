#include <stdio.h>

#define MAX_ASCII_CHAR 126

#define FRACTION '|'
#define CHAR_GAP 9

int main()
{
    short charArr[MAX_ASCII_CHAR];

    for (short i = 0; i < MAX_ASCII_CHAR; ++i) {
        charArr[i] = 0;
    }

    short ch;
    while((ch = getchar()) != EOF) {
        ++charArr[ch];
    }

    for (short i = 0; i < MAX_ASCII_CHAR; ++i) {
        printf("%d:%c", i, CHAR_GAP);
        for (short j = 0; j < charArr[i]; ++j) {
            putchar(FRACTION);
        }
        putchar('\n');
    }
}