#include <stdio.h>

unsigned short isValidHex(char hex[]);
unsigned short isDigit(char ch);
unsigned short isAlpha(char ch);
unsigned short isUpper(char ch);
unsigned short getLen(char hex[]);
char toLower(char ch);
int toPower(short num, short power);
int htoi(char hex[]);

unsigned short isUpper(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}

char toLower(char ch)
{
    return ch - 'A' + 'a';
}

int toPower(short num, short power)
{
    if (power == 0) {
        return 1;
    }

    int result = 1;
    unsigned short i = 0;
    while (i < power) {
        result *= num;
        ++i;
    }
    return result;
}

unsigned short isDigit(char ch)
{
    return ch - '0' <= 9;
}

unsigned short isAlpha(char ch)
{
    return (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F');
}

unsigned short isValidHex(char hex[])
{
    short isValid = hex[0] == '0' && (hex[1] == 'X' || hex[1] == 'x');
    for (short i = 2; hex[i] != '\0'; ++i) {
        if (!isDigit(hex[i]) && !isAlpha(hex[i])) {
            isValid = 0;
            break;
        }
    }
    return isValid;
}

unsigned short getLen(char hex[]) {
    short len = 0;
    while (hex[len] != '\0') {
        ++len;
    }
    return len;
}

int htoi(char hex[])
{
    if (!isValidHex(hex)) {
        printf("HEX NOT VALID\n");
        return -1;
    }

    int result = 0;
    unsigned short i = getLen(hex) - 1;
    unsigned short pow = 0;
    const unsigned short base = 16;
    unsigned short poweredBase = 1;
    char currChar = hex[i];
    while (hex[i] != 'X' && hex[i] != 'x') {
        if (isDigit(hex[i])) {
            result += (hex[i] - '0') * toPower(base, pow);
        }
        else if (isAlpha(hex[i])) {
            currChar = hex[i];
            if (isUpper(currChar)) {
                currChar = toLower(hex[i]);
            }
            result += ((10 + (currChar - 'a')) * toPower(base, pow));
        }
        ++pow;
        --i;
    }
    return result;
}

int main(void)
{
    int res = htoi("0x5b");
    printf("Result decimal: %d\n", res);
    return 0;
}