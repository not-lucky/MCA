#include <stdio.h>

int hcf(int x, int y) {
  int shorter;
  shorter = (x < y) ? x : y;
  for (int i = shorter; i >= 1; i--) {
    if (x % i == 0 && y % i == 0) {
      return i;
    }
  }
  return 1;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d", hcf(a, b));
}