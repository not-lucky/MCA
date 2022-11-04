#include <stdio.h>

int main() {
  int x, r;
  printf("Enter a positive decimal integer:\n");
  scanf("%d", &x);
  int num = x;
  printf("The entered integer in binary form is:\n\t\t\t\t\t\t\t\t\t\t\t");
  while (x != 0) {
    printf("\b\b%d", x % 2);
    x /= 2;
  }
  printf("\n");
  printf("The entered integer in octal form is:\n");
  printf("%o\n", num);

  printf("The entered integer in hexadecimal form is:\n");
  printf("%x", num);
}