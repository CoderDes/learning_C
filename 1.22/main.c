#include <stdio.h>

#define EDGE_POSITION 5
#define NEW_LINE '\n'

int main(void)
{
    short currChar = 0, position = 0;

    while ((currChar = getchar()) != EOF) {
        if (position == EDGE_POSITION + 1) {
            putchar('-');
            putchar(NEW_LINE);
            position = 0;
        }
        putchar(currChar);
        if (currChar != NEW_LINE) {
            ++position;
        } else {
            position = 0;
        }
    }
}