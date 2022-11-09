/*
BETTER APPROACH

// Find total digits in n
digits = (int) log10(n);

// Store reverse of n in num
while(n != 0)
{
    num = (num * 10) + (n % 10);
    n /= 10;
}

// Find total trailing zeros
digits =  digits - ((int) log10(num));
*/

#include <stdio.h>

void print_num(int x) {
  switch (x) {
    {
      case 0:
        printf("Zero ");
        break;
      case 1:
        printf("One ");
        break;
      case 2:
        printf("Two ");
        break;
      case 3:
        printf("Three ");
        break;
      case 4:
        printf("Four ");
        break;
      case 5:
        printf("Five ");
        break;
      case 6:
        printf("Six ");
        break;
      case 7:
        printf("Seven ");
        break;
      case 8:
        printf("Eight ");
        break;
      case 9:
        printf("Nine ");
        break;
    }
  }
}

int main() {
  int num, rev_num = 0, end_zeroes = 0, actual_last_zero = 1;
  printf("Enter a positive number: ");
  scanf("%d", &num);
  while (num != 0) {
    if (actual_last_zero) {
      if (num % 10 == 0)
        end_zeroes++;
      else
        actual_last_zero = 0;
    }
    rev_num = rev_num * 10 + num % 10;
    num /= 10;
  }

  printf("Entered number in words is:\n");

  while (rev_num != 0) {
    print_num(rev_num % 10);
    rev_num /= 10;
  }

  for (int i = 1; i <= end_zeroes; i++) {
    printf("Zero ");
  }
}