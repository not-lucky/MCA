#include <stdio.h>

int reverse(int);

int main() {
  int num = 12120, rev;

  rev = reverse(num);

  printf("The reverse of %d is %d\n", num, rev);

  return 0;
}

int reverse(int num) {
  static int rem, sum = 0;

  if (num) {
    rem = num % 10;
    sum = sum * 10 + rem;
    reverse(num / 10);
  } else {
    return 0;
  }
  return sum;
}