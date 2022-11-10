#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void)
{
    char s1[] = "abcdefg";
    char s2[] = "abf";

    printf("BEFORE %s\n", s1);
    squeeze(s1, s2);
    printf("AFTER %s\n", s1);
}

void squeeze(char s1[], char s2[])
{
    for (short i = 0; s1[i] != '\0'; ++i) {
        for (short j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] != s2[j]) {
                continue;
            }
            for (short z = i; s1[z] != '\0'; ++z) {
                s1[z] = s1[z + 1];
            }
        }
    }
}
