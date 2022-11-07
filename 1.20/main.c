#include <stdio.h>

#define MAX_LEN 1000

void get_text(char text[], short maxLen);
void detab(char text[], short maxLen);

void get_text(char text[], short maxLen)
{
    short i = 0;
    short currChar = '\0';
    for (; (currChar = getchar()) != EOF && i < maxLen; ++i) {
        text[i] = currChar;
    }
    text[i] = '\0';
}

void detab(char text[], short maxLen)
{
    for (short i = 0; i < maxLen; ++i) {
        if (text[i] == '\t') {
            text[i] = ' ';
        }
    }
}

int main(void)
{
    char text[MAX_LEN];
    get_text(text, MAX_LEN);
    printf("ORIGINAL TEXT: %s\n", text);
    detab(text, MAX_LEN);
    printf("DETABED TEXT: %s\n", text);
}