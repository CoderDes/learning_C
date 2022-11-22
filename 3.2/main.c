#include <stdio.h>

#define MAX_LEN 100

void escape(char source[], char target[]);

int main(void)
{
    char source[MAX_LEN] = "Hello,\n\tWorld!\n";
    char target[MAX_LEN] = "";

    escape(source, target);

	printf("SOURCE BEFORE ESCAPE: %s\n", source);
    printf("TARGET AFTER ESCAPE: %s\n", target);

    return 0;
}

void escape(char source[], char target[]) {
    unsigned int i = 0;
	unsigned int j = 0;
    while (source[i] != '\0') {
        switch (source[i]) {
            case '\n':
                target[j] = '\\';
				++j;
                target[j] = 'n';
                break;
            case '\t':
                target[j] = '\\';
				++j;
                target[j] = 't';
                break;
            default:
                target[j] = source[i];
                break;
        }
		++i;
		++j;
    }
    target[j] = '\0';
}
