#include <stdio.h>

int main() {
  char x;
  printf("Enter a single character:\n");
  scanf("%c", &x);
  int i = x;
  if ((65 <= i && i <= 90) || (97 <= i && i <= 122))
    printf("The entered character (%c) is an alphabet.", x);
  else
    printf("The entered character (%c) is NOT an alphabet.", x);
}