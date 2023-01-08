#include <stdio.h>

int main() {
  char* s;
  printf("Enter a string: ");
  scanf("%s", s);

  int i = 0;
  int j = strlen(s) - 1;
  while (i < j) {
    if (s[i] != s[j]) {
      printf("Not a palindrome\n");
      return 0;
    }
    i++;
    j--;
  }

  printf("Palindrome\n");

  return 0;
}
