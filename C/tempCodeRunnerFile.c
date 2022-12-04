#include <stdio.h>

int sum_d(int x) {
  static int sum = 0;
  if (x == 0) {
    return sum;
  }
  sum += x % 10;
  return sum_d(x / 10);
}

int main() {
  int a;
  scanf("%d", &a);
  printf("%d", sum_d(a));
}