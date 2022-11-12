#include <stdio.h>

int any(char s1[], char s2[]);

int main(void)
{
    char s1[] = "lolfgdsgdfgkfdsd";
    char s2[] = "kek";
    int res = any(s1, s2);
    printf("Result: %d\n", res);
    return 0;
}

int any(char s1[], char s2[])
{
    unsigned int i = 0;
    unsigned int j = 0;

    while (s1[i] != '\0') {
        while (s2[j] != '\0') {
            if (s1[i] == s2[j]) {
                return i;
            }
            ++j;
        }
        j = 0;
        ++i;
    }

    return -1;
}