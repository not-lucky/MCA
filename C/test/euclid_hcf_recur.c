#include <stdio.h>

int hcf(int x, int y) {
  if (x % y != 0) {
    return hcf(y, x % y);
  }
  return y;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d", hcf(a, b));
}