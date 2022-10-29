#include <stdio.h>

int main()
{
    int ch, newLines;
    newLines = 0;
    while ((ch = getchar()) != EOF) {
        if (ch != '\n') {
            continue;
        }
        ++newLines;
    }

    printf("%d\n", newLines);
}