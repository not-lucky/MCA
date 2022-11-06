#include <stdio.h>

void base_convertor(int num, int base) {
  int to_print;
  while (num != 0) {
    to_print = num % base;
    if (to_print > 9)
      printf("\b\b%c", 87 + to_print);
    else
      printf("\b\b%d", to_print);
    num /= base;
  }
  printf("\n");
}

int main() {
  int x, r;
  printf("Enter a positive decimal integer:\n");
  scanf("%d", &x);

  printf("The entered integer in binary form is:\n\t\t\t\t\t\t\t\t\t\t\t");
  base_convertor(x, 2);

  printf("The entered integer in octal form is:\n\t\t\t\t\t\t\t\t\t\t\t");
  base_convertor(x, 8);

  printf("The entered integer in hexadecimal form is:\n\t\t\t\t\t\t\t\t\t\t\t");
  base_convertor(x, 16);
}