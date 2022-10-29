#include <stdio.h>

#define ASCII_SPACE 32

int main()
{
    short count = 0;
    short ch;
    while ((ch = getchar()) != EOF) {
        if (ch == ASCII_SPACE) {
            ++count;
        }
    }
    
    printf("Total spaces count: %d\n", count);
}