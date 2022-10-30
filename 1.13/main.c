#include <stdio.h>

#define WORDS_COUNT 10
#define LINE_FRACTION '|'

int main()
{
    int words[WORDS_COUNT];
    for (int i = 0; i < WORDS_COUNT; ++i) {
        words[i] = 0;
    }

    int len = 0;
    int ch;
    int i = 0;
    while (i < WORDS_COUNT) {
        ch = getchar();
        if (ch != ' ' && ch != '\n' && ch != '\t') {
            ++len;
        }
        else {
            words[i] = len;
            len = 0;
            ++i;
        }
    }

    printf("Results:\n");
    for (int i = 0; i < WORDS_COUNT; ++i) {
        if (words[i] == 0) {
            continue;
        }
        for (int len = 0; len < words[i]; ++len) {
            putchar(LINE_FRACTION);
        }
        putchar('\n');
    }
}