#include <stdio.h>

int reverse_number(int num, int rev) {
  int to_mul = 1, temp = num;
  while (temp > 9) {
    to_mul *= 10;
    temp /= 10;
  }
  if (num == 0) return rev;
  rev = rev + ((num % 10) * to_mul);
  return reverse_number(num / 10, rev);
}

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  int reversed = reverse_number(num, 0);
  printf("Reversed number: %d\n", reversed);

  return 0;
}
