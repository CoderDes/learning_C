#include <stdio.h>

#define DIGIT_COUNT 10

int main()
{
    int c, i, nwhite, nother;
    int ndigit[DIGIT_COUNT];
    nwhite = nother = 0;
    for (i = 0; i < DIGIT_COUNT; ++i) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++ndigit[c - '0'];
        }
        else if (c == ' ' || c == '\n' || c == '\t') {
            ++nwhite;
        }
        else {
            ++nother;
        }
    }
    printf("numbers = ");
    for (i = 0; i < DIGIT_COUNT; ++i) {
        printf(" %d ", ndigit[i]);
    }
    printf(", delimeters = %d, others = %d\n", nwhite, nother);
}