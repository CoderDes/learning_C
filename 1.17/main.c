#include <stdio.h>

#define MAX_STRING_SIZE 100
#define MIN_CHAR_COUNT 80

int main()
{
    short input_char;
    short char_counter = 0;
    char str[MAX_STRING_SIZE];
    while ((input_char = getchar()) != EOF) {
        if (input_char == '\n') {
            if (char_counter >= MIN_CHAR_COUNT) {
                printf("char counter: %d\n", char_counter);
                printf("string that 80 chars in length or longer: %s\n", str);
                char_counter = 0;
                str[0] = '\0';
            }
            continue;
        }
        if (char_counter >= MAX_STRING_SIZE) {
            continue;
        }
        str[char_counter] = input_char;
        ++char_counter;
    }

    return 0;
}