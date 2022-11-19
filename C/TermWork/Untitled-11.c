#include <stdio.h>

void main() {
  char arr[100];
  int n;
  gets(arr);
  for (int i = 0; arr[i] != '\0'; i++) n++;
  int palindrome = 1;
  for (int i = 0; i < n / 2; i++) {
    if (arr[i] != arr[n - 1 - i]) {
      printf("%c  %c  %i", arr[i], arr[n - 1 - i], i);
      printf("Not a Palindrome!!!");
      palindrome = 0;
      break;
    }
  }
  if (palindrome) printf("PALINDROME!!");
  puts(arr);
  printf("%d", n);
}