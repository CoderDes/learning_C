#include <stdio.h>

#define MAX_LEN 1000

short isValidCombination(char prev, char curr);

// comment in C
    // 1) all between /* and */
    // 2) double slashes RIGHT AFTER \n

short isValidCombination(char prev, char curr) {
    short isOneLineCombination = prev == '/' && prev == curr;
    short isMultilineCombination = (prev == '/' && curr == '*') || (prev == '*' && curr == '/');
    return isOneLineCombination || isMultilineCombination;
}


int main(void)
{
    char programText[MAX_LEN];

    char prevChar = '\0';
    short currChar = 0;
    short multilineCommentStarts = 0, multilineCommentEnds = 0, isMultilineComment = 0;
    short onelineCommentStarts = 0, onelineCommentEnds = 0, isOnelineComment = 0;
    int len = 0;

    
    while ((currChar = getchar()) != EOF) {
        if (isValidCombination(prevChar, currChar)) {
            multilineCommentStarts = prevChar == '/' && currChar == '*';
            multilineCommentEnds = prevChar == '*' && currChar == '/';
        }
        if (multilineCommentStarts) {
            isMultilineComment = 1;
        }
        else if (multilineCommentEnds) {
            multilineCommentStarts = 0;
            multilineCommentEnds = 0;
            isMultilineComment = 0;
        }
        
        if (isMultilineComment) {
            prevChar = currChar;
            continue;
        }

        if (isValidCombination(prevChar, currChar) || currChar == '\n') {
            onelineCommentEnds = onelineCommentStarts && currChar == '\n';
            onelineCommentStarts = prevChar == '/' && currChar == '/';
        }

        if (onelineCommentStarts) {
            isOnelineComment = 1;
        }
        else if (isOnelineComment && onelineCommentEnds) {
            onelineCommentEnds = 0;
            isOnelineComment = 0;
        }

        if (isOnelineComment) {
            prevChar = currChar;
            continue;
        }

        if (prevChar != '/' && currChar != '/') {
            programText[len] = currChar;
            ++len;
        }
        
        prevChar = currChar;
    }

    programText[len] = '\0';


    printf("===FORMATTED PROGRAM ===\n");
    printf("%s", programText);

    return 0;
}