#include <stdio.h>

int main() {
  int n;
  printf("Enter length of string: ");
  scanf("%d", &n);
  char s[n];
  printf("Enter the string: ");
  scanf("%s", s);

  int i = 0;
  int j = n - 1;
  while (i <= j) {
    if (s[i] != s[j]) {
      printf("Not a palindrome\n");
      return 0;
    }
    i++;
    j--;
  }
  printf("Palindrome\n");
}
