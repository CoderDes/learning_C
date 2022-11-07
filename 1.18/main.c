#include <stdio.h>

#define MAX_LEN 1000

short get_line(char line[], short lim);

short get_line(char line[], short lim) {
    short currChar, prevChar;
    short isDoubleSpace = 0, isTab = 0, len = 0;
    
    for (;len < lim - 1 && (currChar = getchar() ) != EOF && currChar != '\n'; ++len) {
        isDoubleSpace = prevChar == currChar && currChar == ' ';
        isTab = currChar == '\t';
        if (isDoubleSpace || isTab) {
            --len;
            continue;
        }
        line[len] = currChar;
        prevChar = currChar;
    }

    if (currChar == '\n') {
        line[len] = currChar;
        ++len;
    }

    line[len] = '\0';
    printf("LEN: %d\n", len);

    return len;
}

int main()
{
    char currentLine[MAX_LEN];

    char currentLen = 0;
    while((currentLen = get_line(currentLine, MAX_LEN)) > 0) {
        printf("%s", currentLine);
    }
}

