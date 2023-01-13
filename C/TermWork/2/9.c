#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[100], sub[100], new[100] = "", replace[100];
  printf("\n\nEnter a string: ");
  gets(str);

  printf("\nEnter a substring to be replaced: ");
  gets(sub);

  printf("\nEnter the replacement string: ");
  gets(replace);

  int len = strlen(sub);
  for (int i = 0; i < strlen(str); i++) {
    if (strncmp(&str[i], sub, len) == 0) {
      strcat(new, replace);
      i += len - 1;
    } else
      strncat(new, &str[i], 1);
  }
  puts(new);
}