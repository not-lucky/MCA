#include <stdio.h>
int main() {
  int n = 7;
  char arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%c", &arr[i]);
  }
  int palindrome = 1;

  for (int i = 0; i < n; i++) {
    if (arr[i] != arr[n - 1 - i]) {
      printf("Not a Palindrome!!!");
      palindrome = 0;
      break;
    }
  }

  if (palindrome) printf("Palindrome!!!");
}