#include <stdio.h>

void rev(int x) {
  if (x < 10) {
    printf("%d", x);
    return;
  } else {
    printf("%d", x % 10);
    rev(x / 10);
  }
}

int main() {
  int a;
  scanf("%d", &a);
  rev(a);
}