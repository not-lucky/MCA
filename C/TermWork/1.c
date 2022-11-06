#include <stdio.h>

int main() {
  char x;
  printf("Enter a single character:\n");
  scanf("%c", &x);

  if ((65 <= x && x <= 90) || (97 <= x && x <= 122))
    printf("The entered character (%c) is an alphabet.", x);
  else
    printf("The entered character (%c) is NOT an alphabet.", x);
}
