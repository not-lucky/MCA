#include <stdio.h>

int dig(int x) {
  static int digit_count = 0;
  if (x == 0) {
    return digit_count;
  }
  digit_count++;
  return dig(x / 10);
}

int main() {
  int a;
  scanf("%d", &a);
  printf("%d", dig(a));
}