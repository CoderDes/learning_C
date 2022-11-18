#include <stdio.h>

#define CAPITAL_A 65
#define CAPITAL_Z 90
#define SMALL_A 97

int main(void)
{
    char inputChar = getchar();
    char resultChar = inputChar >= CAPITAL_A && inputChar <= CAPITAL_Z ? SMALL_A + (inputChar - CAPITAL_A) : inputChar;
    printf("input char: %c; result char: %c\n", inputChar, resultChar);
}