#include <stdio.h>

short parenthesesBalanced(char text[]);
short quotesValid(char text[]);
void fillText(char text[]);

short programLen = 1000;

int main(void)
{
    extern short programLen;

    char programText[programLen];
    fillText(programText);

    if (!parenthesesBalanced(programText)) {
        printf("SYNTAX ERROR: unbalanced parentheses\n");
        return 1;
    }
    if (!quotesValid(programText)) {
        printf("SYNTAX ERROR: quotes are not valid\n");
        return 1;
    }

    printf("Completed\n");
    return 0;
}

void fillText(char text[]) 
{
    short currChar = 0, i = 0;
    while ((currChar = getchar()) != EOF) {
        text[i] = currChar;
        ++i;
    }
    text[i] = '\0';
}

short parenthesesBalanced(char text[]) 
{
    extern short programLen;

    short braces = 0, brakets = 0, parens = 0, tag = 0;
    
    for (short i = 0; text[i] != '\0'; ++i) {
        if (text[i] == '{') {
            ++braces;
        }
        else if (text[i]  == '}') {
            --braces;
        }
        else if (text[i]  == '[') {
            ++brakets;
        }
        else if (text[i] == ']') {
            --brakets;
        }
        else if (text[i] == '(') {
            ++parens;
        }
        else if (text[i] == ')') {
            --parens;
        }
        else if (text[i] == '<') {
            ++tag;
        }
        else if (text[i] == '>') {
            --tag;
        }
    }

    return braces == 0 && brakets == 0 && parens == 0 && tag == 0;
}

short quotesValid(char text[]) 
{
    extern short programLen;

    short doubleQuotes = 0, singleQuotes = 0;
    short doubleIsOpen = 0, singleIsOpen = 0;

    for (short i = 0; text[i] != '\0'; ++i) {
        doubleIsOpen = doubleQuotes > 0 && doubleQuotes % 2 != 0;
        if (!doubleIsOpen && text[i] == '"') {
            ++doubleQuotes;
        }
        else if (doubleIsOpen && text[i] == '"') {
            --doubleQuotes;
        }

        singleIsOpen = singleQuotes > 0 && singleQuotes % 2 != 0;
        if (!singleIsOpen && text[i] == '\'') {
            ++singleQuotes;
        } else if (singleIsOpen && text[i] == '\'') {
            --singleQuotes;
        }
    }

    return doubleQuotes == 0 && singleQuotes == 0;
}