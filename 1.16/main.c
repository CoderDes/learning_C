#include <stdio.h>

#define MAX_LINE 1000
int get_line(char line[], int max_line);
void copy(char to[], char from[]);


int main()
{
    char current_line[MAX_LINE];
    char longest_line[MAX_LINE];

    int current_len = 0;
    int max_len = 0;

    while ((current_len = get_line(current_line, MAX_LINE)) > 0) {
        if (current_len > max_len) {
            max_len = current_len;
            copy(longest_line, current_line);
        }
    }

    short i = 0;
    while (longest_line[i] != '\0') {
        putchar(longest_line[i]);
        ++i;
    }

    return 0;
}

int get_line(char s[], int lim)
{
    int ch, i;
    for (i = 0; i < lim - 1 && (ch = getchar()) != EOF && ch != '\n'; ++i) {
        s[i] = ch;
    }

    if (ch == '\n') {
        s[i] = ch;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}