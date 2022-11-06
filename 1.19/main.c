#include <stdio.h>

#define MAX_LEN 1000

void reverse(char line[], short len);

void reverse(char line[], short len) {
    short endLineInd = len - 1;
    short startLineInd = 0;
    short middleLineInd = len / 2;
    while (startLineInd != middleLineInd) {
        line[startLineInd] += line[endLineInd];
        line[endLineInd] = line[startLineInd] - line[endLineInd];
        line[startLineInd] -= line[endLineInd];
        
        ++startLineInd;
        --endLineInd;
    }
}

int main()
{
    char inputLine[MAX_LEN];
    short currChar;

    short len = 0;
    while ((currChar = getchar()) != '\n') {
        inputLine[len] = currChar;
        ++len;
    }

    inputLine[len] = '\0';
    reverse(inputLine, len);
    printf("AFTER REVERSE: %s\n", inputLine);
}