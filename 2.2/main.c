#include <stdio.h>

int main(void) {
  short lim = 1000;
  char s[lim];
  short currChar = '\0';
  for (short i = 0; i < lim-1 && (currChar = getchar()) != EOF && currChar != '\n'; ++i)  {
    s[i] = currChar;
  }

  printf("#1: %s\n", s);

  for (short j = 0; ; ++j) {
    if (j < lim - 1) {
        break;
    }
    else if ((currChar = getchar()) != EOF) {
        break;
    }
    else if (currChar != '\n') {
        break;
    }
    s[j] = currChar;
  }

  printf("#2: %s\n", s);
  return 0;
}