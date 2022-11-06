#include <stdio.h>

int main() {
  int x, r;
  printf("Enter a positive decimal integer:\n");
  scanf("%d", &x);
  int original_num = x;
  printf("The entered integer in binary form is:\n\t\t\t\t\t\t\t\t\t\t\t");
  while (x != 0) {
    printf("\b\b%d", x % 2);
    x /= 2;
  }
  printf("\n");
  x = original_num;
  printf("The entered integer in octal form is:\n\t\t\t\t\t\t\t\t\t\t\t");
  while (x != 0) {
    printf("\b\b%d", x % 8);
    x /= 8;
  }
  printf("\n");
  x = original_num;
  int to_print;
  printf("The entered integer in hexadecimal form is:\n\t\t\t\t\t\t\t\t\t\t\t");
  while (x != 0) {
    to_print = x % 16;
    if (to_print > 9) printf("\b\b%c", 87 + to_print);
    else printf("\b\b%d", to_print);
    x /= 16;
  }
}